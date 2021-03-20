#include <cstdio>

int main()
{
	//출력할 별의 최다 개수를 입력
	int count;
	scanf("%d", &count);
	
	//각 줄마다 별을 하나부터 count까지 앞에 공백을 넣어서 일정 간격으로 출력
	for (int i = 1; i <= count; i++)
	{
		int range = count - i;
		for (int j = 0;		j < range; j++) printf(" ");
		for (int j = range;	j < count; j++) printf("*");
		printf("\n");
	}

	//각 줄마다 별을 count - 1부터 하나까지 앞에 공백을 넣어서 일정 간격으로 출력
	for (int i = count - 1; i > 0; i--)
	{
		int range = count - i;
		for (int j = 0;		j < range; j++) printf(" ");
		for (int j = range; j < count; j++) printf("*");
		printf("\n");
	}

    return 0;
}