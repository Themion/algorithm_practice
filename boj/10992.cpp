#include <cstdio>

int main()
{
	//출력할 별의 최다 개수를 입력
	int count;
	scanf("%d", &count);

	//맨 아래줄을 제외하기 위해서 count를 하나 빼 준다
	count -= 1;

	//맨 아랫줄을 제외한 각 줄에 대해 ㅅ자를 그린다
	for (int i = 1; i <= count; i++)
	{
		//for문에 사용할 임시 변수
		int range = count - i + 1;
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
	}

	//맨 밑줄을 *로 모두 채운다
	count = 2 * count + 1;
	for (int i = 0; i < count; i++) printf("*");
	printf("\n");

    return 0;
}