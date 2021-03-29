/* 9. Write a working C++ program that uses the Bellman-Ford algorithm */

#include <iostream>
#include <cmath>
using namespace std;

struct edge
{
    // (NOTE: we're storing node index for start and end)
    int from;
    int to;
    int weight;
};
struct node
{
    int id;
};

int main()
{
    const int numOfEdges = 10;
    const int numOfNodes = 5;
    const int startingNodeIndex = 0;
    float bestDistance[numOfNodes];

    // Initialise nodes
    node nodes[numOfNodes];
    nodes[0].id = 0;
    nodes[1].id = 1;
    nodes[2].id = 2;
    nodes[3].id = 3;
    nodes[4].id = 4;
    // Initialise edges
    edge edges[numOfEdges];
    edges[0].from = 0;
    edges[0].to = 1;
    edges[0].weight = 6;
    edges[1].from = 0;
    edges[1].to = 3;
    edges[1].weight = 7;
    edges[2].from = 1;
    edges[2].to = 3;
    edges[2].weight = 8;
    edges[3].from = 1;
    edges[3].to = 2;
    edges[3].weight = 5;
    edges[4].from = 1;
    edges[4].to = 4;
    edges[4].weight = -4;
    edges[5].from = 2;
    edges[5].to = 1;
    edges[5].weight = -2;
    edges[6].from = 3;
    edges[6].to = 2;
    edges[6].weight = -3;
    edges[7].from = 3;
    edges[7].to = 4;
    edges[7].weight = 9;
    edges[8].from = 4;
    edges[8].to = 0;
    edges[8].weight = 2;
    edges[9].from = 4;
    edges[9].to = 2;
    edges[9].weight = 7;

    // Initialise best-distance array values to infinity
    for (int i = 0; i < numOfNodes; i++)
    {
        bestDistance[i] = INFINITY;
    }

    // Set starting node to distance 0
    bestDistance[startingNodeIndex] = 0;

    // Run (numberOfNodes - 1) iterations
    for (int i = 0; i < numOfNodes - 1; i++)
    {
        cout << "iteration #" << i << endl;
        // For each node...
        for (int currentNode = 0; currentNode < numOfNodes; currentNode++)
        {
            // For each edge where the node equals the current node...
            for (int currentEdge = 0; currentEdge < numOfEdges; currentEdge++)
            {
                if (edges[currentEdge].from == currentNode)
                {
                    // Check if new distance (Edge weight + Best distance) is less than current distance.
                    float newDistance = edges[currentEdge].weight + bestDistance[edges[currentEdge].from];
                    if (newDistance < bestDistance[edges[currentEdge].to])
                    {
                        // Rleax node
                        bestDistance[edges[currentEdge].to] = newDistance;
                        cout << edges[currentEdge].to << ": " << bestDistance[edges[currentEdge].to] << endl;
                    }
                }
            }
        }
    }

    // Run iterations again but for finding the negative cycles
    for (int i = 0; i < numOfNodes - 1; i++)
    {
        cout << "iteration #" << i << endl;
        for (int currentNode = 0; currentNode < numOfNodes; currentNode++)
        {
            for (int currentEdge = 0; currentEdge < numOfEdges; currentEdge++)
            {
                if (edges[currentEdge].from == currentNode)
                {
                    float newDistance = edges[currentEdge].weight + bestDistance[edges[currentEdge].from];
                    if (newDistance < bestDistance[edges[currentEdge].to])
                    {
                        // Set to negative infinity
                        bestDistance[edges[currentEdge].to] = -INFINITY;
                        cout << edges[currentEdge].to << ": " << bestDistance[edges[currentEdge].to] << endl;
                    }
                }
            }
        }
    }

    for (int i = 0; i < numOfNodes; i++)
    {
        cout << i << ": " << bestDistance[i] << endl;
    }
    return 0;
}
