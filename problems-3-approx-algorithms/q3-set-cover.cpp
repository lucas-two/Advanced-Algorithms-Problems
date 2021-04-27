/* Q3. Set cover problem */
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    const int numOfSets = 6;
    vector<int> masterSet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<vector<int>> chosenFams;
    vector<vector<int>> family = {
        {1, 2, 3, 4, 5, 6}, //s0
        {5, 6, 8, 9},       //s1
        {10, 11},           //s2
        {1, 4, 7, 10},      //s3
        {2, 5, 8, 7, 11},   //s4
        {3, 6, 9, 12}};     //s5

    while (!masterSet.empty())
    {
        int largestFamily = 0;
        for (int i = 1; i < family.size(); i++)
        {
            if (family[i].size() > family[largestFamily].size())
            {
                largestFamily = i;
            }
        }
        // Remove the items in the set from the family (if they exist)
        for (int i = 0; i < family[largestFamily].size(); i++)
        {
            for (int j = 0; j < masterSet.size(); j++)
            {
                // If this value is in the master set
                if (family[largestFamily][i] == masterSet[j])
                {
                    // Remove it
                    masterSet.erase(masterSet.begin() + j);
                    break;
                }
            }
        }
        // Remove family set from search pool
        chosenFams.push_back(family[largestFamily]);
        family.erase(family.begin() + largestFamily);
    }

    // Print the sets that were used
    cout << "Sets used: " << endl;
    for (int i = 0; i < chosenFams.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < chosenFams[i].size(); j++)
        {
            cout << chosenFams[i][j] << " ";
        }
        cout << "}" << endl;
    }
}