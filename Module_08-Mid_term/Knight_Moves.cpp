#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int row, col;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> vec = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

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
    int t;
    cin >> t;
    while(t--){
        cin >> row >> col;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                vis[i][j] = false;
                dis[i][j] = -1;
            }
        }

        int ki, kj;
        cin >> ki >> kj;
        bfs(ki, kj);

        int qi, qj;
        cin >> qi >> qj;

        cout << dis[qi][qj] << endl;

    }
    return 0;
}