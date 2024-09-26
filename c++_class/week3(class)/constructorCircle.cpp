#include <iostream>
using namespace std;

/*  생성자(Constructor)를 통해 객체 생성시 초기화를 할 수 있다.
    클래스 이름과 동일하게 생성하고 리턴타입을 선언하지 않는다.
    객채 생성시 한 번 자동으로 호출된다.
    한 클래스에 여러 개의 생성자를 만들 수 있다.
    생성자가 하나도 선언되지 않았을 때는 매개변수 없는 기본 생성자를 컴파일러가 자동 생성한다.
    개발자가 하나라도 생성자를 만든 경우 기본 생성자를 만들어주지 않는다. */

class Circle{ 
public:
    int radius;
    Circle(); // 생성자
    Circle(int r); // 생성자
    double getArea();
};

// 매개변수 없는 생성자
Circle::Circle(){
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

// 매개변수 r을 갖는 생성자
Circle::Circle(int r){
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea(){
    return 3.14 * radius * radius;
}

// 매개변수 없는 생성자와 있는 생성자 각각 호출
int main(){
    Circle donut;
    double area = donut.getArea();
    cout << "donut의 면적은 " << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza의 면적은 " << area << endl;
}