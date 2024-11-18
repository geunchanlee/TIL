#ifndef Power_H
#define Power_H
using namespace std;

class Power {
private:
    int kick;
    int punch;
public:
    Power(int kick=0, int punch=0){
        this->kick = kick;
        this->punch = punch;
    }
    void show();
    // + 연산자 함수 3개
    Power operator+(Power op2);
    Power operator+(int op2);
    friend Power operator+(int op1, Power op2); // 외부함수 프렌드 선언
    
    // - 연산자 함수 3개
    Power operator-(Power op2);
    Power operator-(int op2);
    friend Power operator-(int op1, Power op2); // 외부함수 프렌드 선언
    
    // +=, -= 함수
    Power& operator+=(Power op2);
    Power& operator+=(int op2);
    Power& operator-=(Power op2);
    Power& operator-=(int op2);
    
    // ==, !=, ! 함수
    bool operator==(Power op2);
    bool operator!=(Power op2);
    bool operator!();
    
    // 전위 연산자, 후위 연산자 함수
    Power& operator++();
    Power operator++(int x);
    Power& operator--();
    Power operator--(int x);
    
    // 참조리턴 << 함수
    Power& operator<<(int n);
};

#endif
