#include <cstdio>
#include <vector>

int ret[501][501], sum[501];

int main()
{
    //tc: 테스트 케이스의 수, size: 각 테스트 케이스에서 파일의 수
	int tc, size;
	scanf("%d", &tc);

    //각 테스트 케이스마다
	while (tc--)
	{
        //파일의 수와 각 파일의 크기를 입력받는다
		scanf("%d", &size);
		for (int i = 1; i <= size; i++)
		{
			scanf("%d", &ret[i][i]);
            //1번 파일부터 i번 파일까지의 합을 sum[i]에 저장한다
			sum[i] = sum[i - 1] + ret[i][i];
		}

        //연속한 파일을 두 개 이상 결합하는 경우에 대해
		for (int s = 1; s <= size; s++)
		{
            //연속된 파일의 시작점을 i로 본다면
			for (int i = 1; i + s <= size; i++)
			{
                //우선 불가능한 경우를 집어넣고
				ret[i][i + s] = 0x3f3f3f3f;

                //연속한 파일을 두 그룹으로 찢었을 때 가중치가 최소가 되는 지점 k를 찾는다
				for (int k = i; k < i + s; k++)
				{
					if (ret[i][i + s] > ret[i][k] + ret[k + 1][i + s])
						ret[i][i + s] = ret[i][k] + ret[k + 1][i + s];
				}

                //i번 파일부터 i + s번 파일까지 합칠 경우 sum[i + s] - sum[i - 1]만큼의 비용이 소모된다
				ret[i][i + s] += sum[i + s] - sum[i - 1];
			}
		}

        //전부 계산했을 때 ret[1][size]값은 모든 파일의 가중치만큼 더 커져있을 것이므로
        //sum[size]만큼 뺀 값을 출력한다
		printf("%d\n", ret[1][size] - sum[size]);
	}

	return 0;
}