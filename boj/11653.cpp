#include <cstdio>

int main()
{
    int N, i = 1;
    scanf("%d", &N);

    // 현재 N의 인수 중 제곱근보다 크지 않은 인수를 모두 출력
    while (N >= ++i * i) while (N % i == 0)
    {
        printf("%d\n", i);
        N /= i;
    }

    // N의 인수 중 제곱근보다 크지 않은 약수가 없고, 
    // N이 1이 아니라면 N은 소수이므로 출력
    if (N != 1) printf("%d\n", N);

    return 0;
}