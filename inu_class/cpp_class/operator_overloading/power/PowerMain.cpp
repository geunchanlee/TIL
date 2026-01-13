#include <iostream>

using namespace std;
# include "Power.h"

int main() {
    Power a(3, 5), b(4, 6), c;
    
    cout << "\n" << "+ 연산자" << endl;
    c = a+b; // (3, 5) + (4, 6)
    c.show();
    c = a+2; // (3, 5) + 2
    c.show();
    c = 5+a; // 5 + (3, 5)
    c.show();
    
    cout << "\n" << "- 연산자" << endl;
    c = a-b; // (3, 5) - (4, 6)
    c.show();
    c = a-2; // (3, 5) - 2
    c.show();
    c = 5-a; // 5 - (3, 5)
    c.show();

    cout << "\n" << "+=, -= 연산자" << endl;
    c+=a; // (2, 0) += (3, 5)
    c.show();
    c+=15; // (5, 5) += 15
    c.show();
    c-=a; // (20, 20) -= (3, 5)
    c.show();
    c-=10; // (17, 15) -= 10
    c.show();
    
    cout << "\n" << "==, != 연산자" << endl;
    cout << "a == c" << endl; // a==c일 때 true
    cout << boolalpha << (a==c) << endl;
    cout << "a != c" << endl; // a!=c 일 때 true
    cout << boolalpha << (a!=c) << endl;
    
    cout << "\n" << "++ 연산자" << endl;
    c = ++a; // c = ++(3, 5)
    c.show();
    c = b++; // c = (4, 6)++
    c.show();
    b.show();
    
    cout << "\n" << "--연산자" << endl;
    c = --a; // c = --(3, 5)
    c.show();
    c = b--; // c = (4, 6)--
    c.show();
    b.show();
    
    cout << "\n" << "! 연산자" << endl; // !a a의 kick, punch가 0이면 true
    cout << boolalpha << (!a) <<endl;
    
    cout << "\n" << "<< 연산자" << endl;
    a << 3 << 5; // (3, 5) + 3 + 5
    a.show();
    
    return 0;
}
