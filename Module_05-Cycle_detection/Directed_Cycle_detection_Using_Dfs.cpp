#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int vis[N];
int pathVis[N];
int parentArray[N];
vector<int> adj[N];
bool ans;

void dfs(int parent){
    vis[parent] = true;
    pathVis[parent] = true;
    for(int child: adj[parent]){
        if(pathVis[child])
        {
            ans = true;
        }
        if(!vis[child]){
            dfs(child);
        }
    }
    pathVis[parent] = false;
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    while(edge--){
        int input_1, input_2;
        cin >> input_1 >> input_2;

        adj[input_1].push_back(input_2);
    }

    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));

    ans = false;

    for(int i = 0; i < node; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    if(ans) cout << "Cycle detected" << endl;
    else cout << "Cycle not detected" << endl;

    return 0;
}