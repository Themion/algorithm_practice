#include <cstdio>

int main()
{
	//출력할 별의 최다 개수를 입력
	int count;
	scanf("%d", &count);

	//각 줄마다 별을 하나부터 count까지 출력
	for (int i = 1; i <= count; i++)
	{
		int range = count - i;
		for (int j = range; j < count; j++) printf("*");
		printf("\n");
	}

	//각 줄마다 별을 count - 1부터 하나까지 출력
	for (int i = count - 1; i > 0; i--)
	{
		int range = count - i;
		for (int j = range; j < count; j++) printf("*");
		printf("\n");
	}

    return 0;
}