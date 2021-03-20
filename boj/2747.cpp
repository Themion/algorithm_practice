#include <cstdio>

int main()
{
	//피보나치 수를 계산할 때 필요한 공간은 총 세 개이다
	//두 개는 더할 수를 저장한 공간, 나머지 하나는 더한 수를 저장할 공간
	int fib[3] = { 0, 1, }, cnt;
	//몇번째 피보나치 수를 출력할 것인지 입력받음
	scanf("%d", &cnt);
	//cnt번째까지의 피보나치 수를 연산
	for (int i = 2; i <= cnt; i++) fib[i % 3] = fib[(i - 1) % 3] + fib[(i - 2) % 3];
	//cnt번째 피보나치 수를 출력한다
	printf("%d\n", fib[cnt % 3]);

    return 0;
}