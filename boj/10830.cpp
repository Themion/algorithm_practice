#include <algorithm>
#include <cstdio>
#include <vector>

//행렬을 저장할 클래스
class matrix
{
public:
    //mat: 행렬 자체를 저장할 공간
    //N: 행렬의 한 행/열의 크기
	int mat[5][5] = { {0} }, N;

	matrix() { }
	matrix(int N) { this->N = N; }

    //행렬 * 행렬
	matrix operator*(matrix A)
	{
		matrix ret = matrix(this->N);

		for (int row = 0; row < N; row++)
			for (int col = 0; col < N; col++)
				for (int i = 0; i < N; i++)
				{
					ret.mat[row][col] += this->mat[row][i] * A.mat[i][col];
					ret.mat[row][col] %= 1000;
				}

		return ret;
	}

    //행렬의 출력을 멤버 함수로 정의한다
	void print()
	{
		for (int row = 0; row < N; row++)
		{
			for (int col = 0; col < N; col++)
				printf("%d ", this->mat[row][col]);
			printf("\n");
		}
	}
};

//입력받을 행렬의 크기
int N;
//A: B제곱할 행렬, ret: B제곱한 행렬
matrix A, ret;

int main()
{
    //B: A 행렬을 제곱할 횟수
	unsigned long long B;

    //N과 B를 입력받은 뒤
	scanf("%d %lld", &N, &B);
    //A와 ret의 크기를 정해주고
	A = matrix(N); ret = matrix(N);

    //A의 각 성분을 입력받는다
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
        {
            if (row == col) ret.mat[row][col] = 1;
            scanf("%d", &A.mat[row][col]);
        }

    //B를 2진수로 보았을 때
	while (B)
	{
        //B의 각 자리수가 1일 때 ret에 A를 곱해준 뒤
		if (B % 2) ret = ret * A;
        //A를 제곱해둔 뒤
        A = A * A;
        //B의 다음 자리수를 확인한다
		B >>= 1;
	}

    //A ^ B를 출력한다
	ret.print();

	return 0;
}