#include <cstdio>

int main()
{
	int tc, M, N, x, y;
	scanf("%d", &tc);
	while (tc--)
	{
		int a, b, cnt;
		bool rec[40001] = { false, };
		scanf("%d %d %d %d", &M, &N, &x, &y);

		a = (y - 1) % M + 1; b = y; cnt = y - N;

		do
		{
			rec[a] = true;
			cnt += N;
			a = (a - 1 + N) % M + 1;
		} while (!rec[a] && !rec[x]);

		if (!rec[x]) cnt = -1;
		printf("%d\n", cnt);
	}

	return 0;
}