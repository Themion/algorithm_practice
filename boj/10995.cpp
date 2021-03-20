#include <cstdio>

int main()
{
	//도형의 높이를 입력받는다
	int num;
	scanf("%d", &num);

	//각 줄에 대해서
	for (int i = 0; i < num; i++)
	{
		//해당 줄이 홀수번째 줄이라면 공백으로 시작한다
		if (i % 2 == 1) printf(" ");
		//" *"을 num - 1번 출력하므로 "*"을 반드시 먼저 출력해준다
		printf("*");
		//패턴의 대부분을 이루는 " * * * ... *"을 출력한다
		for (int i = 1; i < num; i++) printf(" *");
		printf("\n");
	}

	return 0;
}