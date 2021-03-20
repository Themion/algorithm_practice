#include <cstdio>

int main()
{
	//글자를 하나씩 입력받을 버퍼
	char buf;
	//글자가 들어온 횟수를 센다
	int count = 0;

	//buf에 글자가 하나씩 들어올 때마다
	while (scanf("%c", &buf) == 1)
	{
		//글자를 그대로 출력
		printf("%c", buf);
		//글자가 들어온 횟수를 1 추가
		count += 1;

		//글자가 열 번 들어올 때마다 줄을 바꾼 뒤 count를 0으로 초기화
		if (count == 10)
		{
			printf("\n");
			count = 0;
		}
	}

    return 0;
}