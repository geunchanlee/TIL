#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

int main() {

    Shape *pStart=NULL;
    Shape *pLast;

    pStart = new Circle();
    pLast = pStart;
    
    char c = ' ';
    while( c != 'x') {
        cout << "문자열 입력: ";
        cin >> c;
        if (c == 'c') {
            pLast = pLast->add(new Circle());
        } else if (c == 'r') {
            pLast = pLast->add(new Rect());
        } else if (c == 'l') {
            pLast = pLast->add(new Line());
        } else if (c == 'x') {
            cout << "x입력" <<endl;
            Shape* p = pStart;
            while(p != NULL) {
                p->paint();
                Shape* q = p->getNext();
                delete p;
                p = q;
            }
        }
    }
    
    return 0;
}
