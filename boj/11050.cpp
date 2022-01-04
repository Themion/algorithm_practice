#include <cstdio>

#define MAX_N 10

int main() {
    // N, K: 이항계수 상수, ans[n][k]: 이항계수 nCk
    int N, K, ans[MAX_N + 1][MAX_N + 1] = {{ 0, }};

    // 문제의 조건을 입력받은 뒤 파스칼의 삼각형을 이용해 이항 계수를 계산
    scanf("%d %d", &N, &K);
    for (int n = 1; n <= N; n++) {
        ans[n][0] = ans[n][n] = 1;
        for (int k = 1; k < n; k++)
            ans[n][k] = ans[n - 1][k] + ans[n - 1][k - 1];
    }

    // 이항계수를 출력
    printf("%d\n", ans[N][K]);

    return 0;
}
