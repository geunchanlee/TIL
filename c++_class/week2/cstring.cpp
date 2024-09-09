#include <iostream>
#include <cstring>
using namespace std;

// 키입력_문자열_헤더파일

int main() 
{
    char password[11];
    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while(true) { // bool type 사용가능
        cout << "암호 >> ";
        cin >> password;
        if(strcmp(password, "C++") == 0) {
            cout << "프로그램을 정상 종료합니다." << endl;
            break;
        }
        else
            cout << "암호가 다릅니다." << endl;
    }
}