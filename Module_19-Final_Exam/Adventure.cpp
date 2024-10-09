#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
const int maxW = 1005;
int dp[maxN][maxW];

int knapsack(int n, int weight[], int value[], int w)
{
    if(n < 0 || w == 0) return 0;
    if(dp[n][w] != -1)
        return dp[n][w];
    
    if(weight[n] <= w)
    {
        int opt1 = knapsack(n - 1, weight, value, w - weight[n]) + value[n];
        int opt2 = knapsack(n - 1, weight, value, w);
        return dp[n][w] = max(opt1, opt2);
    }
    else
    {
        return dp[n][w] = knapsack(n - 1, weight, value, w);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, w;
        cin >> n >> w;

        int weight[n], value[n];

        for(int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }

        cout << knapsack(n - 1, weight, value, w) << "\n";
    }
    return 0;
}