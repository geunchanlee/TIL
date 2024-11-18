#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    int numerator, denominator;
    cout << "분수1(분자 분모) 입력: ";
    cin >> numerator >> denominator;
    Fraction x(numerator, denominator);
    if (denominator <= 0) {
        cerr << "분모가 0보다 커야합니다." << endl;
        return 1;
    }
    
    cout << "분수1(분자 분모) 입력: ";
    cin >> numerator >> denominator;
    Fraction y(numerator, denominator);
    if (denominator <= 0) {
        cerr << "분모가 0보다 커야합니다." << endl;
        return 1;
    }
    int num;
    cout << "정수 입력: "; cin >> num;
    
    Fraction z;
    
    cout << "--------------------------------------------------" << endl;
    cout << "객체 연산자 객체 = 연산수행 (실행결과)" << endl;
    z = x+y;
    cout << '('; x.printFraction(); cout << ")+("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = x-y;
    cout << '('; x.printFraction(); cout << ")-("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = x*y;
    cout << '('; x.printFraction(); cout << ")*("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = x/y;
    cout << '('; x.printFraction(); cout << ")/("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    
    cout << "--------------------------------------------------" << endl;
    cout << "객체 연산자 객체 = 연산수행 (실행결과)" << endl;
    z = x+num;
    cout << '('; x.printFraction(); cout << ")+" << num;
    cout << "=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = x-num;
    cout << '('; x.printFraction(); cout << ")-" << num;
    cout << "=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = x*num;
    cout << '('; x.printFraction(); cout << ")*" << num;
    cout << "=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = x/num;
    cout << '('; x.printFraction(); cout << ")/" << num;
    cout << "=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    
    cout << "--------------------------------------------------" << endl;
    cout << "객체 연산자 객체 = 연산수행 (실행결과)" << endl;
    z = num+y;
    cout << num << "+("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = num-y;
    cout << num << "-("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = num*y;
    cout << num << "*("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;
    z = num/y;
    cout << num << "/("; y.printFraction();
    cout << ")=("; z.printFraction(); cout << ") ("; z.printResult(); cout << ")" << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "객체 연산자 객체 = 연산수행 (실행결과)" << endl;
    cout << '('; x.printFraction(); cout << ")==("; y.printFraction();
    cout << ")=" << boolalpha << (x==y) << endl;
    
    cout << '('; x.printFraction(); cout << ")+=("; y.printFraction();
    cout << ")=("; x+=y ;x.printFraction(); cout << ") ("; x.printResult(); cout << ")" << endl;
}
