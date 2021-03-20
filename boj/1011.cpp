#include <cstdio>

int main()
{
	//tc: 테스트 케이스의 수
	//start, end : 시작점과 끝점의 좌표
	int tc, start, end;
	//sum, add, times :	times 횟수만큼 점프할 때의 최대 거리는 sum이며
	//					times가 늘어날 때마다 최대 거리는 add씩 늘어난다
	long long sum, add, times;
	//add를 사용할 때 add가 하나 늘어날지 결정한다
	bool isAdd;

	scanf("%d", &tc);

	//각 테스트 케이스마다
	for (int t = 0; t < tc; t++)
	{
		//start와 end를 입력받고 나머지 변수를 초기화한다
		scanf("%d %d", &start, &end);
		end -= start; start = 0;

		sum = 0; add = 1; times = 0;
		isAdd = false;

		//최대 이동 거리가 이동 거리보다 작다면
		while (sum < end)
		{
			//최대 이동 거리를 가중치만큼 늘린다
			sum += add;
			//같은 가중치만큼 늘린 적이 없다면 표시한다
			if (!isAdd) isAdd = true;
			//같은 가중치만큼 늘린 적이 있다면 표시를 지우고 가중치를 1 늘린다
			else
			{
				isAdd = false;
				add += 1;
			}

			//점프 횟수를 1 늘린다
			times += 1;
		}

		//최소 점프 횟수를 출력
		printf("%lld\n", times);
	}

	return 0;
}