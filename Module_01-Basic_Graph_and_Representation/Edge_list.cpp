#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector <pair<int, int>> v;

    while(edge--){
        int input_1, input_2;
        cin >> input_1 >> input_2;
        v.push_back({input_1, input_2});
    }

    // for(pair<int, int> p : v){
    //     cout << p.first << " " << p.second << endl;
    // }

    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}