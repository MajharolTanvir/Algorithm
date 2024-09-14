#include <bits/stdc++.h>
using namespace std; 

const long long int INF = 1e18 + 5;

class Edge
{
public:
    int u, v;
    long long int c;
    Edge(int u, int v, long long int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

long long int dis[1005];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v;
        long long int c; // a, b, w
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    int s;
    cin >> s;
    dis[s] = 0;


    for (int i = 1; i < n; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INF && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int t;
        cin >> t;
        while(t--){
            int d;
            cin >> d;
            if(dis[d] != INF){
                cout << dis[d] << endl;
            }
            else {
                cout << "Not Possible" << endl;
            }
        }
    }
    
    return 0;
}