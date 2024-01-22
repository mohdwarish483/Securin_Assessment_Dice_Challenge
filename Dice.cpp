#include <iostream>
#include <vector>

using namespace std;

// Count occurrences of each sum (2-12)

int sumCount[13] = {0};

// Calculate the total number of combinations
int calculateTotalCombinations(int dieASize, int dieBSize)
{
    return dieASize * dieBSize;
}
// Possible combinations of dice A
void dieAPossibleCombinations(int number, vector<int> &temp, vector<vector<int>> &dieA)
{
    if (temp.size() == 6)
    {
        dieA.push_back(temp);
        return;
    }

    for (int i = number; i <= 6; ++i)
    {
        temp.push_back(i);
        dieAPossibleCombinations(i, temp, dieA);
        temp.pop_back();
    }
}

// Possible combinations of dice B
void dieBPossibleCombinations(int number, vector<int> &temp, vector<vector<int>> &dieB)
{
    if (temp.size() == 6)
    {
        dieB.push_back(temp);
        return;
    }

    for (int i = number; i <= 8; ++i)
    {
        temp.push_back(i);
        dieBPossibleCombinations(i, temp, dieB);
        temp.pop_back();
    }
}

// Calculate and display the distribution of combinations
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

void calculateProbabilityOfSums(const vector<int> &dieA, const vector<int> &dieB)
{
    int numSides = 6;

    for (size_t i = 0; i < dieA.size(); ++i)
    {
        for (size_t j = 0; j < dieB.size(); ++j)
        {
            int temp = dieA[i] + dieB[j];
            ++sumCount[temp];
        }
    }

    // Print the custom probabilities

    int totalCombinations = calculateTotalCombinations(dieA.size(), dieB.size());
    cout << "\n======================================================================\n";
    cout << "\n Probabilities of sums before transformation: \n";
    cout << "\n======================================================================\n";
    for (int k = 2; k <= 12; ++k)
    {
        double probability = static_cast<double>(sumCount[k]) / totalCombinations;
        cout << "P(Sum = " << k << ") = " << sumCount[k] << "/" << totalCombinations << " = " << probability << "\n";
    }
}

void undoom_dice(const vector<int> &dieA, const vector<int> &dieB)
{
    cout << "\n=====================================================================\n";
    cout << "Undooming dice and Reattaching the spots :\n";

    vector<vector<int>> custom_dieA;
    vector<vector<int>> custom_dieB;

    // combinations for dice A and B
    vector<int> temp;
    dieAPossibleCombinations(1, temp, custom_dieA);
    dieBPossibleCombinations(1, temp, custom_dieB);

    // Iterate through all combinations to find the matches with probability distribution before transformation
    for (const auto &i : custom_dieA)
    {
        for (const auto &j : custom_dieB)
        {
            int tempSum[13] = {0};

            // Calculate the sum of each combination
            for (size_t k = 0; k < i.size(); ++k)
            {
                for (size_t l = 0; l < j.size(); ++l)
                {
                    int sum = i[k] + j[l];
                    ++tempSum[sum];
                }
            }

            // Check if the probability distribution matches the probability distribution before transformation
            bool distributionMatches = true;
            for (int m = 0; m < 13; ++m)
            {
                if (tempSum[m] != sumCount[m])
                {
                    distributionMatches = false;
                    break;
                }
            }

            // If the distribution matches, print the transformed dice and probabilities
            if (distributionMatches)
            {
                cout << "\n======================================================================\n";
                cout << "Transformed DiceA : ";
                for (const auto &val : i)
                {
                    cout << val << " ";
                }
                cout << "\n======================================================================\n";

                cout << "Transformed DiceB : ";
                for (const auto &val : j)
                {
                    cout << val << " ";
                }
                cout << "\n======================================================================\n";
                cout << "Probability of sums After Transforming:";
                cout << "\n======================================================================\n";

                int totalCombinations = calculateTotalCombinations(dieA.size(), dieB.size());

                for (int n = 2; n <= 12; ++n)
                {
                    double probability = static_cast<double>(tempSum[n]) / (dieA.size() * dieB.size());
                    cout << "P(Sum = " << n << ") = " << tempSum[n] << "/" << totalCombinations << " = " << probability << endl;
                }
                return; // No need to continue searching
            }
        }
    }
}

int main()
{
    // Original dice values
    vector<int> Original_A = {1, 2, 3, 4, 5, 6};
    vector<int> Original_B = {1, 2, 3, 4, 5, 6};

    cout << "\n======================================================================\n";
    cout << "Dice A before transformation : ";
    for (const auto &value : Original_A)
    {
        cout << value << " ";
    }
    cout << "\n======================================================================\n";

    cout << "Dice B before transformation: ";
    for (const auto &value : Original_B)
    {
        cout << value << " ";
    }
    cout << "\n======================================================================\n";

    int combinations = calculateTotalCombinations(Original_A.size(), Original_B.size());
    cout << "Total Combinations : " << combinations << endl;
    cout << "\n======================================================================\n";

    calculateCombinationDistribution(Original_A, Original_B);

    // Probabilities before transformation

    calculateProbabilityOfSums(Original_A, Original_B);
    // Call the function to undo the transformation and print the results
    undoom_dice(Original_A, Original_B);

    return 0;
}
