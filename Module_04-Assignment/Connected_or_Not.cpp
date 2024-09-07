#include <bits/stdc++.h>
using namespace std;

int main()
{

    int node, edge;
    cin >> node >> edge;
    int matrix[node][node];
    memset(matrix, 0, sizeof(matrix));
    while(edge--){
        int input1, input2;
        cin >> input1 >> input2;
        matrix[input1][input2] = 1;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int checkValue1, checkValue2;
        cin >> checkValue1 >> checkValue2;
        
        if(matrix[checkValue1][checkValue2] == 1 || checkValue1 == checkValue2)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }


    return 0;
}