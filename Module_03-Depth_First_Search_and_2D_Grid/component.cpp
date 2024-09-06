#include <bits/stdc++.h>
using namespace std;


const int N = 20;
vector<int> v[N];
bool vis[N];

void dfs(int src){
    cout << src << endl;
    vis[src] = true;

    for(int child: v[src]){
        if(!vis[child]){
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

        v[input_1].push_back(input_2);
        v[input_2].push_back(input_1);
    }
    memset(vis, false, sizeof(vis));

    int c = 0;
    
    for(int i = 0; i < node; i++){
        if(!vis[i]){
            dfs(i);
            c++;
        }
    }

    cout << "Component - " << c << endl;
    return 0;
}