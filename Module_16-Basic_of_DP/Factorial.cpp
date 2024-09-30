#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n ==0) return 1;
    int miniFactorial = fact(n - 1);
    return miniFactorial * n;
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}