#include <iostream>
using namespace std;

#include "Calendar.h"

Calendar::Calendar() : Calendar(2024, 9, 26) { }

Calendar::Calendar(int m, int d){
    year = 2024;
    month = m;
    day = d;
    cout << year << "년 " << month << "월 " << day << "일 " << "Calendar 객체 생성" << endl;
}

Calendar::Calendar(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
    cout << year << "년 " << month << "월 " << day << "일 " << "Calendar 객체 생성" << endl;
}

Calendar::~Calendar(){
    cout << year << "년 " << month << "월 " << day << "일 "
    << "Calendar 객체 소멸" << endl;
}

void Calendar::set(int m, int d){
    month = m;
    day = d;
}

void Calendar::set(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

void Calendar::printCalendar(){
    cout << year << "년 " << month << "월 " << day << "일 " << endl;
}
