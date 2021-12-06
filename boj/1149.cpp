#include <cstdio>

// col[i % 2][j] : i번째 집을 j번째 색으로 칠할 때 드는 비용
int col[2][3] = {{ 0, }};

int min(int a, int b) { return a < b ? a : b; }

int main() {
    // 집의 개수
    int N;
    scanf("%d", &N);

    // i번 집을 색칠할 때
    for (int i = 1; i <= N; i++) {
        // 현재 집을 각 색으로 칠하는 비용을 입력받은 뒤
        scanf("%d %d %d", &col[i % 2][0], &col[i % 2][1], &col[i % 2][2]);

        // 이전 집을 현재 집과 다른 색으로 칠할 때까지의 총 비용을
        // 현재 집을 현재 색으로 칠하는 비용에 더한다
        col[i % 2][0] += min(col[!(i % 2)][1], col[!(i % 2)][2]);
        col[i % 2][1] += min(col[!(i % 2)][0], col[!(i % 2)][2]);
        col[i % 2][2] += min(col[!(i % 2)][0], col[!(i % 2)][1]);
    }

    // col[N]에는 모든 집의 최소 비용이 저장되어 있으므로
    // 이 세 최소비용 중 최솟값을 출력한다
    printf("%d\n", min(col[N % 2][0], min(col[N % 2][1], col[N % 2][2])));

    return 0;
}