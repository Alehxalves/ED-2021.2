#include <iostream>
#include <vector>
using namespace std;

int selecionildo(vector <int> & vet, int n){
    int cont = 0;
    for(int p = 0; p < n; p++){
        int min_idx = p;    
        for(int k = p + 1; k <= n-1; k++){
            if(vet[k] < vet[min_idx]){
                min_idx = k;
            }
        }
        if(min_idx != p) cont++;
        swap(vet[p], vet[min_idx]);
    }
    return cont;
}

int main(){
    vector<int> vet;
    int n, value;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        vet.push_back(value);
    }
    int cont = selecionildo(vet, n);
    cout << cont << endl;
    return 0;
}