#include <iostream>
using namespace std;

#include "Calendar.h"

int main() {
    
    Calendar date1;
    Calendar date2(4, 5);
    Calendar date3(2002, 2, 2);
    date1.printCalendar();
    date2.printCalendar();
    date3.printCalendar();
    
    int year, month, day;
    cout << "년도 입력: ";
    cin >> year;
    cout << "월 입력: ";
    cin >> month;
    cout << "일 입력: ";
    cin >> day;
    
    Calendar date4(year, month, day);
    Calendar date5(month, day);
    date4.printCalendar();
    date5.printCalendar();
    
    date1.set(1945, 8, 15);
    date1.printCalendar();
    date1.set(12, 25);
    date1.printCalendar();
}
