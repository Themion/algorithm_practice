#include <cstdio>

#define MAX_N 1000
#define INF 0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int main() {
    // N: 집의 수, cost[i][j]: i번째 집을 j색으로 칠하는 비용
    // dp[i][j]: i번째 집까지 칠하되 i번째 집의 색이 j일 때의 비용
    // add: dp의 이전 값을 현재 값에 더할 때 최솟값을 저장할 공간
    // ans: 모든 집을 칠하는 비용의 최솟값
    int N, cost[MAX_N][3], dp[2][3], add, ans = INF;

    // 집의 수와 칠하는 비용을 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) 
        scanf("%d", &cost[i][j]);

    // 첫 집을 칠할 색을 미리 지정
    for (int s = 0; s < 3; s++) {
        // 첫 집을 칠했을 때의 비용은 cost 혹은 INF로 저장
        for (int i = 0; i < 3; i++) dp[0][i] = i == s ? cost[0][i] : INF;
        // 두번째 집부터 마지막에 칠한 색에 대해
        for (int i = 1; i < N; i++) {
            // 각 집을 칠하는 최소 비용을 계산
            dp[i % 2][0] = min(dp[!(i % 2)][1], dp[!(i % 2)][2]) + cost[i][0];
            dp[i % 2][1] = min(dp[!(i % 2)][0], dp[!(i % 2)][2]) + cost[i][1];
            dp[i % 2][2] = min(dp[!(i % 2)][0], dp[!(i % 2)][1]) + cost[i][2];
        }

        // 집을 모두 칠한 뒤 첫 집과 마지막 집의 색이 같지 않은 경우에 한해
        // 비용의 최솟값을 계산
        for (int c = 0; c < 3; c++) if (s != c) ans = min(ans, dp[!(N % 2)][c]);
    }

    // 주어진 방법으로 집을 칠하는 최소 비용을 출력
    printf("%d\n", ans);

    return 0;
}
