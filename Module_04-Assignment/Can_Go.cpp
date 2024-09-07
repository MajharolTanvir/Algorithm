#include <bits/stdc++.h>
using namespace std;

int row, col;
char a[1005][1005];
bool vis[1005][1005];

vector<pair<int,int>> vec = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col || a[i][j] == '#'){
        return false;
    }
    return true;
}

void dfs(int src_i, int src_j){
    vis[src_i][src_j] = true;

    for(int i = 0; i < 4; i++){
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

    pair<int , int> A, B;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
           if(a[i][j] == 'A'){
                A = {i, j};
           }
           if(a[i][j] == 'B'){
                B = {i, j};
           }
        }
    }

    memset(vis, false, sizeof(vis));
    dfs(A.first, A.second);

    if(vis[B.first][B.second] == 1){
        cout << "YES" << endl;
    }
    else 
        cout << "NO" << endl;

    return 0;
}