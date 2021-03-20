#include <cstdio>

int main()
{
	//출력에 사용할 수를 입력받음
	int input;
	scanf("%d", &input);

	//1부터 9까지 입력받은 수와 i의 곱을 출력
	for (int i = 1; i <= 9; i++) 
        printf("%d * %d = %d", input, i, input * i);

    return 0;
}