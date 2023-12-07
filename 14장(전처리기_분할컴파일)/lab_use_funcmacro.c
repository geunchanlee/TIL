#include <stdio.h>
#define PI 3.1415
#define CIRCLE_AREA(r) (PI * (r) * (r))
// #define DEBUG

int main()
{
#ifdef DEBUG
    printf("디버깅 모드입니다.\n");
#endif //endif 없으면 아래 문장 전부 가려지므로 꼭 넣기

    double radius;
    printf("원의 반지름을 입력하세요: ");
    scanf("%lf", &radius);
    printf("원의 넓이는 %.2lf입니다.\n", CIRCLE_AREA(radius));
    return 0;
}