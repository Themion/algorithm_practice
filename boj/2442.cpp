#include <cstdio>

int main()
{
	//출력에 사용할 수를 입력받는다
	int input;
	scanf("%d", &input);

	//각 줄마다
	for (int i = 1; i <= input; i++)
	{
		int temp = 2 * i - 1;

		//공백을 칸에 맞게 출력한 뒤
		for (int j = 0; j < input - i; j++) printf(" ");

		//줄 넘버만큼 별을 출력
		for (int j = 0; j < temp; j++) printf("*");
		printf("\n");
	}

    return 0;
}