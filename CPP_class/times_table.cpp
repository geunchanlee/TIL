#include <iostream>
using namespace std;

// 9.5 c++ class <week1>

int main() {
    for(int i=2; i<10; i++){
        for(int j=1; j<9; j++){
            cout << i << '*' << j << '=' << i*j << ',' << '\t';
        }
        cout << i << '*' << 9 << '=' << i*9 << '\n';
    }
    cout << "-----------------------------\n";
    for(int i=1; i<10; i++){
        for(int j=2; j<9; j++){
            cout << j << '*' << i << '=' << j*i << ',' << '\t';
        }
        cout << 9 << '*' << i << '=' << 9*i  << '\n';
    }
    return 0;
}