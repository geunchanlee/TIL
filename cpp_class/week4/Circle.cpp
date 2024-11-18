#include <iostream>
using namespace std;

#include "Circle.h" // 헤더 

// 클래스 구현부 파일

Circle::Circle(){
    radius = 1;
    cout << "반지름 " << radius;
    cout << " 원 생성" << endl;
}

Circle::Circle(int r){
    radius = r;
    cout << "반지름 " << radius;
    cout << " 원 생성" << endl;
}

double Circle::getArea(){
    return 3.14 * radius * radius;
}