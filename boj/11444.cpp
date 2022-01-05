#include <cstdio>

typedef unsigned long long ull;

// 행렬 크기는 2 * 2로 고정
#define LEN 2
// 피보나치 수를 나누어 나머지를 구할 수
#define MOD 1000000007

/*                   n
            | 1   1 |    | F(n+1)  F(n)  |
    fib^n = |       |  = |               |
            | 1   0 |    |  F(n)  F(n-1) |
    피보나치를 행렬곱을 이용하여 계산 */
class matrix {
public:
    ull mat[2][2] = {{ 0, }};

    // 곱셈 결과를 저장할 때 사용할 영행렬
    matrix() { }
    // 피보나치 행렬
    matrix(bool b) { 
        for (int i = 0; i < LEN; i++) for (int j = 0; j < LEN; j++) 
            this->mat[i][j] = i * j == 0;
    }
    // 단위행렬
    matrix(int i) { for (int i = 0; i < LEN; i++) this->mat[i][i] = 1; }

    // mat로의 접근을 operator로 설정 -> 메모리 약 4KB 증가
    ull* operator[](int i) { return this->mat[i]; }

    // 행렬곱
    matrix operator*(matrix m) {
        matrix ret;
        for (int row = 0; row < LEN; row++) for (int col = 0; col < LEN; col++)
            for (int i = 0; i < LEN; i++) {
                ret[row][col] += this->mat[row][i] * m[i][col];
                ret[row][col] %= MOD;
            }
        return ret;
    }
    void operator*=(matrix m) { *this = *this * m; }
};

int main() {
    // 행렬을 거듭제곱할 횟수
    ull n;
    // fib: 2의 거듭제곱을 할 행렬
    // ans: 거듭제곱한 행렬을 각각 곱해 저장할 행렬
    matrix fib = matrix(true), ans = matrix(3);

    scanf("%lld", &n);

    // fib를 제곱할 횟수 n을 이진법으로 보았을 때 n - 1의 각 자리에 대해
    for (n--; n; n /= 2) {
        // 현재 자리가 1이라면 ans에 fib를 곱한다
        if (n % 2) ans *= fib;
        // fib를 제곱한다
        fib *= fib;
    }

    // fib를 (n - 1)제곱하였으므로
    // [0][0] 위치는 fib(n - 1 + 1), 즉 fib(n)가 된다
    printf("%lld\n", ans[0][0]);

    return 0;
}
