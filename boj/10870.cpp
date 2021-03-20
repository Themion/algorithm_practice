#include <cstdio>

//피보나치 수는 세 개의 공간만 가지고 계산이 가능하다
int fib[3];

int main()
{
    //n번째 피보나치 수를 계산할 때 쓸 변수
    int n;
    scanf("%d", &n);

    //1번째 피보나치 수는 1이다
    fib[1] = 1;
    //2번째 수부터 차례로 계산한다
    for (int i = 2; i <= n; i++) 
        fib[i % 3] = fib[(i - 1) % 3] + fib[(i - 2) % 3];

    //n번째 피보나치 수를 출력한다
    printf("%d\n", fib[n % 3]);

    return 0;
}