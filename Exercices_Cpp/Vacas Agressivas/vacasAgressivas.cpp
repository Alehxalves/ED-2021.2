#include <iostream>
#include <vector>

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

int pico(vector <int> & vet, int low, int high){
    if(high - low == 0){
        return low;
    }else if(high - low == 1){
        if(vet[low] > vet[high]) 
            return low;
        else 
            return high;
    }else{
        int mid = (low + high) / 2;
        if((vet[mid] > vet[mid - 1]) && (vet[mid] > vet[mid + 1])) 
            return mid;
        if(vet[mid - 1] < vet[mid]){
            if(vet[mid] > vet[mid + 1]) 
                return mid;
            else
                return pico(vet, mid + 1, high);
        }else 
            return pico(vet, low, mid - 1);  
    }
}

int busca_binaria(vector<int> & vet, int size, int item){
    int inicio = 0; 
    int fim = size - 1; 
    int contador = 0;
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        contador = contador + 1;
        if(vet[meio] == item){
          return contador;          
        }else{
            if(vet[meio] > item)
                fim = meio - 1;
            else
                inicio = meio + 1;
        }
    }
    return -1;
}

bool verificarDist(vector<int> & baias, int vacas, int dist, int nPico){
    int busca = 0;
    for(int i = 1; i <= nPico; i += dist){
        while(true){
            busca = busca_binaria(baias, baias.size(), i);
            if(busca != -1){
                vacas--;
                break;
            }
            else i++;
        }
        if(vacas == 0) return false; // Se não sobrar vacas retornar para verificar uma distância maior.
    }
    return true; // True caso tenha sobrado vacas a ser colocadas, então a (distancia - 1) será a máxima distância mínima.
}

int maxDistMin(vector<int> & baias, int vacas, int size){
    if(vacas == 1) 
        return baias[pico(baias, 0, baias.size() - 1)];
    else if(vacas == 0) 
        return 0;
    int nPico = baias[pico(baias, 0, baias.size() - 1)];
    int dist = size / vacas;
    while(true){
        bool sobrouVaca = verificarDist(baias, vacas, dist, nPico);
        if(!sobrouVaca) dist++;
        else{
            dist--;
            break;
        }
    }
    return dist;
}

int main(){
    vector<int> baias;
    int n_baias, vacas, value;
    
    cin >> n_baias >> vacas;
    for(int i = 0; i < n_baias; i++){
        cin >> value;
        baias.push_back(value);
    }
    quickSort(baias, 0, n_baias);
    int dist = maxDistMin(baias, vacas, n_baias);
    cout << dist << endl;
}