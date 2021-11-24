#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void bubbleSort(vector<int> & vet, int n){
    bool swapped = true;
    while(swapped != false){
        swapped = false;
        for(int i = 0; i < n - 1; i++){
            if(vet[i] > vet[i + 1]){
                swap(vet[i], vet[i + 1]);
                swapped = true;
            }
        }
    }
}

int repetidos(vector<int> & vet, int n){
    int count = 0;
    for (int i = 0; i < n - 1; i++){
        if (vet[i] == vet[i + 1]) {
            count = count + 1;
        }
    }
    return count;
}

int main(){
    vector<int> vet;
    int count, n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        vet.push_back(value);
    }
    bubbleSort(vet, n);
    count = repetidos(vet, n);
    cout << count << endl;
    return 0;
}