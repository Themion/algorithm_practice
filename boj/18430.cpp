#include <cstdio>

#define MAX_N 5

#define u y - 1
#define d y + 1
#define l x - 1
#define r x + 1

#define ux visit[u][x]
#define dx visit[d][x]
#define yl visit[y][l]
#define yr visit[y][r]

// visit[y][x]: 부메랑을 만들 때 칸 (x, y)를 사용했다면 true, 아니라면 false
bool visit[MAX_N][MAX_N];
// N, M: 나무 재료의 크기, K: 나무 재료의 각 칸의 강도
// ans: 부메랑의 강도의 합의 최댓값
int N, M, K[MAX_N][MAX_N], ans;

int max(int a, int b) { return a > b ? a : b; }

void backtrack(int y, int x, int sum) {
    // (x_, y_): (x, y)의 다음 좌표
    int y_ = y + (x == M - 1), x_ = (x + 1) % M;

    // 모든 좌표에 부메랑을 배치했다면
    if (y == N) {
        // 부메랑의 강도의 합을 기존 최댓값과 비교해 갱신한 뒤 return
        ans = max(ans, sum);
        return;
    }

    // 현재 칸에 부메랑을 배치하지 않는 경우를 먼저 계산
    backtrack(y_, x_, sum);

    // 현재 칸에 부메랑을 둘 수 있다면
    if (!visit[y][x]) {
        // 현재 칸을 부메랑의 중심으로 둔 뒤 중심의 강도를 두 배로 설정
        visit[y][x] = true;
        sum += 2 * K[y][x];

        // 위쪽과 왼쪽이 존재하고 비었다면
        if (y > 0 && !ux && x > 0 && !yl) {
            // 해당 위치에 부메랑을 둔 뒤 이후의 경우를 계산하고
            ux = yl = true;
            backtrack(y_, x_, sum + K[u][x] + K[y][l]);
            // 부메랑을 제거
            ux = yl = false;
        }
        // 위쪽과 오른쪽이 존재하고 비었다면
        if (y > 0 && !ux && x < M - 1 && !yr) {
            // 해당 위치에 부메랑을 둔 뒤 이후의 경우를 계산하고
            ux = yr = true;
            backtrack(y_, x_, sum + K[u][x] + K[y][r]);
            // 부메랑을 제거
            ux = yr = false;
        }
        // 아래쪽과 왼쪽이 존재하고 비었다면
        if (y < N - 1 && !dx && x > 0 && !yl) {
            // 해당 위치에 부메랑을 둔 뒤 이후의 경우를 계산하고
            dx = yl = true;
            backtrack(y_, x_, sum + K[d][x] + K[y][l]);
            // 부메랑을 제거
            dx = yl = false;
        }
        // 아래쪽과 오른쪽이 존재하고 비었다면
        if (y < N - 1 && !dx && x < M - 1 && !yr) {
            // 해당 위치에 부메랑을 둔 뒤 이후의 경우를 계산하고
            dx = yr = true;
            backtrack(y_, x_, sum + K[d][x] + K[y][r]);
            // 부메랑을 제거
            dx = yr = false;
        }
        // 중심 칸을 제거
        visit[y][x] = false;
    }
}

int main() {
    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++)
        scanf("%d", &K[y][x]);

    // 부메랑을 둘 수 있는 모든 경우에 대해 각 부메랑의 강도의 합의 최댓값을 계산한 뒤
    backtrack(0, 0, 0);
    // 부메랑의 강도의 합의 최댓값을 출력
    printf("%d\n", ans);

    return 0;
}
