#include <cstdio>

int main()
{
	//피보나치 수의 계산은 크기 3짜리 배열로 충분히 가능하다
	int fib[3] = { 0, 1, 1 };
	//cnt: 계산할 피보나치 수의 번호
	//lmt: 피보나치 수의 순환을 구하기 위한 변수
	unsigned long long cnt, lmt = 3;
	
	//수열에서 처음으로 0이 나온 경우 그 다음 수는 반드시 0 직전 수이다
	//따라서 0 직후의 수가 1이라면 0 직전의 수도 1이므로 
	//fib[0] + fib[1] + fib[2] == 2인 경우 이 세 수는 반드시
	//주기의 맨 마지막 수, 주기의 맨 처음 수, 주기의 두번째 수이다
	while (1)
	{
		fib[(lmt++) % 3] = (fib[(lmt - 1) % 3] + fib[(lmt - 2) % 3]) % 1000000;
		if (fib[0] + fib[1] + fib[2] == 2) break;
	}

	//주기의 맨 처음 수를 0번째로 세었으니 lmt값은 주기 + 1이다
    //또한 연산하면서 lmt에 1을 더 더했으므로 lmt에 1을 더 빼야 한다
	lmt -= 2;

	//cnt를 입력받은 뒤 해당 수를 주기와 나머지 연산을 한다
	scanf("%lld", &cnt);
	cnt %= lmt;

	//cnt번째 피보나치 수를 구한 뒤 출력한다
	for (int i = 2; i <= cnt; i++) fib[i % 3] = (fib[(i - 1) % 3] + fib[(i - 2) % 3]) % 1000000;
	printf("%d\n", fib[cnt % 3]);

    return 0;
}