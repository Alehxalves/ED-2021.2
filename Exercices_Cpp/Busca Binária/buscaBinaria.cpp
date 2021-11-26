#include <iostream>
#include <vector>
#include <set>

using namespace std;

int busca_binaria(vector<int> & vet, int size, int item){
    int inicio = 0; 
    int fim = size - 1; 
    int contador = 0;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        contador = contador + 1;
        if(vet[meio] == item){
          break;          
        }else{
            if(vet[meio] > item)
                fim = meio - 1;
            else
                inicio = meio + 1;
        }
    }
    return contador;
}

void inserirVetIte(vector<int> & primaryVec, vector<int> & busca, vector<int> & ite, int size_busca){
    int k = 0;
    for(int i = 0; i < size_busca; i++){
        k = busca_binaria(primaryVec, primaryVec.size(), busca[i]);
        ite.push_back(k);
    }
}

void showVec(vector<int> & vec, int size){
    for(int i = 0; i < size; i++){
        if(i == size - 1)
            cout << vec[i] << endl;
        cout << vec[i] << " ";
    }
}

int main(){
    int n, m, value;
    vector<int> primaryVec, busca, ite;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> value;
        primaryVec.push_back(value);
    }
    
    for(int i = 0; i < m; i++){
        cin >> value;
        busca.push_back(value);
    }
    
    inserirVetIte(primaryVec, busca, ite, m);
    showVec(ite, ite.size());
    return 0;
}