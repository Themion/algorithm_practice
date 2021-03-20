#include <cstdio>

int main()
{
	//세 자리 수 a, b를 받아와서 역순으로 만든 뒤 더 큰 수를 출력한다
	int a, b;
	scanf("%d %d", &a, &b);

	a = 100 * (a % 10) + (a / 100) + 10 * ((a / 10) % 10);
	b = 100 * (b % 10) + (b / 100) + 10 * ((b / 10) % 10);

	if (a > b) printf("%d\n", a);
	else printf("%d\n", b);

    return 0;
}