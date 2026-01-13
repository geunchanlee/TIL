#include <iostream>
using namespace std;

// Circle 선언부 -> 구조체와 연관있어서 끝날 땐 세미콜론;으로 끝내야 한다.
class Circle{ 
public:
    int radius;
    double getArea();
};

// Circle 구현부
double Circle::getArea(){
    return 3.14 * radius * radius;
}

int main(){
    // 객체 생성하고 멤버변수(radius) 접근, 멤버함수(getArea) 호출
    Circle donut;
    donut.radius = 1;
    double area = donut.getArea();
    cout << "donut의 면적은 " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea();
    cout << "pizza의 면적은 " << area << endl;
}