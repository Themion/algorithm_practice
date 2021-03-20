#include <cstdio>

//파스칼의 삼각형을 저장할 공간
short tri[2][1000];

int main()
{
	//n, k: 이항계수 (n k)를 구할 때 쓸 변수
	int n, k;
	//i % 2, (i - 1) % 2를 축약시킴
	bool trig;
	scanf("%d %d", &n, &k);

	//삼각형의 각 층에 대해
	for (int i = 0; i <= n; i++)
	{
		trig = i % 2;
		//삼각형의 두 옆변은 반드시 1이다
		tri[trig][0] = 1;
		tri[trig][i] = 1;

		//삼각형 안의 값을 채운다
		for (int j = 1; j < i; j++)
			tri[trig][j] = (tri[!trig][j - 1] + tri[!trig][j]) % 10007;
	}

	//이항계수 값을 출력한다
	printf("%d\n", tri[n % 2][k]);

	return 0;
}