#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int separa(vector<int> & vet, int low, int high){
    int pivot = vet[high];
    int i = low;
    for(int j = low; j < high; j++){
        if(vet[j] <= pivot){
            swap(vet[i], vet[j]);
            i++;
        }
    }
    swap(vet[i], vet[high]);
    return i;
}

void quickSort(vector<int> & vet, int low, int high){
    if(low < high){
        int pi = separa(vet, low, high);
        quickSort(vet, low, pi - 1);
        quickSort(vet, pi + 1, high);
    }
}

void isSaved(vector<int> & vac, vector<int> & pac, int n){
    for(int i = 0; i < n; i++){
        if(vac[i] < pac[i]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
} 

int main(){
    vector<int> vac, pac;
    
    int n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        vac.push_back(value);
    }
    for(int i = 0; i < n; i++){
        cin >> value;
        pac.push_back(value);
    }
    quickSort(vac, 0,  n - 1);
    quickSort(pac, 0,  n - 1);
    isSaved(vac, pac, n);
    return 0;
}