#include <cstdio>

#define MAX_N 100

int main() {
    // 정사각형 도형을 저장할 공간
    bool ans[MAX_N * 4 + 1][MAX_N * 4 + 1] = {{ 0, }};
    // 정사각형 도형의 한 변의 길이
    int N;

    // 입력받은 값을 정사각형의 한 변의 길이로 바꾼 뒤 N 갱신
    scanf("%d", &N);
    N = 4 * (N - 1);

    // 가장 큰 사각형부터 변 길이를 2 * 2씩 줄여나가며 저장
    for (int a = 0; a <= N / 2; a += 2) for (int i = a; i <= N - a; i++)
        ans[i][a] = ans[a][i] = ans[N - i][N - a] = ans[N - a][N - i] = 1;

    // ans[i][j]값이 true면 *을, 아니라면 공백을 출력
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) printf("%c", ans[i][j] ? '*' : ' ');
        printf("\n");
    }

    return 0;
}
