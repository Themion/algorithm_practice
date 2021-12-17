#include <cstdio>

#define MAX_N 1500000
#define MOD 1000000

int main() {
    // fib[i % 3]: i번째 피보나치 수
    int fib[3] = { 0, 1, 1 };
    // n: 구할 피보나치 수의 순서
    unsigned long long n;

    // n을 입력받은 뒤 해당 수를 주기와 나머지 연산을 한다
    scanf("%lld", &n);
    n %= MAX_N;

    // n번째 피보나치 수를 구한 뒤 출력한다
    for (int i = 2; i <= n; i++) 
        fib[i % 3] = (fib[(i - 1) % 3] + fib[(i - 2) % 3]) % MOD;
    printf("%d\n", fib[n % 3]);

    return 0;
}
