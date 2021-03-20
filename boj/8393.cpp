#include <cstdio>

int main()
{
	//num에 숫자를 입력받은 뒤
	//ret에 1부터 num까지의 총합을 저장한다
	int num, ret = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)ret += i;
	printf("%d\n", ret);

    return 0;
}