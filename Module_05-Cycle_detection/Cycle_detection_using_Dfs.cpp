#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int vis[N];
int parentArray[N];
bool ans;
vector<int> adj[N];

void dfs(int parent){
    vis[parent] = true;
    for(int child: adj[parent]){
        if(vis[child] && parentArray[parent] != child){
            ans = true;
        }
        if(!vis[child]){
            parentArray[child] = parent;
            dfs(child);
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    while(edge--){
        int input_1, input_2;
        cin >> input_1 >> input_2;

        adj[input_1].push_back(input_2);
        adj[input_2].push_back(input_1);
    }

    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;

    for(int i = 0; i < node; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    if(ans)
        cout << "Cycle detected" << endl;
    else
        cout << "Cycle Not Found" << endl;

    return 0;
}