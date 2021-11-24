#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void inverter(vector<int> & vet, int index){
  for (int i = 0, j = index; i < j; i++, j--)
    swap(vet[i], vet[j]);
}

vector<int> tapioca_Sort(vector<int> & vet, int n){
    int j = maior(vet, 0, n);
    vector<int> flip;
    for(int i = n - 1; i == 0; i--){
        if(j < i){
            inverter(vet, i);
        }
    }
    return flip;
}

void printVector(vector<int> & vet, int n){
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << vet[i] << endl;
            break;
        }
        cout << vet[i] << " ";
    }
}

int maior(vector<int> & vet, int r, int n){
    int maior = 0, indice = 0;
    for(int i = r; i < n; i++){
        if(vet[i] > maior){
            maior = vet[i];
            indice = i;
        }
    }  
    return indice;
}

int main(){
    vector<int> vet;
    int n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        vet.push_back(value);
    }
    tapioca_Sort(vet, n);
    printVector(vet, n);
    return 0;
}