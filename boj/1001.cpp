#include <cstdio>

int main()
{
	//a, b, 를 저장할 공간
	int a, b;
	//a와 b를 입력받는다
	scanf("%d %d", &a, &b);
	//둘을 뺀 결과를 저장하지 않고 바로 출력
	printf("%d\n", a - b);

    return 0;
}