#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int row, col;
bool vis[N][N];
int dis[N][N];
char a[N][N];
vector<pair<int, int>> vec = {{0, 1},{0, -1},{-1, 0},{1, 0}};
pair<int, int >parent[N][N];

bool valid(int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col || a[i][j] == '#'){
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
            if(valid(children_i, children_j) && !vis[children_i][children_j] && a[children_i][children_j] != '#'){
                q.push({children_i, children_j});
                vis[children_i][children_j] = true;
                dis[children_i][children_j] = dis[par.first][par.second] + 1;
                parent[children_i][children_j] = {par.first, par.second };
            } 
        }
    }
}

int main()
{
    int si, sj, di, dj;
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
           cin >> a[i][j];
           if(a[i][j] == 'A')
           {
            si = i;
            sj = j;
           }
           else if(a[i][j] == 'B')
           {
            di = i;
            dj = j;
           }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);

    if(vis[di][dj])
    {
        cout << "YES\n" << dis[di][dj] << endl;

        pair<int, int> p = {di, dj};
        vector<pair<int, int>> path;

        while(!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }
        path.push_back({si, sj});

        reverse(path.begin(), path.end());
        string ans = "";
        for(int i = 1; i < path.size(); i++){
            if(path[i-1].first == path[i].first){
                if(path[i-1].second - 1 == path[i].second)
                {
                    ans += "L";
                }
                else
                {
                    ans += "R";
                }
            }
            else
            {
                if(path[i-1].first - 1 == path[i].first)
                {
                    ans += "U";
                }
                else
                {
                    ans += "D";
                }
            }
        }

        cout << ans << endl;
    }
    else 
    {
        cout << "NO\n";
    }
    
    return 0;
}