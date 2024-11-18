#include <iostream>
using namespace std;

class Calendar {
private:
    int year;
    int month;
    int day;
public:
    Calendar();
    Calendar(int m, int d);
    Calendar(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void printCalendar();
};

Calendar::Calendar(){ 
    year = 2024;
    month = 9;
    day = 19;
}

Calendar::Calendar(int m, int d){
    year = 2024;
    month = m;
    day = d;
}

Calendar::Calendar(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

int Calendar::getYear(){
    return year;
}

int Calendar::getMonth(){
    return month;
}

int Calendar::getDay(){
    return day;
}

void Calendar::setYear(int y){
    year = y;
}

void Calendar::setMonth(int m){
    month = m;
}

void Calendar::setDay(int d){
    day = d;
}

void Calendar::printCalendar(){
    cout << year << "년 " << month << "월 " << day << "일" << endl;
}

int main(){
    Calendar cal1;
    Calendar cal2(10,1);
    Calendar cal3(1997,11,27);

    cal1.printCalendar();
    cal2.printCalendar();
    cal3.printCalendar();

    cout << "cal3의 연, 월, 일 변경하고 출력하기\n" << endl;

    cal3.setYear(2024);
    cout << "변경된 년도: " << cal3.getYear() << " 년" << endl;
    cal3.setMonth(12);
    cout << "변경된 월: " << cal3.getMonth() << " 월" << endl;
    cal3.setDay(25);
    cout << "변경된 일: " << cal3.getDay() << " 일" << endl;

    cal3.printCalendar();
}