#include <cstdio>

#define MAX_N 3 * 1024

// 계산의 편의를 위해 삼각형을 뒤집어서 저장
bool ans[MAX_N][2 * MAX_N] = {{ 1, 1, 1, 1, 1, 0 },
                              { 0, 1, 0, 1, 0, 0 },
                              { 0, 0, 1, 0, 0, 0 }};

int main() {
    // 삼각형의 높이
    int N;

    // 높이를 입력받은 뒤
    scanf("%d", &N);
    // 프랙탈의 크기가 주어진 크기가 될 때까지 프랙탈화 반복
    for (int n = 3; n < N; n *= 2)
        // 삼각형의 오른쪽과 위쪽 꼭지점에 기존 삼각형을 복제해 프랙탈 생성
        for (int i = 0; i < n; i++) for (int j = 0; j < 2 * n; j++)
            ans[i + n][j + n] = ans[i][j + 2 * n] = ans[i][j];

    // 삼각형을 차례로 출력
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N * 2; j++) printf("%c", ans[i][j] ? '*' : ' ');
        printf("\n");
    }

    return 0;
}
