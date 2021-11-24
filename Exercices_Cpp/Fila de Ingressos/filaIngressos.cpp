#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int busca_binaria(vector<int> & vet, int n, int item){
  int inicio = 0; 
  int fim = n - 1; 
  int contador = 0; 
  while (inicio <= fim){
    int meio = (inicio + fim);
    contador = contador + 1;
    if (vet[meio] == item){
      break;         
    }
    else{
      if (vet[meio] > item){
        fim = meio - 1;
      }
      else{
        inicio = meio + 1;
      }
    }
  }
  return contador;
}

void showVector(vector<int> & vet, int n){
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << vet[i] << endl;
            break;
        }
        cout << vet[i] << " ";
    }
}

int main(){
  vector<int> fila;
  int n, value;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> value;
    fila.push_back(value);
  }
  showVector(fila, n);
  cout << busca_binaria(fila, n, 4);
}