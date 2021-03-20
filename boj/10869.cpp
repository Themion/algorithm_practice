#include <cstdio>

int main()
{
	//두 수 a, b 사이의 사칙연산 결과값을 출력
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", a + b);
	printf("%d\n", a - b);
	printf("%d\n", a * b);
	printf("%d\n", a / b);
	printf("%d\n", a % b);

	return 0;
}