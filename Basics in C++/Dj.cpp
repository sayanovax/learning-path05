#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/* Edge structure */
struct Edge {
    int v;
    int w;
};

/* Priority queue node */
struct Node {
    int vertex;
    int dist;
};

/* Min-heap comparator */
struct Compare {
    bool operator()(Node a, Node b) {
        return a.dist > b.dist;
    }
};

class Graph {
private:
    int n;
    vector<vector<Edge> > adj;

public:
    Graph(int vertices) {
        n = vertices;
        adj.resize(n);
    }

    // Add edge (undirected by default)
    void addEdge(int u, int v, int w, bool undirected = true) {
        Edge e1;
        e1.v = v;
        e1.w = w;
        adj[u].push_back(e1);

        if (undirected) {
            Edge e2;
            e2.v = u;
            e2.w = w;
            adj[v].push_back(e2);
        }
    }

    // Print shortest path using parent array
    void printPath(int parent[], int v) {
        if (v == -1)
            return;
        printPath(parent, parent[v]);
        cout << v << " ";
    }

    // Dijkstra's Algorithm
    void dijkstra(int src) {
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);

        priority_queue<Node, vector<Node>, Compare> pq;

        dist[src] = 0;
        Node start;
        start.vertex = src;
        start.dist = 0;
        pq.push(start);

        while (!pq.empty()) {
            int u = pq.top().vertex;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].v;
                int w = adj[u][i].w;

                if (!visited[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;

                    Node node;
                    node.vertex = v;
                    node.dist = dist[v];
                    pq.push(node);
                }
            }
        }

        // Output result
        cout << "\nVertex\tDistance\tPath\n";
        for (int i = 0; i < n; i++) {
            cout << i << "\t";
            if (dist[i] == INT_MAX) {
                cout << "INF\t\tNo path";
            } else {
                cout << dist[i] << "\t\t";
                printPath(&parent[0], i);
            }
            cout << endl;
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

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}


