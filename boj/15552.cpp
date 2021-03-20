#include <cstdio>

int main()
{
	//num : 테스트 케이스의 수
	//a, b : 더할 두 수
	int num, a, b;

	//테스트 케이스를 입력받는다
	scanf("%d", &num);

	//테스트 케이스만큼 반복
	for (int i = 0; i < num; i++)
	{
		//a와 b를 입력받아 둘의 합을 출력한다
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

    return 0;
}