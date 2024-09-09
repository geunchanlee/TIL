#include <iostream>
#include <string>
using namespace std;

// 9.9 c++ class <week2-1>
// cin.ignore 알아보기.
// getline, string 헤더 배움


int main() 
{
    int a, b;
    string axis;

    cout << "정수 2개 입력(2~9): ";
    cin >> a >> b;
    getchar();

    if (a>b) {
      int t;
      t = a;
      a = b;
      b = t;
    }
    if ((a < 2 || a > 9) || (b < 2 || b > 9)) {
        cout << "숫자 범위 오류" << endl;
        return 1;
    }

    cout << "문자열 입력(가로, 세로): ";
    getline(cin, axis);

    if (axis != "가로" && axis != "세로") {
        cout << "비정상 입력" << endl;
        return 1;
    }

    if (axis == "가로") {
        for(int i = a; i<=b; i++){
            for(int k=1; k<9; k++){
                cout << i << '*' << k << '=' << i*k << ',' << '\t';
            }
            cout << i << '*' << 9 << '=' << i*9 << '\n';
        }
    }
    else if (axis == "세로") {
        for(int i=1; i<10; i++){
            for(int k=a; k<b; k++){
               cout << k << '*' << i << '=' << k*i << ',' << '\t';
            }
            cout << b << '*' << i << '=' << b*i  << '\n';
        }
    }
    
}