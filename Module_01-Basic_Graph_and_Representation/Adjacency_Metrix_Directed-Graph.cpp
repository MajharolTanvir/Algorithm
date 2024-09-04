#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    int matrix[node][edge];
    memset(matrix, 0, sizeof(matrix));
    while(edge--){
        int input1, input2;
        cin >> input1 >> input2;
        matrix[input1][input2] = 1;
    }

    int checkValue1, checkValue2;
    cin >> checkValue1 >> checkValue2;

    if(matrix[checkValue1][checkValue2] == 1)
        cout << "Connected" << endl;
    else 
        cout << "Not Connected" << endl;

    return 0;
}