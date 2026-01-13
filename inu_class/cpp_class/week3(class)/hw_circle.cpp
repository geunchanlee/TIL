#include <iostream>
using namespace std;

class Circle{ 
private:
    int radius;
public:
    Circle();
    Circle(int r);
    ~Circle(); 
    double getArea();
    int getRadius();
    void setRadius(int r);
};

Circle::Circle(){
    radius = 1;
}

Circle::Circle(int r){
    radius = r;
}

Circle::~Circle() {
}

double Circle::getArea(){
    return 3.14 * radius * radius;
}

int Circle::getRadius(){
    return radius;
}

void Circle::setRadius(int r){
    radius = r;
}


int main(){
    Circle donut;
    cout << "donut의 " << "현재 반지름은 " << donut.getRadius() << " 면적은 " << donut.getArea() << " 입니다." << endl;
    Circle pizza(30);
    cout << "pizza의 " << "현재 반지름은 " << pizza.getRadius() << " 면적은 " << pizza.getArea() << " 입니다." << endl;
    cout << endl;
    cout << "donut과 pizza의 반지름을 각각 5, 10으로 변경" << endl;
    donut.setRadius(5);
    pizza.setRadius(10);
    cout << endl;
    cout << "donut의 " << "현재 반지름은 " << donut.getRadius() << " 면적은 " << donut.getArea() << " 입니다." << endl;
    cout << "pizza의 " << "현재 반지름은 " << pizza.getRadius() << " 면적은 " << pizza.getArea() << " 입니다." <<endl;



    return 0;
}