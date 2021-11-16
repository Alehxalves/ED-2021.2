#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
    char c;
    int a_size, b_size;

    cin >> a >> b;
    a_size = a.size();
    b_size = b.size();
    cout << a_size << " " << b_size << endl; 
    cout << a + b << endl;
    c = a[0];
    a[0] = b[0];
    b[0] = c;
    cout << a << " " << b << endl;
  
    return 0;
}