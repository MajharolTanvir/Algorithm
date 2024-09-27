#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];
int ans = 0;

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

int main()
{
    int n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<pair<int, int>> edgeList;

    while(e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA != leaderB)
        {
            dsu_union_by_size(a, b);
        }
        else {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}