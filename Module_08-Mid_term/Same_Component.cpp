#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int row, col;
bool vis[N][N];
int dis[N][N];
char a[N][N];
vector<pair<int, int>> vec = {{0, 1},{0, -1},{-1, 0},{1, 0}};

bool valid(int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col || a[i][j] == '-'){
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
        for(int i = 0; i < 4; i++){
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

    int s1, s2, d1, d2;
    cin >> s1 >> s2 >> d1 >> d2;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(s1, s2);

    if(vis[s1][s2] == vis[d1][d2]){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}