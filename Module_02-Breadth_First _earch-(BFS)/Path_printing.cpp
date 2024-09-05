#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child: v[par]){  
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
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

        v[input_1].push_back(input_2);
        v[input_2].push_back(input_1);
    }

    int src, des;
    cin >> src >> des;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(src);

    int x = des;
    while(x != -1){
        cout << x << " ";
        x = parent[x];
    }

    return 0;
}