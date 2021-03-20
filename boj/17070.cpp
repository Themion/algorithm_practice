#include <cstdio>

#define MAX_N 16

// 집의 구조
bool map[MAX_N][MAX_N] = {{ false, }};
// way[dir][y][x]: 파이프가 {가로, 세로, 대각선} 방향으로 (x, y) 좌표에
//                 도달하는 경우의 수
int way[3][MAX_N][MAX_N] = {{{ 0, }}}, N;

// 파이프의 머리가 (x, y)에 있을 때 파이프를 옮길 수 있는 경우의 수 계산
void set_way(int y, int x)
{
    // 세로 / 가로 / 오른쪽으로 움직일 수 있는지 여부를 미리 저장
    bool to_down = y + 1 < N && !map[y + 1][x],
        to_right = x + 1 < N && !map[y][x + 1],
        to_diag  = to_down && to_right && !map[y + 1][x + 1];

    // 가로로 움직일 수 있다면 
    // 이전에 가로 / 대각선으로 움직인 경우의 수를 더한다
    if (to_right)
        way[0][y][x + 1]     = way[0][y][x] + way[2][y][x];
    // 세로로 움직일 수 있다면 
    // 이전에 세로 / 대각선으로 움직인 경우의 수를 더한다
    if (to_down)
        way[1][y + 1][x]     = way[1][y][x] + way[2][y][x];
    // 대각선으로 움직일 수 있다면 
    // 이전에 가로 / 세로 / 대각선으로 움직인 경우의 수를 더한다
    if (to_diag)
        way[2][y + 1][x + 1] = way[0][y][x] + way[1][y][x] + way[2][y][x];
}

int main()
{
    // 집의 구조를 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        scanf("%d", &map[i][j]);

    // 파이프는 가로로 (1, 0)에 놓인 상태에서 시작한다
    way[0][0][1] = 1;

    // 집의 (y, 0)에는 파이프가 오지 못하는 것이 자명하다
    // 이 이외의 모든 경우에 대해 파이프를 옮길 수 있는 경우의 수를 계산
    for (int y = 0; y < N; y++) for (int x = 1; x < N; x++)
        set_way(y, x);

    N--;    // (N, N)까지 파이프를 옮길 수 있는 경우의 수 출력
    printf("%d\n", way[0][N][N] + way[1][N][N] + way[2][N][N]);

    return 0;
}