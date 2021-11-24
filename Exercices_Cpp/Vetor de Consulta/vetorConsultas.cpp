#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> total_consultas(vector<string> & vet_consulta, vector<string> & vet_busca, int size_consulta, int size_busca){
    vector<int> int_busca;
    int totalBusca;
    for(int i = 0; i < size_busca; i++){
        totalBusca = 0;
        for(int j = 0; j < size_consulta; j++){
            if(vet_busca[i] == vet_consulta[j]){
                totalBusca++;
            }
        }
        int_busca.push_back(totalBusca);
    }
    return int_busca;
}

void showVector(vector<int> & vet, int n){
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << vet[i] << endl;
            break;
        }
        cout << vet[i] << " ";
    }
}

int main(){
    vector<string> vet_consulta, vet_busca;
    vector<int> totalConsultas;
    int size_consulta, size_busca;
    string line;
    cin >> size_consulta;
    // Vetor consulta;
    for(int i = 0; i < size_consulta; i++){
        cin >> line;
        vet_consulta.push_back(line);
    }
    cin >> size_busca;
    // Vetor de busca;
    for(int i = 0; i < size_busca; i++){
        cin >> line;
        vet_busca.push_back(line);
    }
    totalConsultas = total_consultas(vet_consulta, vet_busca, size_consulta, size_busca);
    cout << "I";
    showVector(totalConsultas, totalConsultas.size());
}