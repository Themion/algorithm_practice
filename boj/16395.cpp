#include <cstdio>

#define MAX_N 30

int main() {
    // n, k: 이항계수를 구할 값, tri[n][k] = nCk
    int n, k, tri[MAX_N + 1][MAX_N + 1] = {{ 0, }, { 0, 1, }};

    // 문제의 조건을 입력받은 뒤 파스칼의 삼각형을 계산
    for (int i = scanf("%d %d", &n, &k); i <= n; i++)
        for (int j = 1; j <= i / 2; j++)
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];

    // 이항계수 nCk를 출력
    printf("%d\n", tri[n][k]);

    return 0;
}
