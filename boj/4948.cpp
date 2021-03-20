#include <cstdio>

int main()
{
	//123456을 매 줄에 써넣기 귀찮아서 상수로 지정
	const int size = 123456;
	//n, cnt: 소수를 계산할 때 사용할 변수
	//sum[i]: 1부터 i까지의 소수의 개수
	int n, cnt, sum[size * 2 + 1] = { 0, };
	//num[i]: i가 소수라면 false, 아니라면 true
	bool num[size * 2 + 1] = { false, };
	//0과 1은 소수가 아님이 자명하다
	num[0] = true; num[1] = true;

	//2부터 size까지 해당 수가 소수가 아니라면
	for (n = 2; n <= size; n++) if(!num[n])
	{
		//해당 수의 배수들은 전부 소수가 아니다
		cnt = 2;
		while (n * cnt <= size * 2) num[n * cnt++] = true;
	}
	//sum[i]의 값은 i가 소수일 때 sum[i - 1] + 1이고 
	//i가 소수가 아닐 때 sum[i]이다
	for (n = 1; n <= size * 2; n++) sum[n] = sum[n - 1] + !num[n];

	//n이 0이 아닐 때 sum[2 * n] - sum[n]을 출력한다
	while((scanf("%d", &n) == 1) && (n != 0)) 
        printf("%d\n", sum[2 * n] - sum[n]);

    return 0;
}