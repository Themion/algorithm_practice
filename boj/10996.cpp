#include <cstdio>

int main()
{
	//도형의 높이를 입력받는다
	int num;
	scanf("%d", &num);

	//각 줄에 대해서
	for (int i = 0; i < num * 2; i++)
	{
        //해당 줄이 짝수 줄이라면 ' ' 먼저, 홀수 줄이라면 '*' 먼저
		for (int j = i % 2; j < num + i % 2; j++)
        {
            //' '와 '*'을 num회 번갈아 출력한다
            if (j % 2) printf(" ");
            else       printf("*");
        }
		printf("\n");
	}

	return 0;
}