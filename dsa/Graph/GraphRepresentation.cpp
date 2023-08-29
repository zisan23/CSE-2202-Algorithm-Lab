// graph representation using Adjacency Matrix and Adjacency List

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    int **adjMatrix;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;

        adjMatrix = new int *[vertices];

        for (int i = 0; i < vertices; i++)
        {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printAdjMatrix()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjList()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " --> ";
            for (int j = 0; j < vertices; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};