#include <cstdio>

#define MAX_N 5
#define MOD 1000
#define FOR for (int row = 0; row < N; row++) for (int col = 0; col < N; col++)

// 행렬을 저장할 클래스
class matrix {
public:
    // 행렬을 저장할 공간
    int mat[MAX_N][MAX_N] = { {0} };
    // [] 연산자를 이용해 mat에 접근
    int* operator[](int i) { return mat[i]; }
};

// 입력받을 행렬의 크기
int N;

// 두 행렬 P, Q의 곱을 ret에 저장해 반환
matrix operator*(matrix P, matrix Q) {
    matrix ret;
    FOR for (int i = 0; i < N; i++)
        ret[row][col] = (P[row][i] * Q[i][col] + ret[row][col]) % MOD;
    return ret;
}

int main() {
    // A 행렬을 제곱할 횟수
    unsigned long long B;
    // A: B제곱할 행렬, ans: A ^ B
    matrix A, ans;

    // N과 B, A를 차례로 입력받고 ans를 단위행렬로 초기화
    scanf("%d %lld", &N, &B);
    FOR scanf("%d", A[row] + col);
    for (int i = 0; i < MAX_N; i++) ans[i][i] = 1;

    // 이진수 B의 각 자리에 대해
    do {
        // B의 현재 자리가 1일 때 ans에 A를 곱한다
        if (B % 2) ans = ans * A;
        // 곱셈 수를 절약하기 위해 A를 제곱
        A = A * A;
    } while (B /= 2);

    // ans의 각 성분을 차례로 출력
    FOR printf("%d%c", ans[row][col], (col == N - 1 ? '\n' : ' '));

    return 0;
}
