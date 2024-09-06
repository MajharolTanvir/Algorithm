#include <bits/stdc++.h>
using namespace std;

int row, col;
char a[20][20];
bool vis[20][20];
vector<pair<int,int>> vec = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col){
        return false;
    }
    return true;
}

void dfs(int src_i, int src_j){

    cout << src_i << " " << src_j << endl;
    vis[src_i][src_j] = true;

    for(int i = 0; i < vec.size(); i++){
        int children_i = src_i + vec[i].first; 
        int children_j = src_j + vec[i].second; 
        if(valid(children_i, children_j) && !vis[children_i][children_j]){
            dfs(children_i, children_j);
        } 
    }
}

int main()
{
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
           cin >> a[i][j];
        }
    }

    int src_i, src_j;
    cin >> src_i >> src_j;
    memset(vis, false, sizeof(vis));
    dfs(src_i, src_j);
    return 0;
}