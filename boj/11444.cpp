#include <cstdio>

typedef unsigned long long ull;

// 행렬 크기는 2 * 2로 고정
#define N 2
// 피보나치 수를 나누어 나머지를 구할 수
#define MOD 1000000007

/*                   n
            | 1   1 |    | F(n+1)  F(n)  |
    fib^n = |       |  = |               |
            | 1   0 |    |  F(n)  F(n-1) |
    피보나치를 행렬곱을 이용하여 계산 */
class matrix
{
public:
    ull mat[2][2] = { {0} };
    // 영행렬
	matrix() { }
    // 피보나치 행렬
	matrix(bool b) 
    { 
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) 
            this->mat[i][j] = i * j == 0;
    }
    // 단위행렬
    matrix(int i) { for (int i = 0; i < N; i++) this->mat[i][i] = 1; }

    // 행렬곱
	matrix operator*(matrix A)
	{
		matrix ret;

		for (int row = 0; row < N; row++) for (int col = 0; col < N; col++)
			for (int i = 0; i < N; i++)
			{
				ret.mat[row][col] += this->mat[row][i] * A.mat[i][col];
				ret.mat[row][col] %= MOD;
			}

		return ret;
	}
    void operator*=(matrix A) { *this = *this * A; }
};

int main()
{
    // 행렬을 거듭제곱할 횟수
    ull cnt;
    // fib: 2의 거듭제곱을 할 행렬
    // ans: 거듭제곱한 행렬을 각각 곱해 저장할 행렬
    matrix fib = matrix(true), ans = matrix(3);

    // 행렬을 거듭제곱 할 횟수를 구한 뒤
    // 계산량을 줄이기 위해 [0][0] 위치를 참조하므로 1 뺀다
	scanf("%lld", &cnt);
    cnt--;

    // fib를 n제곱
    while (cnt)
	{
        // 2의 거듭제곱을 반복하며 비트마스킹이 1인 거듭제곱은 ans와 곱해 보존
		if (cnt % 2) ans *= fib;
        fib *= fib;
		cnt /= 2;
	}

    // fib를 (cnt - 1)제곱하였으므로 
    // [0][0] 위치는 fib(cnt - 1 + 1), 즉 fib(cnt)가 된다
    printf("%lld\n", ans.mat[0][0]);

    return 0;
}