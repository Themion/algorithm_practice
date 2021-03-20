#include <cstdio>

int main()
{
	//출력할 별의 최다 개수를 입력
	int count;
	scanf("%d", &count);

	for (int i = 1; i <= count; i++)
	{
		//for문에 사용할 임시 변수
		int range = count - i;
		//i번째 줄에 대해 count - i만큼 미리 간격을 띄운다
		for (int j = 0; j < range; j++) printf(" ");
		printf("*");

		//i - 1회만큼 ' *'를 출력한다
		range = i - 1;
		for (int j = 0; j < range; j++) printf(" *");
		printf("\n");
	}

    return 0;
}