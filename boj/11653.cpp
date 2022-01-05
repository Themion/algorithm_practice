#include <cstdio>

int main() {
    // 소인수분해 할 수
    int N;

    // N의 인수가 둘 이상이라면 N은 가장 작은 인수 i의 제곱보다 크거나 같다
    // N이 인수 i로 나누어 떨어질 동안 i를 출력
    for (int i = scanf("%d", &N); N >= ++i * i; ) 
        for (; !(N % i); N /= i) printf("%d\n", i);

    // for문을 벗어낫다면 N의 인수가 하나 이하가 된다
    // N이 1이 아니라면 N은 N의 소수인 인자이므로 출력
    if (N != 1) printf("%d\n", N);

    return 0;
}
