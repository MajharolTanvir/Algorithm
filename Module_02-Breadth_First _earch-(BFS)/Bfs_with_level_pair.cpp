#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

void bfs(int src, int des){
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    while(!q.empty()){
        pair <int, int> p = q.front();
        int par = p.first;
        int level = p.second;
        q.pop();

        if(par == des){
            cout << level << endl;
        }

        for(int child: v[par]){  
            if(!vis[child]){
                q.push({child, level + 1});
                vis[child] = true;
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

    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    bfs(src, 4);

    return 0;
}