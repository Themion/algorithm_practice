#include <cstdio>

//파스칼의 삼각형을 저장할 공간
int tri[30][30];

int main()
{
	//n, k: 이항계수 (n k)를 구할 때 쓸 변수
	int n, k;
	scanf("%d %d", &n, &k);

	//삼각형의 각 층에 대해
	for (int i = 0; i < n; i++)
	{
		//삼각형의 두 옆변은 반드시 1이다
		tri[i][0] = 1;
		tri[i][i] = 1;

		//삼각형 안의 값을 채운다
		for (int j = 1; j < i; j++) tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
	}

	//행과 열의 인덱스가 0부터 시작하므로
	//n, k값이 1 줄어든 값을 출력한다
	printf("%d\n", tri[n - 1][k - 1]);

	return 0;
}