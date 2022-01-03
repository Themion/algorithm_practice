#include <cstdio>

#define MAX_N 100

int main() {
    // ans[i][j]: (i, j)에 별이 찍혀야 하면 false, 아니라면 true
    bool ans[(4 * MAX_N) - 3][(4 * MAX_N) - 3] = {{ 0, }};
    // N: 출력할 도형의 가로 길이, n: 공백을 저장할 때 사용할 변수
    // y, x: 공백을 저장할 각 좌표
    int N, n, y = -1, x = 1;

    // N을 입력받은 뒤 N이 1이라면 별 하나만 출력한 뒤 종료
    scanf("%d", &N);
    if (N == 1) { printf("*\n"); return 0; }

    // 저장할 도형의 한 변의 길이는 4 * (N - 1)이다
    // N을 변형시키지 않기 위해 N을 따로 n에 저장
    N = 4 * (N - 1); n = N;
    // 공백을 저장할 길이가 1 이상일 때
    while (n) {
        // 공백을 아래쪽 방향으로 n번 저장한 뒤 n을 2 줄인다
        for (int i = 0; i < n; i++) ans[++y][x] = true;
        n -= 2;
        // 공백을 오른쪽 방향으로 n번, 위쪽 방향으로 n번 저장한 뒤 n을 2 줄인다
        for (int i = 0; i < n; i++) ans[y][++x] = true;
        for (int i = 0; i < n; i++) ans[--y][x] = true;
        n -= 2;
        // 공백을 왼쪽 방향으로 n번 저장한다
        for (int i = 0; i < n; i++) ans[y][--x] = true;
    }

    // 0번째 줄은 반드시 별이 모두 출력되고, 1번째 줄은 반드시 별이 하나만 출력된다
    // 1번째 줄에 공백을 출력하지 않기 위해 임의로 출력
    for (int i = 0; i <= N; i++) printf("*");
    printf("\n*\n");

    // 2번째 줄부터 저장한 방식대로 별과 공백을 출력
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) printf("%c", ans[i][j] ? ' ' : '*');
        printf("\n");
    }

    return 0;
}
