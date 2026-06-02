#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/* Structure to store adjacency list nodes */
struct Edge {
    int v;
    int w;
};

/* Structure for priority queue */
struct PQNode {
    int vertex;
    int key;
};

/* Min-heap comparator */
struct Compare {
    bool operator()(PQNode a, PQNode b) {
        return a.key > b.key;
    }
};

class Graph {
private:
    int n;                              // number of vertices
    vector<vector<Edge> > adj;          // adjacency list

public:
    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    // Add undirected weighted edge
    void addEdge(int u, int v, int w) {
        Edge e1, e2;
        e1.v = v;  e1.w = w;
        e2.v = u;  e2.w = w;

        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }

    // Universal Prim's Algorithm
    void primMST(int start) {
        vector<int> key(n, INT_MAX);
        vector<int> parent(n, -1);
        vector<bool> inMST(n, false);

        priority_queue<PQNode, vector<PQNode>, Compare> pq;

        key[start] = 0;
        PQNode s;
        s.vertex = start;
        s.key = 0;
        pq.push(s);

        while (!pq.empty()) {
            int u = pq.top().vertex;
            pq.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].v;
                int w = adj[u][i].w;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;

                    PQNode node;
                    node.vertex = v;
                    node.key = key[v];
                    pq.push(node);
                }
            }
        }

        // Output MST
        int totalCost = 0;
        cout << "\nEdges in Minimum Spanning Tree:\n";
        cout << "Edge\tWeight\n";

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << "\t" << key[i] << endl;
                totalCost += key[i];
            }
        }

        cout << "\nTotal weight of MST = " << totalCost << endl;
    }
};

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.primMST(start);

    return 0;
}

