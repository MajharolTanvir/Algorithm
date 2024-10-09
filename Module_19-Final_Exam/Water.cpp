#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int h[n];
        for(int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        int firstMax = INT_MIN;
        int secondMax = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            firstMax = max(firstMax, h[i]);
        }

        for(int i = 0; i < n; i++)
        {
            if(h[i] != firstMax && h[i] > secondMax)
                secondMax = h[i];
        }

        for(int i = 0; i < n; i++)
        {
            if(h[i] == firstMax || h[i] == secondMax)
            {
                cout << i << " ";
            }
        }
        cout << endl;



    }
    return 0;
}