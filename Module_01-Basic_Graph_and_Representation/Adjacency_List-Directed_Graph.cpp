#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector <int> matrix[node];

    while(edge--){
        int input_1, input_2;
        cin >> input_1 >> input_2;

        matrix[input_1].push_back(input_2);
    }

    int checkValue;
    cin >> checkValue;

    for(int x : matrix[checkValue]){
        cout << x << " ";
    }

    // for(int i = 0; i < matrix[checkValue].size(); i++){
    //     cout << matrix[checkValue][i] << " ";
    // }

    return 0;
}