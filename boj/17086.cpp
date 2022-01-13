#include <cstdio>

#define INF 0x3f3f3f3f
#define MAX_N 50

struct coord { int _y = 0, _x = 0; };

int abs(int n) { return n < 0 ? -n : n; }
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    // map[y][x]: 좌표 (x, y)에 상어가 있다면 true, 아니라면 false
    bool map[MAX_N][MAX_N] = {{ 0, }};
    // N, M: 공간의 크기, len: 상어의 수
    // dist: 각 상어까지의 안전 거리, ans: 각 칸의 안전 거리의 최댓값
    int N, M, len = 0, dist, ans = 0;
    // 상어의 좌표의 집합
    coord c[MAX_N * MAX_N];

    scanf("%d %d", &N, &M);
    // 상어가 있는 좌표를 v에 저장
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) {
        scanf("%d", &map[y][x]);
        if (map[y][x]) c[len++] = { y, x };
    }

    // 각 좌표에서 가장 가까운 상어까지의 거리를 계산
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) if (!map[y][x]) {
        // 상어가 없는 경우 안전 거리는 무한이다
        dist = INF;
        
        // 각 상어까지의 거리 중 가장 작은 값을 dist에 저장
        for (int i = 0; i < len; i++)
            dist = min(dist, max(abs(y - c[i]._y), abs(x - c[i]._x)));
        // ans에 dist의 최댓값을 저장
        ans = max(ans, dist);
    }

    // 안전 거리의 최댓값을 출력
    printf("%d", ans);

    return 0;
}
