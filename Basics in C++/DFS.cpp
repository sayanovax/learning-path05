#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int n;                       // number of vertices
    vector<vector<int> > adj;    // adjacency list (Dev-C++ safe)

    // Recursive DFS utility function
    void DFSUtil(int u, vector<bool>& visited, vector<int>& parent) {
        visited[u] = true;
        cout << u << " ";

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                parent[v] = u;   // record spanning tree edge
                DFSUtil(v, visited, parent);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    // Add edge (undirected by default)
    void addEdge(int u, int v, bool undirected = true) {
        adj[u].push_back(v);
        if (undirected)
            adj[v].push_back(u);
    }

    // User-defined DFS function
    void DFS(int start) {
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);

        cout << "DFS Traversal: ";
        DFSUtil(start, visited, parent);

        cout << "\n\nSpanning Tree Edges:\n";
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << endl;
        }
    }

    // DFS for disconnected graphs
    void DFSAll() {
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);

        cout << "DFS Traversal (All Components): ";

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited, parent);
            }
        }

        cout << "\n\nSpanning Tree Edges:\n";
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << endl;
        }
    }
};

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.DFS(start);
    // g.DFSAll();  // uncomment for disconnected graph DFS

    return 0;
}

