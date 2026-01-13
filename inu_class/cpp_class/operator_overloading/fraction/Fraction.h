#ifndef Fraction_h
#define Fraction_h

class Fraction {
private:
    int numerator;
    int denominator;
public:
    // 디폴트 매개변수를 선언해 값이 입력되지 않으면 1로 설정
    Fraction(int numerator = 1, int denominator = 1);
    void printFraction();
    void printResult();
    
    // + 연산자 중복
    Fraction operator+(Fraction op2);
    Fraction operator+(int op2);
    friend Fraction operator+(int op1, Fraction op2);
    
    // - 연산자 중복
    Fraction operator-(Fraction op2);
    Fraction operator-(int op2);
    friend Fraction operator-(int op1, Fraction op2);
    
    // * 연산자 중복
    Fraction operator*(Fraction op2);
    Fraction operator*(int op2);
    friend Fraction operator*(int op1, Fraction op2);
    
    // / 연산자 중복
    Fraction operator/(Fraction op2);
    Fraction operator/(int op2);
    friend Fraction operator/(int op1, Fraction op2);
    
    // ==, += 연산자 함수
    bool operator==(Fraction op2);
    Fraction& operator+=(Fraction op2);
    
};

#endif
