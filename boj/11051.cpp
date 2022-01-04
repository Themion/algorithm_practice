#include <cstdio>

#define MAX_N 1000
#define MOD 10007

int main() {
    // N, K: 이항계수 상수
    int N, K;
    // ans[n][k]: 이항계수 nCk
    short ans[2][MAX_N + 1] = {{ 0, }};

    // 문제의 조건을 입력받은 뒤 파스칼의 삼각형을 이용해 이항 계수를 계산
    scanf("%d %d", &N, &K);
    for (int n = 1; n <= N; n++) {
        ans[n % 2][0] = ans[n % 2][n] = 1;
        for (int k = 1; k < n; k++)
            ans[n % 2][k] = (ans[!(n % 2)][k] + ans[!(n % 2)][k - 1]) % MOD;
    }

    // 이항계수를 출력
    printf("%hd\n", ans[N % 2][K]);

    return 0;
}
