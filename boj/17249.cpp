#include <cstdio>

int main()
{
	int cnt = 0;
	char buf = '=';

	while (buf != '0')
	{
		scanf("%c", &buf);
		if (buf == '@') cnt += 1;
	}

	printf("%d ", cnt);
	cnt = 0;
	
	while (buf != '\n')
	{
		scanf("%c", &buf);
		if (buf == '@') cnt += 1;
	}

	printf("%d\n", cnt);

    return 0;
}