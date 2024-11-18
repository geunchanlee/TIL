#include <iostream>
#include "Fraction.h"
using namespace std;

// 분수 약분에 사용할 최대공약수를 찾는 gcd 함수
// 유클리드 호제법을 사용해서 최대공약수를 찾습니다.
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

Fraction::Fraction(int numerator, int denominator) {
    // 최대공약수로 분자, 분모를 나누어 약분합니다
    int num = gcd(numerator, denominator);
    this->numerator = numerator / num;
    this->denominator = denominator / num;
    
    // 뺄셈 연산 등에서 분모가 -가 되는 경우 음수를 분자로 옮겨 처리해줍니다.
    if (this->denominator < 0) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }
}
    
void Fraction::printFraction() {
    cout << numerator << '/' << denominator;
}

void Fraction::printResult() {
    cout << double(numerator) / double(denominator);
}

// + 연산자 함수 3개
Fraction Fraction::operator+(Fraction op2){
    int n = (this->numerator * op2.denominator) + (op2.numerator * this->denominator);
    int d = this->denominator * op2.denominator;
    Fraction tmp(n, d);
    return tmp;
}

Fraction Fraction::operator+(int op2){
    int n = this->numerator + (op2 * this->denominator);
    int d = this->denominator;
    Fraction tmp(n, d);
    return tmp;
}

// 외부함수로 작성해 프렌드 선언해 2+x같은 연산을 실행합니다.
Fraction operator+ (int op1, Fraction op2) {
    int n = (op1 * op2.denominator) + op2.numerator;
    int d = op2.denominator ;
    Fraction tmp(n, d);
    return tmp;
}

// - 연산자 함수 3개
Fraction Fraction::operator-(Fraction op2) {
    int n = (this->numerator * op2.denominator) - (op2.numerator * this->denominator);
    int d = this->denominator * op2.denominator;
    Fraction tmp(n, d);
    return tmp;
}

Fraction Fraction::operator-(int op2) {
    int n = this->numerator - (op2 * this->denominator);
    int d = this->denominator;
    Fraction tmp(n, d);
    return tmp;
}

Fraction operator-(int op1, Fraction op2) {
    int n = (op1 * op2.denominator) - op2.numerator;
    int d = op2.denominator;
    Fraction tmp(n, d);
    return tmp;
}

// * 연산자 함수 3개
Fraction Fraction::operator*(Fraction op2) {
    int n = this->numerator * op2.numerator;
    int d = this->denominator * op2.denominator;
    Fraction tmp(n, d);
    return tmp;
}

Fraction Fraction::operator*(int op2) {
    int n = this->numerator * op2;
    int d = this->denominator;
    Fraction tmp(n, d);
    return tmp;
}

Fraction operator*(int op1, Fraction op2) {
    int n = op1 * op2.numerator;
    int d = op2.denominator;
    Fraction tmp(n, d);
    return tmp;
}

// /연산자 함수 3개
Fraction Fraction::operator/(Fraction op2) {
    int n = this->numerator * op2.denominator;
    int d = this->denominator * op2.numerator;
    Fraction tmp(n, d);
    return tmp;
}

Fraction Fraction::operator/(int op2) {
    int n = this->numerator;
    int d = this->denominator * op2;
    Fraction tmp(n, d);
    return tmp;
}

Fraction operator/(int op1, Fraction op2) {
    int n = op1 * op2.denominator;
    int d = op2.numerator;
    Fraction tmp(n, d);
    return tmp;
}

bool Fraction::operator==(Fraction op2) {
    return (this->numerator == op2.numerator && this->denominator == op2.denominator);
}

// += 연산자 중복 함수입니다.
Fraction& Fraction::operator+=(Fraction op2) {
    
    // + 연산을 수행한 값을 생성자에서 사용한 약분 방법으로 약분해서 넣어줍니다.
    
    int n = (this->numerator * op2.denominator) + (op2.numerator * this->denominator);
    int d = this->denominator * op2.denominator;
    
    // 최대공약수를 사용해 약분해줍니다.
    int gcdN = gcd(n, d);
    n /= gcdN;
    d /= gcdN;
    
    // 분모가 0 인경우에 대해 처리하는 부분입니다.
    if (d < 0) {
        n = -n;
        d = -d;
    }
    
    this->numerator = n;
    this->denominator = d;
    
    return *this;
}
