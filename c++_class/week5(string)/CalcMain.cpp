#include <iostream>
#include <string>
using namespace std;

// 강의중 살펴본 +가 섞인 식을 입력받아 계산하는 프로그램을 수정해 '-'도 입력받을 수 있게 바꾸자.

// '-' 문자 앞에 '+'를 추가하는 방법으로 해결

int main(){
    string s;
    cout << "식을 입력하세요. ex)55+44-200-1000+302" << endl;
    getline(cin, s, '\n');
    int sum = 0;
    int startIndex = 0;
    
    // 식이 음수로 시작하는 경우를 위한 처리부분
    if (s[0] == '-') {
        startIndex = 1; // 첫 번째 문자가 -일 때 그 이후부터 숫자 탐색
    }
    // '-' 문자를 찾아서 그 자리에 '+'를 넣어주는 부분
    while(true){
        int fIndex = s.find('-', startIndex);
        if(fIndex == -1) // startIndex에서 끝까지 '-'문자가 없을 때 반복을 종료
            break;
        s.insert(fIndex, 1, '+'); // fIndex 자리에 '+'문자를 1번 삽입
        startIndex = fIndex + 2; // '+'를 넣어줬으므로 fIndex는 현재 '+'의 자리. 여기에 +1을 하면 '-'가 있는 자리이기 때문에 +2를 해줘서 다음 탐색으로 넘어감
    }
    cout << "음수 처리된 문자열: " << s << endl;
   
    startIndex = 0; // 다시 처음부터 시작하도록 인덱스 조정
    while(true){
        int fIndex = s.find('+', startIndex);
        if(fIndex == -1){
            string part = s.substr(startIndex);
            if(part == "") break;
            cout << part << endl;
            sum += stoi(part);
            break;
        }
        int count = fIndex - startIndex;
        string part = s.substr(startIndex, count);
        cout << part << endl;
        sum += stoi(part);
        startIndex = fIndex +1;
    }
    cout << "숫자들의 합은 " << sum << endl;
    return 0;
}
