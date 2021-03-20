#include <cstdio>

int main()
{
	//출력할 별의 최다 개수를 입력
	int count;
	scanf("%d", &count);

	//별을 ㅅ 모양으로 출력한다
	for (int i = 1; i <= count; i++)
	{
		//for문에 사용할 임시 변수
		int range = count - i;
		//i번째 줄에 대해 count - i만큼 미리 간격을 띄운다
		for (int j = 0; j < range; j++) printf(" ");
		//ㅅ의 왼쪽 변 출력
		printf("*");

		range = 2 * i - 3;
		
		//i가 1이라면, 즉 ㅅ의 꼭지점 부분이 아니라면
		if (range > 0)
		{
			//ㅅ의 양 변 사이 간격을 출력한 뒤
			for (int j = 0; j < range; j++) printf(" ");
			//ㅅ의 오른쪽 변 출력
			printf("*");
		}

		printf("\n");
	}

    return 0;
}