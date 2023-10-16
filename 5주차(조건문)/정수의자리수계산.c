#include <stdio.h>

int main()
{
	int num;
	int cnt;
	cnt = 0;
	
	printf("정수를 입력하세요: ");
	scanf("%d", &num);

	while (num > 0) {
		num /= 10;
		cnt++;
	}
	printf("총 자리수: %d\n", cnt);
}

