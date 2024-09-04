#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    int matrix[node][edge];
    memset(matrix, 0, sizeof(matrix));

    while(edge--){
        int input_1, input_2;
        cin >> input_1 >> input_2;

        matrix[input_1][input_2] = 1;
        matrix[input_2][input_1] = 1;
    }

    int input_3, input_4;
    cin >> input_3 >> input_4;

    if(matrix[input_3][input_4] == 1)
        cout << "Connected" << endl;
    else
        cout << "Not Connected" << endl;
        
    return 0;
}