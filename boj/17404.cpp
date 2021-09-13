#include <cstdio>

#define MAX_N 1000
#define INF 0x3f3f3f3f
#define _cost first
#define _start second

// N: 칠할 집의 수, cost[i][c]: i번째 집에 c번 색을 칠할 때의 비용
int N, cost[MAX_N][3];
// dp: dp를 이용해 집을 칠할 최적의 경우를 계산
int dp[MAX_N][3];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    // ans: 정답을 저장할 공간
    int ans = INF;

    // 집의 수와 칠하는 비용을 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) 
        scanf("%d", &cost[i][j]);

    // 첫 집을 칠할 색을 미리 지정
    for (int start = 0; start < 3; start++)
    {
        // 첫 집을 칠했을 때의 비용은 cost 혹은 INF로 저장
        for (int i = 0; i < 3; i++) 
            dp[0][i] = i == start ? cost[0][i] : INF;
        // 두번째 집부터 마지막에 칠한 색에 대해
        for (int i = 1; i < N; i++) for (int c = 0; c < 3; c++)
        {
            // 현재 집을 칠할 최소 비용을 우선 INF로 잡은 뒤
            int add = INF;
            // 조건에 맞는 색 중 비용이 가장 적은 색으로 현재 집을 칠한다
            for (int c_ = 0; c_ < 3; c_++) if (c != c_)
                add = min(add, dp[i - 1][c_]);
            // 비용의 총합을 dp에 저장
            dp[i][c] = add + cost[i][c];
        }
            
        // 집을 모두 칠한 뒤 첫 집과 마지막 집의 색이 같지 않은 경우에 한해
        // 비용의 최솟값을 계산
        for (int c = 0; c < 3; c++) if (start != c) 
            ans = min(ans, dp[N - 1][c]);
    }

    printf("%d\n", ans);

    return 0;
}