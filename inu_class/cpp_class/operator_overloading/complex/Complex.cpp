#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

// 복소수 출력 함수
// 허수부가 음수인 경우를 처리해서 1+-2i 같은 출력을 방지했습니다.
void Complex::complexPrint() {
    if (imag >= 0) {
        cout << real << "+" << imag << "i";
    } else {
        cout << real << imag << "i";
    }
}

// + 연산자 중복
Complex Complex::operator+(Complex op2) {
    Complex tmp;
    tmp.real = this->real + op2.real;
    tmp.imag = this->imag + op2.imag;
    return tmp;
}

Complex Complex::operator+(double op2) {
    Complex tmp;
    tmp.real = this->real + op2;
    tmp.imag = this->imag;
    return tmp;
}

Complex operator+(double op1, Complex op2) {
    Complex tmp;
    tmp.real = op1 + op2.real;
    tmp.imag = op2.imag;
    return tmp;
}

// - 연산자 중복
Complex Complex::operator-(Complex op2) {
    Complex tmp;
    tmp.real = this->real - op2.real;
    tmp.imag = this->imag - op2.imag;
    return tmp;
}

Complex Complex::operator-(double op2) {
    Complex tmp;
    tmp.real = this->real - op2;
    tmp.imag = this->imag;
    return tmp;
}

Complex operator-(double op1, Complex op2) {
    Complex tmp;
    tmp.real = op1 - op2.real;
    tmp.imag = op2.imag;
    return tmp;
}

// * 연산자 중복
Complex Complex::operator*(Complex op2) {
    Complex tmp;
    tmp.real = (this->real * op2.real) - (this->imag * op2.imag);
    tmp.imag = (this->real * op2.imag) + (this->imag * op2.real);
    return tmp;
}

Complex Complex::operator*(double op2) {
    Complex tmp;
    tmp.real = this->real * op2;
    tmp.imag = this->imag * op2;
    return tmp;
}

Complex operator*(double op1, Complex op2) {
    Complex tmp;
    tmp.real = op1 * op2.real;
    tmp.imag = op1 * op2.imag;
    return tmp;
}

// /연산자 중복
Complex Complex::operator/(Complex op2) {
    Complex tmp;
    tmp.real = (this->real * op2.real + this->imag * op2.imag) / (op2.real*op2.real + op2.imag*op2.imag);
    tmp.imag = (this->imag * op2.real - this->real * op2.imag) / (op2.real*op2.real + op2.imag*op2.imag);
    return tmp;
}

Complex Complex::operator/(double op2) {
    Complex tmp;
    tmp.real = this->real * op2 /(op2 * op2);
    tmp.imag = this->imag * op2 / (op2 * op2);
    return tmp;
}

Complex operator/(double op1, Complex op2) {
    Complex tmp;
    tmp.real = op1 * op2.real / (op2.real * op2.real + op2.imag * op2.imag);
    tmp.imag = -op1 * op2.imag / (op2.real * op2.real + op2.imag * op2.imag);
    return tmp;
}

// +=, -=, *=, /= 연산자 중복
Complex& Complex::operator+=(Complex op2) {
    this->real += op2.real;
    this->imag += op2.imag;
    return *this;
}

Complex& Complex::operator-=(Complex op2) {
    this->real -= op2.real;
    this->imag -= op2.imag;
    return *this;
}

Complex& Complex::operator*=(Complex op2) {
    double r = this->real;
    double i = this->imag;
    this->real = (r * op2.real) - (i * op2.imag);
    this->imag = (r* op2.imag) + (i * op2.real);
    return *this;
}

Complex& Complex::operator/=(Complex op2) {
    double r = this->real;
    double i = this->imag;
    this->real = (r * op2.real + i * op2.imag) / (op2.real * op2.real + op2.imag * op2.imag);
    this->imag = (i * op2.real - r * op2.imag) / (op2.real*op2.real + op2.imag*op2.imag);
    return *this;
}

