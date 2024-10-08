#include <bits/stdc++.h>
const long long int INF = 1e18 + 5;
using namespace std;


int main()
{
    int n, e;
    cin >> n >> e;
    long long int adj[n + 1][n + 1];

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            adj[i][j] = INF;
            if(i == j){
                adj[i][j] = 0;
            }
        }
    }

    while(e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        if(adj[a][b] > w){
            adj[a][b] = w;
        }
    }


    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        if(adj[x][y] == INF){
            cout << -1 << endl;
        }
        else
            cout <<  adj[x][y] << endl;

    }


    return 0;
}