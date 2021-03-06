#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void merge(vector<int> & vet, int start, int mid, int end){
    vector<int> W;
    W.resize(end - start + 1);

    int i = start;
    int j = mid+1;
    int k = 0;

    while(i <= mid && j <= end){
        if(vet[i] < vet[j]){
            W[k] = vet[i], k++, i++;
        }else{
            W[k] = vet[j], k++, j++;
        }
    }

    while(i <= mid) W[k] = vet[i], k++, i++;
    while(j <= end) W[k] = vet[j], k++, j++;

    for(int i = start; i <= end; i++){
        vet[i] = W[i - start];
    }
}

void mergesort(vector <int> & vet, int start, int end){
    if(end > start){
        int mid = (start + end) / 2;
        mergesort(vet, start, mid);
        mergesort(vet, mid + 1, end);
        merge(vet, start, mid, end);    
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
    // Coleção de bruno
    merge(colec_bruno, 0, (n / 2) - 1, n - 1);
    mergesort(colec_bruno, 0 , n - 1);
    // Coleção de getúlio
    merge(colec_getulio, 0, (n / 2) - 1, n - 1);
    mergesort(colec_getulio, 0 , n - 1);

    cout << compara_figurinhas(colec_bruno, colec_getulio) << endl;
    return 0;
}