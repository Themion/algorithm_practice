#include <cstdio>

#define MAX_N 100

short A[MAX_N][MAX_N], B[MAX_N][MAX_N];

// 행렬의 한 항을 함수 내에서 계산
int mul(int N, int M, int K) {
    int ret = 0;
    for (int m = 0; m < M; m++) ret += A[N][m] * B[m][K];
    return ret;
}

int main() {
    // A[N][M], B[M][K]
    int N, M, K;

    // 행렬 A를 입력받는다
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        scanf("%hd", &A[i][j]);

    // 행렬 B를 입력받는다
    scanf("%*d %d", &K);
    for (int i = 0; i < M; i++) for (int j = 0; j < K; j++) 
        scanf("%hd", &B[i][j]);

    // 행렬 A*B를 저장하지 않고 바로 출력한다
    for (int i = 0; i < N; i++) for (int j = 0; j < K; j++) 
        printf("%d%c", mul(i, M, j), (j == K - 1 ? ' ' : '\n'));

    return 0;
}
