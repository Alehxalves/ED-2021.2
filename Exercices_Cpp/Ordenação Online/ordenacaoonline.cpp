#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> & vet, int start, int mid, int end){
    vector<int> W;
    W.resize(end - start + 1);

    int i = start;
    int j = mid + 1;
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

int main(){
    vector<int> vet;
    int n, op, value;
    int size;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> op >> value;
        if(op == 1){
            vet.push_back(value);
            size = vet.size();
            if(n > 1){
                merge(vet, 0, (size / 2), size - 1);
                mergesort(vet, 0 , size - 1);
            }
        }
        else if(op == 2){
            cout << vet[value] << endl;
        }
    }
    return 0;
}