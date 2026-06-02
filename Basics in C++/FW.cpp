#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF 1000000000   // Large value for infinity

class Graph {
private:
    int n;
    vector<vector<int> > dist;   // distance matrix
    vector<vector<int> > next;   // path reconstruction

public:
    Graph(int vertices) {
        n = vertices;
        dist.resize(n, vector<int>(n, INF));
        next.resize(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
            next[i][i] = i;
        }
    }

    // Add edge
    void addEdge(int u, int v, int w, bool undirected = true) {
        dist[u][v] = w;
        next[u][v] = v;

        if (undirected) {
            dist[v][u] = w;
            next[v][u] = u;
        }
    }

    // Floyd–Warshall algorithm
    void floydWarshall() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][k] + dist[k][j] < dist[i][j]) {

                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    // Print path from u to v
    void printPath(int u, int v) {
        if (next[u][v] == -1) {
            cout << "No path";
            return;
        }
        cout << u << " ";
        while (u != v) {
            u = next[u][v];
            cout << u << " ";
        }
    }

    // Output trace for a single source
    void printSingleSourceResult(int src) {
        cout << "\nShortest paths from source " << src << ":\n";
        cout << "Destination\tDistance\tPath\n";

        for (int i = 0; i < n; i++) {
            cout << i << "\t\t";
            if (dist[src][i] == INF) {
                cout << "INF\t\tNo path";
            } else {
                cout << dist[src][i] << "\t\t";
                printPath(src, i);
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

    g.floydWarshall();

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    g.printSingleSourceResult(src);

    return 0;
}

