#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the total number of combinations
int calculateTotalCombinations()
{
    return 6 * 6;
}

// Function to calculate and display the distribution of combinations
void calculateCombinationDistribution(const vector<int> &dieA, const vector<int> &dieB)
{
    int numSides = 6;
    vector<vector<int>> combinations(numSides, vector<int>(numSides));

    // possible combinations
    for (int i = 0; i < numSides; ++i)
    {
        for (int j = 0; j < numSides; ++j)
        {
            combinations[i][j] = dieA[i] + dieB[j];
        }
    }

    // distribution as a matrix
    cout << "Combination Distribution Matrix:" << endl;
    for (int i = 0; i < numSides; ++i)
    {
        for (int j = 0; j < numSides; ++j)
        {
            cout << combinations[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to calculate the probability of each possible sum
void calculateProbabilityOfSums(const vector<int> &dieA, const vector<int> &dieB)
{
    int numSides = 6;
    vector<int> sumCount(13, 0); // Count occurrences of each sum (2-12)

    // Count occurrences of each sum in the combinations
    for (int i = 0; i < numSides; ++i)
    {
        for (int j = 0; j < numSides; ++j)
        {
            int sum = dieA[i] + dieB[j];
            sumCount[sum - 2]++;
        }
    }

    // Calculate probability for each sum
    int totalCombinations = calculateTotalCombinations();
    cout << "Probability of Sums:" << endl;
    for (int i = 2; i <= 12; ++i)
    {
        cout << "P(Sum = " << i << ") = " << sumCount[i - 2] << "/" << totalCombinations << endl;
    }
}

// Helper function to identify sums with unique combinations
vector<int> findUniqueSums(const vector<int> &dieA, const vector<int> &dieB)
{
    vector<int> uniqueSums;
    vector<int> sumCount(13, 0); // Count occurrences of each sum (2-12)

    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            int sum = dieA[i] + dieB[j];
            sumCount[sum - 2]++;
            if (sumCount[sum - 2] == 1)
            {
                uniqueSums.push_back(sum);
            }
        }
    }
    return uniqueSums;
}

// Helper function to calculate the count of each possible sum for a pair of dice
vector<int> calculateSumCount(const vector<int> &dieA, const vector<int> &dieB)
{
    vector<int> sumCount(13, 0);
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            sumCount[dieA[i] + dieB[j] - 2]++;
        }
    }
    return sumCount;
}

// Function to "undoom" the dice
void undoom_dice(const vector<int> &dieA, const vector<int> &dieB, vector<int> &newDieA, vector<int> &newDieB)
{
    // Analyze Current Distribution
    vector<int> uniqueSums = findUniqueSums(dieA, dieB);
    cout << "Unique Sums: ";
    for (int sum : uniqueSums)
    {
        cout << sum << " ";
    }

    cout << endl;

    // Modify Die B
    newDieB = dieB;

    // Modify Die B to preserve unique sums while respecting other constraints
    for (int sum : uniqueSums)
    {
        int faceIndex = -1;
        for (int i = 0; i < 6; ++i)
        {
            if (dieA[i] + dieB[i] == sum)
            {
                faceIndex = i;
                break;
            }
        }
        if (faceIndex != -1)
        {
            while (newDieA[faceIndex] + newDieB[faceIndex] != sum)
            {
                // Increase Die B face value until the sum matches the unique sum
                newDieB[faceIndex]++;

                // If increasing Die B exceeds its allowable range, prioritize faces not involved in unique sums
                if (newDieB[faceIndex] > 6)
                {
                    for (int i = 0; i < 6; ++i)
                    {
                        if (i != faceIndex && newDieA[i] + newDieB[i] > sum)
                        {
                            newDieB[i]--;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << "New Die B: ";
    for (int value : newDieB)
    {
        cout << value << " ";
    }
    cout << endl;

    // Modify Die A within Constraints
    newDieA = dieA; // Start with original values
    int remainingSpots = 0;
    for (int i = 0; i < 6; ++i)
    {
        remainingSpots += dieA[i] - newDieB[i]; // Redistribute spots from Die B to A
    }
    cout << "Remaining Spots: " << remainingSpots << endl;

    // Distribute remaining spots among Die A faces, prioritizing unique sums and keeping all values under 4
    for (int sum : uniqueSums)
    {
        int faceIndex = -1;
        for (int i = 0; i < 6; ++i)
        {
            if (dieA[i] + dieB[i] == sum)
            {
                faceIndex = i;
                break;
            }
        }
        if (faceIndex != -1)
        {
            while (newDieA[faceIndex] + newDieB[faceIndex] != sum && newDieA[faceIndex] < 4)
            {
                newDieA[faceIndex]++;
                remainingSpots--;
            }
        }
    }

    // Distribute remaining spots evenly among Die A faces, ensuring no face exceeds 4
    for (int i = 0; i < 6; ++i)
    {
        while (remainingSpots > 0 && newDieA[i] < 4)
        {
            newDieA[i]++;
            remainingSpots--;
        }
    }

    // Validating Probability Distribution
    vector<int> originalSumCount = calculateSumCount(dieA, dieB);
    vector<int> modifiedSumCount = calculateSumCount(newDieA, newDieB);

    bool distributionPreserved = true;
    for (int i = 0; i < 13; ++i)
    {
        if (originalSumCount[i] != modifiedSumCount[i])
        {
            distributionPreserved = false;
            cout << "Warning: Probability distribution for sum " << i + 2 << " has changed." << endl;
        }
    }

    if (distributionPreserved)
    {
        cout << "Probability distribution successfully preserved!" << endl;
    }
    else
    {
        cout << "Probability distribution not fully preserved. Consider adjusting the algorithm." << endl;
    }
}

int main()
{
   
    vector<int> originalDieA = {1, 2, 3, 4, 5, 6};
    vector<int> originalDieB = {1, 2, 3, 4, 5, 6};

    vector<int> newDieA, newDieB;

    // Part-A calculations
    int combinations = calculateTotalCombinations();
    cout << "Total Combinations : " << combinations << endl;
    cout << "===============================================" << endl;
    calculateCombinationDistribution(originalDieA, originalDieB);
    cout << "===============================================" << endl;
    calculateProbabilityOfSums(originalDieA, originalDieB);
    cout << "===============================================" << endl;
    // Part-B: Undoom the dice
    undoom_dice(originalDieA, originalDieB, newDieA, newDieB);

    // modified dice values
    cout << "Modified Die A: ";
    for (int value : newDieA)
    {
        cout << value << " ";
    }
    cout << endl;
    cout << "===============================================" << endl;
    cout << "Modified Die B: ";
    for (int value : newDieB)
    {
        cout << value << " ";
    }
    cout << endl;
    cout << "===============================================" << endl;
    return 0;
}
