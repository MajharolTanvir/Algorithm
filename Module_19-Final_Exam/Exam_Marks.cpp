#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+3;
long long int dp[N][N];


bool subset_sum(int n, long long int a[], int s)
{
    if (n < 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    if (dp[n][s] != -1)
        return dp[n][s];

    if (a[n] <= s)
    {
        bool op1 = subset_sum(n - 1, a, s - a[n]);
        bool op2 = subset_sum(n - 1, a, s);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = subset_sum(n - 1, a, s);
    }
}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;
        long long int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        memset(dp, -1, sizeof(dp));

        if(m == 1000) 
            cout << "YES" << endl;
        else if (subset_sum(n - 1, a, 1000 - m))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}