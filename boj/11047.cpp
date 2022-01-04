#include <cstdio>

#define MAX_N 10

int main() {
    // N: 동전의 개수, K: 만들고자 하는 값, A[i]: i번째 동전의 가치
    // ans: 주어진 동전으로 K를 만들 때 사용된 동전의 개수
    int N, K, A[MAX_N] = { 0, }, ans = 0;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", A + i);

    // 가장 큰 동전부터 K를 최소화하는 만큼의 동전을 사용
    while (N--) {
        ans += K / A[N];
        K %= A[N];
    }

    // 동전이 사용된 개수를 출력
    printf("%d\n", ans);

    return 0;
}
