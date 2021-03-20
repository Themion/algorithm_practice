#include <cstdio>

bool graph[1000][1000];

int main()
{
	//N: 문제의 수, M: 문제 간의 관계의 수, Q: 테스트 케이스의 수
	int N, M, Q, start, end;
	//graph[x][y]: y를 풀고 x를 풀어야 함
	//isBroken: break가 사용되었다면 true
	bool isBroken;

	//N, M, Q를 입력받는다
	scanf("%d %d %d", &N, &M, &Q);
	//모든 관계를 입력받는다
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &start, &end);
		//인덱스가 1000까지이므로 start와 end를 1씩 빼야 한다
		graph[start - 1][end - 1] = true;
	}

	//각 테스트 케이스마다
	for (int t = 0; t < Q; t++)
	{
		//서브태스크 1만 사용하므로 문제의 시작과 끝을 입력받는다
		scanf("%*d %d %d", &start, &end);
		//인덱스에 맞도록 1씩 빼 준다
		start -= 1; end -= 1;

		//테스트 케이스 안의 모든 문제에 대해
		for (int i = start; i <= end; i++)
		{
			//문제를 풀 수 있다고 가정
			isBroken = false;

			//start 이전 문제 중 먼저 풀어야 하는 문제가 존재한다면
			for (int j = 0; j < start; j++)
			{
				if (graph[i][j])
				{
					//문제를 풀 수 없음을 표시한 뒤 이를 출력한다
					isBroken = true;
					printf("NO\n");
					break;
				}
			} 
			//문제를 풀 수 없으므로 테스트 케이스를 끝낸다
			if (isBroken) break;

			//end 이후 문제 중 먼저 풀어야 하는 문제가 존재한다면
			for (int j = end + 1; j < N; j++)
			{
				if (graph[i][j])
				{
					//문제를 풀 수 없음을 표시한 뒤 이를 출력한다
					isBroken = true;
					printf("NO\n");
					break;
				}
			}
			//문제를 풀 수 없으므로 테스트 케이스를 끝낸다
			if (isBroken) break;

		}
		//문제를 풀 수 있다면 이를 출력한다
		if (!isBroken) printf("YES\n");
	}

    return 0;
}