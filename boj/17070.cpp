#include <cstdio>

#define MAX_N 16

int main() {
    // map: 집의 구조
    // hori, vert, diag: 각 파이프가 가로/세로/대각 방향으로 움직일 수 있는지 여부
    bool map[MAX_N][MAX_N] = {{ false, }}, hori, vert, diag;
    // N: 집의 크기
    // way[dir][y][x]: 파이프가 {가로, 세로, 대각선}[dir] 방향으로 (x, y) 좌표에
    //                 도달하는 경우의 수
    //                 이 때 파이프는 가로로 (1, 0)에 놓인 상태에서 시작한다
    int N, way[MAX_N][MAX_N][3] = {{{ 0, }, { 1, }}};

    // 집의 구조를 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        scanf("%d", &map[i][j]);

    // 집의 (y, 0)에는 파이프가 오지 못하는 것이 자명하다
    // 이 이외의 모든 경우에 대해 파이프를 옮길 수 있는 경우의 수를 계산
    for (int y = 0; y < N; y++) for (int x = 1; x < N; x++) {
        // 가로 / 세로 / 대각선으로 움직일 수 있는지 여부를 계산
        hori = x + 1 < N && !map[y][x + 1];
        vert = y + 1 < N && !map[y + 1][x];
        diag = vert && hori && !map[y + 1][x + 1];

        // 가로로 움직일 수 있다면
        // 이전에 가로 / 대각선으로 움직인 경우의 수를 더한다
        if (hori) way[y][x + 1][0]     = way[y][x][0] + way[y][x][2];
        // 세로로 움직일 수 있다면
        // 이전에 세로 / 대각선으로 움직인 경우의 수를 더한다
        if (vert) way[y + 1][x][1]     = way[y][x][1] + way[y][x][2];
        // 대각선으로 움직일 수 있다면
        // 이전에 가로 / 세로 / 대각선으로 움직인 경우의 수를 더한다
        if (diag) way[y + 1][x + 1][2] = way[y][x][0] + way[y][x][1] + way[y][x][2];
    }

    // (N, N)까지 파이프를 옮길 수 있는 경우의 수 출력
    printf("%d\n", way[--N][N][0] + way[N][N][1] + way[N][N][2]);

    return 0;
}
