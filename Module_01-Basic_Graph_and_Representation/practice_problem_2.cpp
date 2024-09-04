#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;

    // 1. Adjacency matrix
    // int matrix[node][edge];
    // memset(matrix, 0, sizeof(matrix));

    // while(edge--){
    //     int input_1, input_2;
    //     cin >> input_1 >> input_2;

    //     matrix[input_1][input_2] = 1;
    // }


    // int input_3, input_4;
    // cin >> input_3 >> input_4;

    // if(matrix[input_3][input_4] == 1)
    //     cout << "Connected" << endl;
    // else
    //     cout << "Not Connected" << endl;

    // 2. Adjacency List
    vector<int> matrix[node];

    while(edge--){
        int input_1, input_2;
        cin >> input_1 >> input_2;
        matrix[input_1].push_back(input_2);
    }

    int input_3;
    cin >> input_3;

    for(int x: matrix[input_3]){
        cout << x << " ";
    }
        
    return 0;
}