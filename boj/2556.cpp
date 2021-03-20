#include <cstdio>

int main()
{
	//출력할 별의 최다 개수를 입력
	int count;
	scanf("%d", &count);

	//count개의 별을 count줄 출력한다
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++) printf("*");
		printf("\n");
	}

    return 0;
}