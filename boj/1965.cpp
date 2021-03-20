#include <cstdio>

//size[i]: i번째 상자의 크기
//dp[i]: 0번째부터 i번째까지 상자 중 한 줄에 넣을 수 있는 최대의 상자 개수
int size[1000], dp[1000];

int main()
{
	//n: 상자의 개수, max: 동적 계획법을 사용하면서 가장 큰 dp값을 저장할 공간
	int n, max = 0;
	//상자의 개수와 각 상자의 크기를 입력받는다
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &size[i]);

	//각 상자에 대해
	for (int i = 0; i < n; i++)
	{
		//자신보다 앞의 상자 중 더 작은 상자가 있다면
		for (int j = 0; j < i; j++)
			//그 상자와 자신이 포함한 상자의 수를 비교해
			if ((dp[i] <= dp[j]) && (size[i] > size[j]))
				//더 큰 쪽을 자신 안에 집어넣게 만든다
				dp[i] = dp[j] + 1;

		//이렇게 구한 상자 안의 상자의 개수가 max값보다 크다면 max값을 갱신한다
        if(max < dp[i]) max = dp[i];
	}

	//max값은 가장 큰 상자 안의 상자의 개수이므로
	//max에 1을 더해 출력한다
	printf("%d\n", max + 1);

	return 0;
}