#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product{
    private:
    string name;
    int price;

    public:
    Product(string n, int p) {
        name = n;
        price = p;
    }

    bool operator<(const Product & a){
        if( price != a.price){
            return price < a.price;
        }else{
            return name < a.name;
        }
    }
    friend ostream & operator<<(ostream & os, const Product & p);

    string getName(){
        return name;
    }
    int getPrice(){
        return price;
    }
};

ostream & operator<<(ostream & os, const Product & p){
    os << "(" << p.name << "," << p.price << ")";
    return os;
} 

void printvet(vector<Product> vet, int n){
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << vet[i].getName() << endl;
            break;
        }
        cout << vet[i].getName() << " ";
    }
}

void produtosEscolhidos(vector<Product> & produtos_secao1, vector<Product> & produtos_secao2, int p, int q){
    vector<Product> escolhidos;

    //Seção 1
    for(int i = 0; i < p; i++){
        escolhidos.push_back(Product(produtos_secao1[i].getName(), produtos_secao1[i].getPrice()));
    }
    //Seção 2
    for(int i = 0; i < q; i++){
        escolhidos.push_back(Product(produtos_secao2[i].getName(), produtos_secao2[i].getPrice()));
    }
    sort(escolhidos.begin(), escolhidos.end());
    printvet(escolhidos, escolhidos.size());
}

int main(){
    vector<Product> produtos_secao1;
    vector<Product> produtos_secao2;

    int n, m, p, q;
    string name;
    int price;

    cin >> n >> m >> p >> q;
    for(int i = 0; i < n; i++){
        cin >> name;
        cin >> price;
        produtos_secao1.push_back(Product(name, price));
    }

    for(int i = 0; i < m; i++){
        cin >> name;
        cin >> price;
        produtos_secao2.push_back(Product(name, price));
    }

    sort(produtos_secao1.begin(), produtos_secao1.end());
    sort(produtos_secao2.begin(), produtos_secao2.end());
    
    produtosEscolhidos(produtos_secao1, produtos_secao2, p, q);

    return 0;
}