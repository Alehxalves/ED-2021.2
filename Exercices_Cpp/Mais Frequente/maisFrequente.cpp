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

void repetidos(vector<int> & vet, int * freq, int n){
    int count = 0, aux = 0;
    for (int i = 0; i < n; i++){

        if (vet[i] == vet[i + 1]) {
            count++;
        }else{
            if(count > aux){
                aux = count + 1; // O +1 é para somar o proprio numero que está sendo verificado se à repetidos. ex: 1 1 1 = 3 repetidos
                freq[0] = vet[i];
                freq[1] = aux; 
                count = 0;
            }else  
                count = 0;  
        }
    }
}

void printVector(int * freq, int n){
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << freq[i] << endl;
            break;
        }
        cout << freq[i] << " ";
    }
}   

int main(){
    vector<int> vet;
    int freq[2];
    
    int n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        vet.push_back(value);
    }
    quickSort(vet, 0,  n - 1);
    repetidos(vet, freq, n - 1);
    printVector(freq, 2);
    return 0;
}