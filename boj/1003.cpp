#include <cstdio>

int main()
{
	//n: 출력할 fib의 수, buf: 입력에 사용할 버퍼
    //fib[i][j]: i번째 피보나치 수를 구할 때 j번째 피보나치 수가 호출되는 횟수
	int n, buf, fib[41][2] = {{1, 0}, {0, 1}};

	//각 fib에 대해 fib[i][0]과 fib[i][1]에 값을 입력
	for (int i = 2; i <= 40; i++) for(int j = 0; j < 2; j++)
        fib[i][j] = fib[i - 1][j] + fib[i - 2][j];

	scanf("%d", &n);

	//각 cse에 대해 fib[cse]에 대해 fib[0]과 fib[1]의 호출 횟수를 출력
	for (int i = 0; i < n; i++)
    {
        scanf("%d", &buf);
        printf("%d %d\n", fib[buf][0], fib[buf][1]);
    }

    return 0;
}