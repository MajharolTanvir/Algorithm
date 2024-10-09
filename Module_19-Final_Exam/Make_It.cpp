#include <bits/stdc++.h>
using namespace std;
long long int input;

int dp[100005];

bool makeIt(long long int n)
{
    if(n > input)
        return false;
    if(n == input)
        return true;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = makeIt(n + 3) || makeIt(n * 2); 
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> input;

        memset(dp, -1, sizeof(dp));

        if(makeIt(1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}