#include <cstdio>

//lst[i]: 3 * (2 * i) 크기의 벽을 채우는 경우의 수
int lst[16];

int main()
{
	//3 * N 크기의 벽을 타일로 채우는 경우를 구한다
	int n;
	scanf("%d", &n);

	//3×(홀수) 크기의 벽은 완벽하게 채울 수 없다
	if (n % 2 != 1) 
	{
		//원래대로라면 lst[0] = 0이지만 알고리즘을 위해 1로 설정
		lst[0] = 1;
		//3*2에 배치할 수 있는 경우의 수는 3
		lst[1] = 3;

		//동적 계획법을 사용하여 문제를 해결
		//lst[i] = lst[1] * lst[i - 1] + 2(lst[0] + lst[1] + ... + lst[i - 2])
		for (int i = 2; i <= (n / 2); i++)
		{
			lst[i] = lst[1] * lst[i - 1];
			for (int j = 0; j < i - 1; j++) lst[i] += 2 * lst[j];
		}
    }

    printf("%d\n", lst[n / 2]);

    return 0;
}