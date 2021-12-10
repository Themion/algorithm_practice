#include <cstdio>

#define MAX_N 1000000

// era[i]: i가 소수라면 false, 아니라면 true
bool era[MAX_N + 1] = { true, true, };

int main() {
    // M, N : 소수의 범위, k : 소수를 구할 때 쓸 곱셈수
    int M, N, k;
    scanf("%d %d", &M, &N);

    // 2부터 N까지 모든 수에 대해
    for (int i = 2; i <= N; i++) {
        // 2 이상을 곱해서 나온 수는 모두 소수가 아니다
        k = 2;
        // i * k가 N 초과라면 굳이 할 필요가 없다
        while (i * k <= N) era[i * k++] = true;
    }

    // era에서 소수인 수들만 골라 출력한다
    for (int i = M; i <= N; i++) if (!era[i]) printf("%d\n", i);

    return 0;
}
