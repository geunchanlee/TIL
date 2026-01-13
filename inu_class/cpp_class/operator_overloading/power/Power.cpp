#include <iostream>
#include "Power.h"

using namespace std;

void Power::show() {
    cout << "kick=" << kick << "," << "punch=" << punch << endl;
}

Power Power::operator+(Power op2) {
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

Power Power::operator+(int op2) {
    Power tmp;
    tmp.kick = kick + op2;
    tmp.punch = punch + op2;
    return tmp;
}

// 2+a 같은 연산을 위해 외부함수로 작성해 프렌드 선언
// 외부함수이기 때문에 프렌드 선언을 해줘야 private 변수에 접근가능
Power operator+ (int op1, Power op2) {
    Power tmp;
    tmp.kick = op1 + op2.kick;
    tmp.punch = op1 + op2.punch;
    return tmp;
}

Power Power::operator-(Power op2) {
    Power tmp;
    tmp.kick = this->kick - op2.kick;
    tmp.punch = this->punch - op2.punch;
    return tmp;
}

Power Power::operator-(int op2) {
    Power tmp;
    tmp.kick = kick - op2;
    tmp.punch = punch - op2;
    return tmp;
}

// 2-a 같은 연산을 위해 외부함수로 작성해 프렌드 선언
// 외부함수이기 때문에 프렌드 선언을 해줘야 private 변수에 접근가능
Power operator-(int op1, Power op2) {
    Power tmp;
    tmp.kick = op1 - op2.kick;
    tmp.punch = op1 - op2.punch;
    return tmp;
}

// +=, -=는 참조 리턴
Power& Power::operator+=(Power op2) {
    kick = kick + op2.kick;
    punch = punch + op2.punch;
    return *this;
}

Power& Power::operator+=(int op2) {
    kick = kick + op2;
    punch = punch + op2;
    return *this;
}

Power& Power::operator-=(Power op2) {
    kick = kick - op2.kick;
    punch = punch - op2.punch;
    return *this;
}

Power& Power::operator-=(int op2) {
    kick = kick - op2;
    punch = punch - op2;
    return *this;
}

bool Power::operator==(Power op2) {
    if(kick==op2.kick && punch==op2.punch)
        return true;
    else
        return false;
}

bool Power::operator!=(Power op2) {
    if(kick!=op2.kick || punch!=op2.punch)
        return true;
    else
        return false;
}

Power& Power:: operator++ () {
    kick++;
    punch++;
    return *this;
}

Power Power::operator++(int x) {
    Power tmp = *this;
    kick++;
    punch++;
    return tmp;
}

Power& Power:: operator--() {
    kick--;
    punch--;
    return *this;
}

Power Power::operator--(int x) {
    Power tmp = *this;
    kick--;
    punch--;
    return tmp;
}

bool Power::operator!() {
    if(kick == 0 && punch == 0) return true;
    else return false;
}

Power& Power::operator<<(int n) {
    kick += n;
    punch += n;
    return *this;
}
