#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int separa(vector<int> & vet, vector<int> & indic, int low, int high){
    int pivot = vet[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(vet[j] <= pivot){
            swap(vet[i], vet[j]);
            swap(indic[i], indic[j]);
            i++;
        }
    }
    swap(vet[i], vet[high]);
    swap(indic[i], indic[high]);
    return i;
}

void quickSort(vector<int> & vet, vector<int> & indic, int low, int high){
    if(low < high){
        int pi = separa(vet, indic, low, high);

        quickSort(vet, indic, low, pi - 1);
        quickSort(vet, indic, pi + 1, high);
    }
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

int main(){
    vector<int> vet, indic;
    
    int n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        vet.push_back(value);
        indic.push_back(i);
    }
    quickSort(vet, indic, 0,  n - 1);
    printVector(indic, n);
    return 0;
}