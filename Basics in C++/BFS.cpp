#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<int> > adj;   // Dev-C++ safe

public:
    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    void addEdge(int u, int v, bool undirected = true) {
        adj[u].push_back(v);
        if (undirected)
            adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        vector<int> level(n, -1);
        queue<int> q;

        visited[start] = true;
        level[start] = 0;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }

        cout << "\n\nSpanning Tree Edges:\n";
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << endl;
        }

        cout << "\nNode Levels (Distance from start):\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << " : " << level[i] << endl;
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

    g.BFS(start);
    return 0;
}

