#include <iostream>
#include <algorithm>
using namespace std;

#define V 4
struct Edge { int u, v, w; };

int find(int parent[], int i)
{
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot]) parent[yroot] = xroot;
    else { parent[yroot] = xroot; rank[xroot]++; }
}

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void kruskalMST(Edge edges[], int E)
{
    sort(edges, edges+E, cmp);

    int parent[V], rank[V] = {0};
    for(int i=0;i<V;i++) parent[i]=i;

    cout << "Edges in MST:\n";
    for(int i=0; i<E; i++)
    {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if(x != y)
        {
            cout << edges[i].u << " - " << edges[i].v << " (weight " << edges[i].w << ")\n";
            unionSet(parent, rank, x, y);
        }
    }
}

int main()
{
    Edge edges[] = { {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4} };
    int E = sizeof(edges)/sizeof(edges[0]);

    kruskalMST(edges, E);
    return 0;
}

