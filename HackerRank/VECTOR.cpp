#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int> > matriz(n);
    for(int i = 0; i < n; i++){
        int size = 0;
        cin >> size;
        vector<int> vec(size, 0);
        for(int j = 0; j < size; j++){
            int aux;
            cin >> aux;
            vec[j] = aux;
        }
        matriz[i] = vec;
    }
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        cout << matriz.at(x).at(y) << endl;
    }
}