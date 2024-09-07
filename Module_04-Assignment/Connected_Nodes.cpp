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
        matrix[input_2].push_back(input_1);
    }

    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++){
        int checkValue;
        cin >> checkValue;

        if(matrix[checkValue].empty()){
            cout << -1;
        }

        sort(matrix[checkValue].begin(), matrix[checkValue].end(), greater<int>());

        for(int x : matrix[checkValue]){
            cout << x << " ";
        }

        cout << endl;
    }


    return 0;
}