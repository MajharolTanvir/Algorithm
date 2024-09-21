#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

// DSU initialization
void dsu_initialize(int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

// DSU find with path compression
int dsu_find(int node)
{
    if(parent[node] == -1) return node;
    int leader = dsu_find(parent[node]); // Path compression
    parent[node] = leader;
    return leader;
}

// DSU union by size
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

// Edge class
class Edge
{
    public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

// Comparator for sorting edges based on weight
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int main()
{
    int n,e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> edgeList;

    // Reading edges
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    // Sort edges by weight
    sort(edgeList.begin(), edgeList.end(), cmp);

    int totalCost = 0;

    // Kruskal's Algorithm
    for(Edge ed: edgeList)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);
        if(leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u, ed.v);
            totalCost += ed.w;
        }
    }

    cout << totalCost << endl;

    return 0;
}