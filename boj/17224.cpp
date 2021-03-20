#include <algorithm>
#include <cstdio>

//sub[i][j]: i번 문제의 (j == 0: 쉬움, 1: 쉬움+어려움)의 점수
//solve[i]: i번 문제를 풀었을 때 얻을 수 있는 최대 점수
int sub[100][2], solve[100];

int main()
{
	//N: 문제의 수, L: 역량, K: 문제의 최대 갯수
	int N, L, K;
	//N, L, K를 입력받는다
	scanf("%d %d %d", &N, &L, &K);

	//각 문제의 난이도를 입력받는다
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &sub[i][0], &sub[i][1]);
		//문제를 풀 수 있다면 해당 점수만큼 solve의 값을 더한다
		if (sub[i][0] <= L) solve[i] += 100;
		if (sub[i][1] <= L) solve[i] += 40;
	}

	//점수를 정렬하여 작은 순서대로 나열한다
	std::sort(solve, solve + N);

	//출력할 값을 저장할 공간으로 L을 사용
	L = 0;
	//얻을 수 있는 가장 큰 점수부터 K개 점수를 더한다
	for (int i = 1; i <= K; i++) L += solve[N - i];
	//얻을 수 있는 최대 점수를 출력한다
	printf("%d\n", L);

    return 0;
}