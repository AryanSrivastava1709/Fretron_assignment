#include <bits/stdc++.h>
using namespace std;

void distributeApples(vector<int> &appleWeight, vector<int> &shares, vector<vector<int>> &shareWeight)
{
    int totalWeight = accumulate(appleWeight.begin(), appleWeight.end(), 0);
    vector<int> targetedWeights(shares.size());
    vector<int> currentWeights(shares.size(), 0);

    for (int i = 0; i < shares.size(); i++)
    {
        targetedWeights[i] = totalWeight * shares[i] / 100;
    }

    sort(appleWeight.rbegin(), appleWeight.rend());

    for (auto weight : appleWeight)
    {
        int leastIndex = 0;
        double leastRatio = numeric_limits<double>::max();

        for (int i = 0; i < shares.size(); i++)
        {
            if (targetedWeights[i] > 0)
            {
                double ratio = static_cast<double>(currentWeights[i] + weight) / targetedWeights[i];
                if (ratio < leastRatio)
                {
                    leastRatio = ratio;
                    leastIndex = i;
                }
            }
        }
        shareWeight[leastIndex].push_back(weight);
        currentWeights[leastIndex] += weight;
    }
}

int main()
{
    vector<int> appleWeight;
    int weight;
    cout << "Enter apple weight in grams (-1 to stop): ";
    while (cin >> weight && weight != -1)
    {
        appleWeight.push_back(weight);
        cout << "Enter apple weight in grams (-1 to stop): ";
    }

    sort(appleWeight.rbegin(), appleWeight.rend());

    vector<int> shares = {50, 30, 20};
    vector<string> names = {"Ram", "Sham", "Rahim"};
    vector<vector<int>> shareWeight(shares.size());

    distributeApples(appleWeight, shares, shareWeight);

    cout << "Distribution Result:" << endl;
    for (size_t i = 0; i < names.size(); i++)
    {
        cout << names[i] << ": ";
        for (size_t j = 0; j < shareWeight[i].size(); j++)
        {
            if (j > 0)
                cout << ", ";
            cout << shareWeight[i][j];
        }
        cout << endl;
    }

    return 0;
}
