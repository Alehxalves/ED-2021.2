#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using std::rotate;

void right_rotation(vector<int>& vet, int nrot){
    if(nrot == 0 || nrot == vet.size()){
        return;
    }
    else if(nrot > vet.size()){
        while(nrot > vet.size()){ 
            nrot-= vet.size();
        }
    }
    rotate(vet.rbegin(), vet.rbegin() + nrot, vet.rend());
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}

