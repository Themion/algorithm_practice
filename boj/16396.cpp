#include <cstdio>

//선분이 어디서 몇 개 시작되고 끝나는지 저장
int cont[10001];

int main()
{
	//start, end : 각 선분의 시작과 끝
	//cases : 선분의 개수
	//lines : 0부터 10000까지 읽을 때, 현재 읽고 있는 곳이 선분이 있는지 확인
	//ret : 직선 좌표에 투사된 선의 총 길이 합
	int start, end, cases, lines = 0, ret = 0;
	scanf("%d", &cases);
	for (int c = 0; c < cases; c++)
	{
		scanf("%d %d", &start, &end);
		cont[start] += 1; cont[end] += -1;
	}
	for (int i = 0; i <= 10000; i++)
	{
		lines += cont[i];
		if (lines > 0) ret += 1;
	}

	printf("%d\n", ret);

    return 0;
}