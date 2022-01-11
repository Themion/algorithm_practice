#include <cstdio>

#define MAX_N 25

// arr[y][x]: 칸 (x, y)에 넴모를 놓았다면 true, 아니라면 false
bool arr[MAX_N][MAX_N];
// N, M: 칸의 크기, ans: 넴모를 전부 놓은 경우의 수
int N, M, ans = 0;

// 칸 (x, y)에 넴모를 놓은 경우와 놓지 않은 경우를 탐색
void backtrack(int y, int x) {
    // x가 M이라면 현재 좌표를 (0, y + 1)로 변경
    if (x == M) { y++; x = 0; }
    // y가 N이라면 모든 칸에 넴모를 놓은 것이므로 ans에 1 더한 뒤 return
    if (y == N) { ans++; return; }

    // x 혹은 y가 0이라면 해당 칸을 오른쪽 아래로 하는 2 * 2 넴모는 존재하지 않는다
    // 왼쪽, 위쪽, 왼쪽 위 대각선쪽 중 한 곳이라도 넴모가 없다면 넴모를 놓을 수 있다
    if (x & y == 0 || !arr[y - 1][x] || !arr[y][x - 1] || !arr[y - 1][x - 1]) {
        // 넴모를 놓은 뒤 탐색하고 넴모를 제거
        arr[y][x] = true;
        backtrack(y, x + 1);
        arr[y][x] = false;
    }
    // 넴모를 놓지 않은 경우를 탐색
    backtrack(y, x + 1);
}

int main() {
    // 보드의 크기를 입력받는다
    scanf("%d %d", &N, &M);
    
    // N과 M 둘 중 하나가 1이라면 2 * 2꼴 넴모는 절대 놓을 수 없으므로
    // 가능한 경우는 2 ^ (N * M)이다
    if (N == 1 || M == 1) ans = 1 << (N * M);
    // 그렇지 않다면 넴모를 놓아가며 가능한 경우의 수를 계산
    else backtrack(0, 0);

    // 넴모를 놓을 수 있는 경우의 수를 출력
    printf("%d\n", ans);

    return 0;
}
