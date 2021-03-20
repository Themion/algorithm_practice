#include <cstdio>

int main()
{
	int buf;
	bool attend[30] = { false, };

	for (int i = 0; i < 28; i++)
	{
		scanf("%d", &buf);
		attend[buf - 1] = true;
	}

	for (int i = 0; i < 30; i++) if (!attend[i]) printf("%d\n", i + 1);

    return 0;
}