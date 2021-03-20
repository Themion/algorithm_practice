#include <cstdio>

int main()
{
	//자연수 n을 입력받아 n부터 1까지 출력한다
	int num;
	scanf("%d", &num);
	for (int i = num; i > 0; i--) printf("%d\n", i);

    return 0;
}