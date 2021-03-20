#include <cstdio>

int main()
{
	//a, b : 입력받은 두 수를 저장할 공간
	//times : 반복 횟수
	int a, b, times;

	//반복 횟수를 입력받는다
	scanf("%d", &times);

	//times가 0이 될 때까지
	for (int i = 0; i < times; i++)
	{
		//a, b를 입력받고 a+b를 출력
		scanf("%d %d", &a, &b);
		printf("Case #%i: %d + %d = %d\n", i + 1, a, b, a + b);
	}

    return 0;
}