#ifndef Complex_h
#define Complex_h

class Complex {
private:
    double real;
    double imag;
public:
    // 디폴트 매개변수로 0으로 설정
    Complex(double real = 0, double imag = 0);
    
    void complexPrint();
    
    Complex operator+(Complex op2);
    Complex operator+(double op2);
    friend Complex operator+(double op1, Complex op2);
    
    Complex operator-(Complex op2);
    Complex operator-(double op2);
    friend Complex operator-(double op1, Complex op2);
    
    Complex operator*(Complex op2);
    Complex operator*(double op2);
    friend Complex operator*(double op1, Complex op2);
    
    
    Complex operator/(Complex op2);
    Complex operator/(double op2);
    friend Complex operator/(double op1, Complex op2);
    
    Complex& operator+=(Complex op2);
    Complex& operator-=(Complex op2);
    Complex& operator*=(Complex op2);
    Complex& operator/=(Complex op2);
    
};

#endif
