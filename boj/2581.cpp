#include <cstdio>

#define MAX_N 10000

int main() {
    // prime[i]: i가 소수라면 false, 그렇지 않다면 true
    bool prime[MAX_N + 1] = { 1, 1 };
    // M, N: 범위로 주어지는 수, sum: 범위 내 소수의 합, min: 범위 내 소수의 최솟값
    int M, N, sum = 0, min = MAX_N;

    scanf("%d %d", &M, &N);

    // N 이하의 모든 소수에 대해
    for (int i = 2; i <= N; i++) if (!prime[i]) {
        // 에라토스테네스의 체 실행
        for (int j = i + i; j <= N; j += i) prime[j] = true;
        // 소수가 M 이상이라면
        if (i >= M) {
            // 소수의 합과 최솟값을 갱신
            if (min > i) min = i;
            sum += i;
        }
    }
    // 합이 존재한다면 합과 최솟값을, 그렇지 않다면 -1을 출력
    sum ? printf("%d\n%d\n", sum, min) : printf("-1\n");

    return 0;
}
