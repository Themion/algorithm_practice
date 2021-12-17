#include <cstdio>

int main() {
    // 피보나치 수를 계산할 때 필요한 공간은 총 세 개이다
    // 두 개는 더할 수를 저장한 공간, 나머지 하나는 더한 수를 저장할 공간

    // fib[i % 3]: i번째 피보나치 수, n: 구할 피보나치 수의 순서 
    long long fib[3] = { 0, 1, }, n;
    // 구할 피보나치 수의 순서를 입력받은 뒤
    scanf("%lld", &n);
    // n번째까지의 피보나치 수를 연산
    for (int i = 2; i <= n; i++)
        fib[i % 3] = fib[(i - 1) % 3] + fib[(i - 2) % 3];
    // n번째 피보나치 수를 출력한다
    printf("%lld\n", fib[n % 3]);

    return 0;
}
