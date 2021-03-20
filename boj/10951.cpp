#include <cstdio>

int main()
{
	//입력받은 두 수를 저장할 공간
	int a, b;
	//입력을 받을 동안 그대로 출력
	while (scanf("%d %d", &a, &b) == 2) printf("%d\n", a + b);

    return 0;
}