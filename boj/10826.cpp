#include <cstdio>

int const size = 2090;

short arr[3][size];

void fib(short a[], short b[], short ab[])
{
	int add = 0;

	for (int i = 0; i <= size; i++)
	{
		ab[i] = a[i] + b[i] + add;
		if (add != 0) add = 0;

		if (ab[i] >= 10)
		{
			add = ab[i] / 10;
			ab[i] %= 10;
		}
	}
}

int main()
{
	int n, cnt = size - 1;
	scanf("%d", &n);

	arr[1][0] = 1;

	for (int i = 2; i <= n; i++)
		fib(arr[(i - 2) % 3], arr[(i - 1) % 3], arr[i % 3]);

	while ((cnt >= 0) && (arr[n % 3][cnt] == 0)) cnt--;
    if(cnt < 0) cnt = 0;

	for (int i = cnt; i >= 0; i--) printf("%d", arr[n % 3][i]);
	printf("\n");

	return 0;
}