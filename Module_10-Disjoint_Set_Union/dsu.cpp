#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];

void dsu_initialize(int n){
    for(int i = 0; i < n; i++){
        par[i] = -1;
    }
    par[1] = 2;
    par[2] = 3;
}

int dsu_find(int node) 
{
    if(par[node] == -1) return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

int dsu_union(int node1, int node2) {
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    par[leaderA] = leaderB;
}

int main()
{
    dsu_initialize(7);
    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}