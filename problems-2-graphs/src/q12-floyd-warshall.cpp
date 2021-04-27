/* 12. Run the Floyd Warshall algorithm on a specific graph */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct edge
{
    int from, to;
    float weight; // to store infinity, must be float.
};
int main()
{
    const int numOfEdges = 10;
    const int numOfNodes = 6;

    int nodes[numOfNodes] = {0, 1, 2, 3, 4, 5}; // Relaballing as (original no.) - 1

    edge edges[numOfEdges];
    edges[0].from = 0;
    edges[0].to = 4;
    edges[0].weight = -1;
    edges[1].from = 3;
    edges[1].to = 0;
    edges[1].weight = -4;
    edges[2].from = 1;
    edges[2].to = 0;
    edges[2].weight = 1;
    edges[3].from = 1;
    edges[3].to = 3;
    edges[3].weight = 2;
    edges[4].from = 4;
    edges[4].to = 1;
    edges[4].weight = 7;
    edges[5].from = 3;
    edges[5].to = 4;
    edges[5].weight = 3;
    edges[6].from = 2;
    edges[6].to = 1;
    edges[6].weight = 2;
    edges[7].from = 5;
    edges[7].to = 1;
    edges[7].weight = 5;
    edges[8].from = 5;
    edges[8].to = 2;
    edges[8].weight = 10;
    edges[9].from = 2;
    edges[9].to = 5;
    edges[9].weight = -8;

    // Create N * N matrix
    float matrix[numOfNodes][numOfNodes];

    // Fill with infinity (or 0 if it's looking at the same node)
    for (int i = 0; i < numOfNodes; i++)
    {
        for (int j = 0; j < numOfNodes; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = INFINITY;
            }
        }
    }

    // Fill in the weights from each edge
    for (int i = 0; i < numOfEdges; i++)
    {
        matrix[edges[i].from][edges[i].to] = edges[i].weight;
    }

    for (int k = 0; k < numOfNodes; k++)
    {
        for (int i = 0; i < numOfNodes; i++)
        {
            for (int j = 0; j < numOfNodes; j++)
            {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    // Print the matrix
    for (int i = 0; i < numOfNodes; i++)
    {
        for (int j = 0; j < numOfNodes; j++)
        {
            cout << matrix[i][j] << "      ";
        }
        cout << endl;
    }
}
