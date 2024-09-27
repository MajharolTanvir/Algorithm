#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int row, col;
char a[N][N];
bool vis[N][N];
int mini, comp = INT_MAX;
vector<pair<int,int>> vec = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col){
        return false;
    }
    return true;
}

void dfs(int src_i, int src_j){
    mini++;
    vis[src_i][src_j] = true;

    for(int i = 0; i < 4; i++){
        int children_i = src_i + vec[i].first; 
        int children_j = src_j + vec[i].second; 
        if(valid(children_i, children_j) && !vis[children_i][children_j] && a[children_i][children_j] == '.'){
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

    memset(vis, false, sizeof(vis));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
        {
            mini = 0;
            if(!vis[i][j] && a[i][j] == '.')
            {
                dfs(i, j);
                comp = min(mini, comp);
            }
        }
    }

    if(comp == INT_MAX)
        cout << -1 << "\n";
    else
        cout << comp << "\n";


    return 0;
}