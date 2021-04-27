/* Q1. Vertex cover problem */
/*
Algorithm:
1) Initialize the result as {}
2) Consider a set of all edges in given graph.  Let the set be E.
3) Do following while E is not empty
...a) Pick an arbitrary edge (u, v) from set E and add 'u' and 'v' to result
...b) Remove all edges from E which are either incident on u or v.
4) Return result
(source: https://www.geeksforgeeks.org/vertex-cover-problem-set-1-introduction-approximate-algorithm-2/)
*/
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    vector<int> connected;
    bool visited = false;
};

int main()
{

    const int numOfNodes = 6;
    node nodes[numOfNodes];
    nodes[0].connected = {1};
    nodes[1].connected = {0, 2, 3};
    nodes[2].connected = {1, 4, 5};
    nodes[3].connected = {1, 4};
    nodes[4].connected = {3, 2};
    nodes[5].connected = {2};

    for (int i = 0; i < numOfNodes; i++)
    {
        // If we haven't yet visited this node
        if (nodes[i].visited == false)
        {
            // Go through it's adjacent nodes and choose one that's
            // not yet visited.
            for (int j = 0; j < nodes[i].connected.size(); j++)
            {
                // If we haven't visited the current connected node
                if (nodes[nodes[i].connected[j]].visited == false)
                {
                    cout << "Edge visited: " << i << "->" << nodes[i].connected[j] << endl;
                    // Mark our two nodes (edge) as visited
                    nodes[i].visited = true;
                    nodes[nodes[i].connected[j]].visited = true;
                    break;
                }
            }
        }
    }
    // Print all nodes that were visited
    // This is our vertex cover
    cout << "Vertex Cover: ";
    for (int i = 0; i < numOfNodes; i++)
    {
        if (nodes[i].visited)
        {
            cout << i << " ";
        }
    }
}