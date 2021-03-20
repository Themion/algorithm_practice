#include <cstdio>

int main()
{
    //두 수 a와 b를 입력받은 뒤
    int a, b;
    scanf("%d %d", &a, &b);
    //a와 b의 각 자리 수의 곱을 출력하고
    printf("%d\n", a * (b % 10));
    printf("%d\n", a * ((b / 10) % 10));
    printf("%d\n", a * (b / 100));
    //a와 b의 곱을 출력한다
    printf("%d\n", a * b);

    return 0;
}