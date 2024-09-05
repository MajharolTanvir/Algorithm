#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        cout << par << endl;

        // for(int i = 0; i < v[par].size(); i++){
        //     int child = v[par][i];
        //     cout << child << endl;
        // }

        for(int child: v[par]){  
            if(!vis[child]){
                q.push(child);
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
    bfs(src);

    return 0;
}