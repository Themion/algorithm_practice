#include <cstdio>

#define MAX_N 20

int main() {
    // fib[i % 2]: i번째 피보나치 수, n: 구할 피보나치 수의 순서
    int fib[2] = { 0, 1 }, n;

    // n을 입력받은 뒤 n번째 피보나치 수까지 계산
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) fib[i % 2] += fib[!(i % 2)];
    // n번째 피보나치 수를 출력
    printf("%d\n", fib[n % 2]);

    return 0;
}
