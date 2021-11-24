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

int compara_figurinhas(vector<int> & colec1, vector<int> & colec2){
    if(colec1 == colec2)
        return 1;
    else    
        return 0;
}

int main(){
    vector<int> colec_bruno, colec_getulio;
    int n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        colec_bruno.push_back(value);
    }
    for(int i = 0; i < n; i++){
        cin >> value;
        colec_getulio.push_back(value);
    }
    quickSort(colec_bruno, 0,  n - 1);
    quickSort(colec_getulio, 0,  n - 1);
    cout << compara_figurinhas(colec_bruno, colec_getulio) << endl;
    return 0;
}