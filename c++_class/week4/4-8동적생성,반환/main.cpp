#include <iostream>
using namespace std;
#include "Circle.h"

int main() {
    int radius;
    Circle *p;
    while(true){
        cout << "정수 반지름 입력(음수면 종료합니다)>> ";
        cin >> radius;
        if(radius < 0) break;
        p = new Circle(radius);
        cout << "원의 면적은 " << p -> getArea() << endl;
        delete p;
    }
}
