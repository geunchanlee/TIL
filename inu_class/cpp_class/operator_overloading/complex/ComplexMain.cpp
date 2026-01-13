#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
    double x, y;
    cout << "복소수 a: ";
    cin >> x >> y;
    Complex a(x, y);
    
    cout << "복소수 b: ";
    cin >> x >> y;
    Complex b(x, y);
    
    cout << "복소수 a= "; a.complexPrint(); cout << ", 복소수 b= "; b.complexPrint(); cout << '\n';
    cout << "-----------------------------------------" << endl;
    Complex c;
    cout << "복소수 사칙연산 출력" << endl;
    c = a+b;
    cout << "a+b= "; c.complexPrint(); cout << '\n';
    c = a-b;
    cout << "a-b= "; c.complexPrint(); cout << '\n';
    c = a*b;
    cout << "a*b= "; c.complexPrint(); cout << '\n';
    c = a/b;
    cout << "a/b= "; c.complexPrint(); cout << '\n';
    
    cout << "----------------------------------------" << endl;
    a+=b;
    cout << "a+=b| a= "; a.complexPrint(); cout << '\n';
    a-=b;
    cout << "a-=b| a= "; a.complexPrint(); cout << '\n';
    a*=b;
    cout << "a*=b| a= "; a.complexPrint(); cout << '\n';
    a/=b;
    cout << "a/=b| a= "; a.complexPrint(); cout << '\n';
    
    return 0;
}
