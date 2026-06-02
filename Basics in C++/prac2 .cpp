#include <iostream>
using namespace std;

#define V 8

void dfs(int graph[V][V], int visited[V], int start)
{
    cout << start << " ";
    visited[start] = 1;

    for (int i = 0; i < V; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}

int main()
{
    int graph[V][V] =
    {
        {0,1,0,1,0,0,0,0}, // A
        {1,0,1,0,0,0,0,0}, // B
        {0,1,0,1,1,0,0,0}, // C
        {1,0,1,0,0,0,0,0}, // D
        {0,0,1,0,0,1,1,1}, // E
        {0,0,0,0,1,0,0,0}, // F
        {0,0,0,0,1,0,0,0}, // G
        {0,0,0,0,1,0,0,0}  // H
    };

    int visited[V] = {0};

    cout << "DFS Traversal: ";
    dfs(graph, visited, 0);  // Start from A

    return 0;
}

