#include <iostream>
#include <limits.h>   // use this instead of climits
using namespace std;

#define V 8

void dijkstra(int graph[V][V], int start)
{
    int dist[V], visited[V], parent[V];

    // STEP 1: Initialization
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    // STEP 2: Main loop
    for(int count = 0; count< V - 1; count++)
    {
        int min = INT_MAX, u = -1;

        // Pick minimum distance unvisited vertex
        for(int i = 0; i < V; i++)
        {
            if(visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Relax neighbors
        for(int w = 0; w < V; w++)
        {
            if(graph[u][w]==1 && visited[w] == 0 &&
               dist[u] + graph[u][w] < dist[w])
            {
                dist[w] = dist[u] + graph[u][w];
                parent[w] = u;
            }
        }
    }

    // STEP 3: Print shortest path A ? H
    int end = 7, path[V], idx = 0;

    for(int j = end; j != -1; j = parent[j])
        path[idx++] = j;

    cout << "Shortest path A to H: ";
    for(int i = idx - 1; i >= 0; i--)
        cout << char('A' + path[i]) << " ";
}

int main()
{
    int graph[V][V] =
    {
        {0,4,0,2,0,0,0,0},
        {4,0,5,0,0,0,0,0},
        {0,5,0,1,3,0,0,0},
        {2,0,1,0,8,10,0,0},
        {0,0,3,8,0,2,3,0},
        {0,0,0,10,2,0,1,5},
        {0,0,0,0,3,1,0,2},
        {0,0,0,0,0,5,2,0}
    };

    dijkstra(graph, 0);
    return 0;
}

