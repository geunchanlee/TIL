#include <iostream>
using namespace std;

// 키입력_문자열_헤더파일

int main() 
{
    cout << "주소를 입력하세요 >> ";

    char address[100];
    cin.getline(address, 100, '\n'); // 개행문자 '\n' 를 만날때까지 입력받음
    // cin.getline(char buf[], int size, char delimitChar)
    // buf에 size-1개의 문자를 입력받고 끝에 '\0' 붙임
    // delimitChar를 만나면 입력 중단받고 끝에 '\0' 붙임
    cout << "주소는 " << address << "입니다.\n";

    return 0;
}