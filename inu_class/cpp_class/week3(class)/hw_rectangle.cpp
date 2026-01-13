#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;
public:
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int length);
    ~Rectangle();
    int getArea();
    int getWidth();
    int getHeight();
    void setWidth(int w);
    void setHeight(int h);  
};

Rectangle::Rectangle(){
    width = 1;
    height = 1;
}

Rectangle::Rectangle(int w, int h){
    width = w;
    height = h;
}

Rectangle::Rectangle(int length){
    width = length;
    height = length;
}

Rectangle::~Rectangle(){
}

int Rectangle::getArea() {
    return width * height;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

int main() {
    Rectangle rect1;
    cout << "rect1 생성" << " width: " << rect1.getWidth() << " height: " << rect1.getHeight() << " area: " << rect1.getArea() << endl;
    Rectangle rect2(2, 5);
    cout << "rect2 생성" << " width: " << rect2.getWidth() << " height: " << rect2.getHeight() << " area: " << rect2.getArea() << endl;
    Rectangle rect3(10);
    cout << "rect3 생성" << " width: " << rect3.getWidth() << " height: " << rect3.getHeight() << " area: " << rect3.getArea() << endl;
    cout << endl;
    cout << "rect2의 width와 height 3, 10으로 변경" << endl;
    rect2.setWidth(3);
    rect2.setHeight(10);
    cout << "변경된 rect2의" << " width: " << rect2.getWidth() << " height: " << rect2.getHeight() << " area: " << rect2.getArea() << endl;





}