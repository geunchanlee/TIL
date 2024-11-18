#include <iostream>
using namespace std;

void star(int n, int f);


int main()
{
    int n, f;
    cout << "별출력(1~4): ";
    cin >> f;
    cout << "정수 입력: ";
    cin >> n;
    star(n, f);
}

void star(int n, int f){
    if (f == 1){
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                cout << '*';
            }
            cout << '\n';
        }
    }
    else if (f == 2){
        for(int i=1;i<=n;i++) {
            for(int j=n-i;j>0;j--){
                cout << ' ';
            }
            for(int k=1;k<=i;k++){
                cout << '*';
            }
            cout << '\n';
        }
    }
    else if (f == 3){
        int star = 1;
        for(int i=1; i<=n*2-1;i++){
            for(int j=0;j<star;j++){
                cout << '*';
            }
            if(i < n)
                star += 1;
            else 
                star -= 1;
            cout << '\n';
        }
    }
    else if (f == 4){
        int star = 1;
        for(int i=1; i<=n*2-1;i++){
            for(int j=0;j<n-star;j++){
                cout << ' ';
            }
            for(int k=0;k<star;k++){
                cout << '*';
            }
            if(i < n)
                star += 1;
            else
                star -= 1;
            cout << '\n';
        }
    }
}