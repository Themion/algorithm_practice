#include <cstdio>

#define MAX 50

// board[i][j]: (i, j) 칸이 검은 색이면 true, 아니라면 false
bool board[MAX][MAX];

int min(int a, int b) { return a < b ? a : b; }

int brute_force(int y, int x) {
    int paint[2] = { 0, 0 };

    // 체스판의 i행 j열 칸의 색은 (i + j) % 2에 따라 결정된다
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) 
        paint[board[y + i][x + j] == (i + j) % 2] += 1;

    // 칠하는 두 방법 중 더 작은 방법을 기존 방법과 비교한다
    return min(paint[0], paint[1]);
}

int main() {
    // N, M: 판자의 사이즈, ans : 칠해야 하는 최소 횟수
    // paint: 판자를 잘라낸 뒤 칠하는 횟수를 셀 때 쓸 변수
    int N, M, ans = MAX * MAX, paint[2];
    // 입력을 버퍼를 통해 받는다
    char buf;

    // 판자의 크기와 칠해진 상태를 입력받는다
    scanf("%d %d\n", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &buf);
            board[i][j] = (buf == 'B');
        }
        // 개행문자 입력 방지
        scanf("%*c");
    }

    // 판자가 8 * 8 크기가 될 수 있는 모든 경우에 대해 색을 칠하는 횟수를 계산
    // 각 경우를 비교하여 최솟값을 ans에 저장한다
    for (int y = 0; y <= N - 8; y++) for (int x = 0; x <= M - 8; x++) 
        ans = min(ans, brute_force(y, x));

    // 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다
    printf("%d\n", ans);

    return 0;
}