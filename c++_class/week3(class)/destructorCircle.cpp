#include <iostream>
using namespace std;

/*  소멸자(Destructor)는 객체가 소멸되는 시점에 자동으로 호출되는 함수이다.
    소멸자 함수는 클래스 이름 앞에 ~를 붙인다.
    소멸자는 리턴타입이 없으며 중복이 불가능해 한 클래스에 한 개만 작성할 수 있다.
    소멸자가 선언되어 있지 않으면 기본 소멸자가 컴파일러에 의해 자동으로 생성된다.
    함수 안에서 선언된 지역 객체는 함수가 종료할때 소멸된다. 함수 바깥쪽에서 선언된 전역 개체는 프로그램 종료시 소멸된다. */



class Circle{ 
public:
    int radius;

    Circle();
    Circle(int r);
    ~Circle(); 
    double getArea();
};

Circle::Circle(){
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r){
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() {
    cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle::getArea(){
    return 3.14 * radius * radius;
}

/* 프로그램 실행 결과
    >> 반지름 1 원 생성
    >> 반지름 30 원 생성
    >> 반지름 30 원 소멸
    >> 반지름 1 원 소멸 
    객체가 생성된 반대 순서로 소멸된다.  */

int main(){
    Circle donut;
    Circle pizza(30);

    return 0;
}

