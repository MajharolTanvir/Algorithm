#include <bits/stdc++.h>
using namespace std;

int row, col;
bool vis[20][20];
int dis[20][20];
char a[20][20];
vector<pair<int, int>> vec = {{0, 1},{0, -1},{-1, 0},{1, 0}};

bool valid(int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col){
        return false;
    }
    return true;
}

void bfs(int si, int sj){
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        for(int i = 0; i < vec.size(); i++){
            int children_i = par.first + vec[i].first; 
            int children_j = par.second + vec[i].second; 
            if(valid(children_i, children_j) && !vis[children_i][children_j]){
                q.push({children_i, children_j});
                vis[children_i][children_j] = true;
                dis[children_i][children_j] = dis[par.first][par.second] + 1;
            } 
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
    memset(dis, -1, sizeof(dis));
    bfs(src_i, src_j);

    cout << dis[0][3] << endl;
    return 0;
}