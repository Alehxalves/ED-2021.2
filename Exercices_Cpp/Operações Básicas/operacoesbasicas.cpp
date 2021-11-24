#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string showVector(vector<int> vec, int n){
    stringstream ss;
    string line;
    for(int i = 0; i < n; i++)
        ss << vec[i] << " ";
    line = ss.str();
    return line;
}

vector<int> rVet(vector<int> vec, int n, int i){
    if(n == 1) return vec;
    else{
        n--;
        int aux = vec[i];
        vec[i] = vec[n];
        vec[n] = aux;
        i++;
        if(i < n) return rVet(vec, n, i);
    }
    return vec;
}

int sumVec(vector<int> vec, int n, int i){
    int sum;
    if(n == 1) return vec[0]; 
    else{
        sum += vec[i];
        i++;
        if(i < n)
            sum += sumVec(vec, n, i);
    }
    return sum;
}

int multVec(vector<int> vec, int n, int i){
    int mult = 1;
    if(n == 1) return vec[0]; 
    else{
        mult = mult * vec[i];
        i++;
        if(i < n)
            mult *= multVec(vec, n, i);
    }
    return mult;
}

int minVec(vector<int> vec, int n, int i){
    int min = *min_element(vec.begin(), vec.end());
    return min;
}
int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value){
        vet.push_back(value);
    }
    int n = vet.size();
    cout << "vet : [ " << showVector(vet, n) << "]" <<endl;
    cout << "rvet: [ " << showVector(rVet(vet, n, 0), n) << "]" << endl;
    cout << "sum : " << sumVec(vet, n, 0) << endl;
    cout << "mult: " << multVec(vet, n, 0) << endl;
    cout << "min : " << minVec(vet, n, 0) << endl;
    cout << "inv : [ " << showVector(rVet(vet, n, 0), n) << "]" << endl;
}