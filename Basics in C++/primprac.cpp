#include <iostream>
#include <climits>
using namespace std;

#define V 5  // Example: 5 vertices for simplicity

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int w = 0; w < V; w++)
        if (!mstSet[w] && key[w] < min)
            min = key[w], min_index = w;
    return min_index;
}

void primMST(int graph[V][V])
{
    int parent[V];     // Store MST
    int key[V];        // Min weight to connect
    bool mstSet[V];    // Included in MST

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;    // Start from vertex 0
    parent[0] = -1; 

    for (int count = 0; count < V-1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print MST edges
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " (weight " << graph[i][parent[i]] << ")\n";
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}

