/* Q4. Bin Packing problem (Best fit & First fit) */

#include <iostream>
#include <vector>
using namespace std;

void firstFit(vector<int>, int);
void bestFit(vector<int>, int);

int main()
{
    vector<int> items = {4, 8, 1, 4, 2, 1};
    int capacity = 10;

    firstFit(items, capacity);
    bestFit(items, capacity);
}

/* Add the item to the first bin that has enough space */
void firstFit(vector<int> items, int cap)
{
    vector<int> bins = {0}; // Initialise bins with 1 bin of capacity 0

    // Loop through each item
    for (int i = 0; i < items.size(); i++)
    {
        bool binFound = false;
        // Add it to the first most bin
        for (int b = 0; b < bins.size(); b++)
        {
            // If it can fit into the bin, add it
            if (bins[b] + items[i] <= cap)
            {
                bins[b] += items[i];
                binFound = true;
                break;
            }
        }
        // If there was no bin found
        if (!binFound)
        {
            // Create a new one with the item placed in it
            bins.push_back(items[i]);
        }
    }
    cout << "[First Fit] Bins used: " << bins.size() << endl;
}

/* Add the item to the fullest bin it can go into */
void bestFit(vector<int> items, int cap)
{
    vector<int> bins = {0}; // Initialise bins with 1 bin of capacity 0

    // Loop through each item
    for (int i = 0; i < items.size(); i++)
    {
        bool binFound = false;
        int bestBin = -1;
        for (int b = 0; b < bins.size(); b++)
        {
            // If it can fit into the bin..
            if (bins[b] + items[i] <= cap)
            {
                // If it's -1, we haven't yet chosen a bin, so choose this one.
                if (bestBin = -1)
                {
                    bestBin = b;
                    binFound = true;
                }
                // If the bin is more full than the current fullest bin
                else if (bins[b] > bins[bestBin])
                {
                    bestBin = b;
                }
            }
        }
        // Add the item to the best bin (if we found one)
        if (binFound)
        {
            bins[bestBin] += items[i];
        }
        // Otherwise create a new bin for the item
        else
        {
            bins.push_back(items[i]);
        }
    }
    cout << "[Best Fit] Bins used: " << bins.size() << endl;
}