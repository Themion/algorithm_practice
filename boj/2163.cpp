#include <cstdio>

int main()
{
	//n * m 크기 초콜릿을 1 * 1개의 초콜릿들로 나누는 횟수는 n * m - 1이다
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", n * m - 1);

	return 0;
}