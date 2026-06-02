#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Structure to store an edge */
struct Edge {
    int u;
    int v;
    int w;
};

/* Comparator for min-heap */
struct Compare {
    bool operator()(Edge a, Edge b) {
        return a.w > b.w;
    }
};

/* Disjoint Set (Union-Find) */
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findSet(int x) {
        if (parent[x] != x)
            parent[x] = findSet(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = findSet(x);
        int py = findSet(y);

        if (px != py) {
            if (rank[px] < rank[py])
                parent[px] = py;
            else if (rank[px] > rank[py])
                parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
};

class Graph {
private:
    int n;   // number of vertices
    vector<vector<Edge> > adj;  // adjacency list

public:
    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    // Add undirected weighted edge
    void addEdge(int u, int v, int w) {
        Edge e;
        e.u = u;
        e.v = v;
        e.w = w;

        adj[u].push_back(e);
        adj[v].push_back(e);
    }

    // Universal Kruskal's Algorithm
    void kruskalMST() {
        priority_queue<Edge, vector<Edge>, Compare> pq;

        // Push all edges into priority queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                Edge e = adj[i][j];
                if (e.u < e.v)   // avoid duplicate edges
                    pq.push(e);
            }
        }

        DisjointSet ds(n);

        int totalWeight = 0;
        cout << "\nEdges in Minimum Spanning Tree:\n";
        cout << "Edge\tWeight\n";

        while (!pq.empty()) {
            Edge e = pq.top();
            pq.pop();

            int u = e.u;
            int v = e.v;

            if (ds.findSet(u) != ds.findSet(v)) {
                ds.unionSet(u, v);
                cout << u << " - " << v << "\t" << e.w << endl;
                totalWeight += e.w;
            }
        }

        cout << "\nTotal weight of MST = " << totalWeight << endl;
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

    g.kruskalMST();
    return 0;
}

