#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int iteracoes_bubbleSort(vector<int> & vet, int n){
    int count = 0;
    bool swapped = true;

    while(swapped != false){
        swapped = false;
        count++;
        for(int i = 0; i < n - 1; i++){
            if(vet[i] > vet[i + 1]){
                swap(vet[i], vet[i + 1]);
                swapped = true;
            }
        }
    }
    return count;
}

string showVector(vector<int> & vet, int n){
    string line;
    stringstream ss;
    for(int i = 0; i < n; i++){
        ss << vet[i] << " ";
    }
    line = ss.str();
    return line;
}

int main(){
    vector<int> vet;
    int n, value;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> value;
        vet.push_back(value);
    }
    cout << iteracoes_bubbleSort(vet, n) << endl;
    cout << showVector(vet, n);
    return 0;
}