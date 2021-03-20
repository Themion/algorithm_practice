#include <cstdio>

int tri[31][31];

int main()
{
    //tc: 테스트 케이스의 수
    //n, k: 파스칼의 삼각형으로 다리의 수를 구한다
	int tc, n, k;

    //테스트 케이스를 입력받은 뒤
	scanf("%d", &tc);
    //각 테스트 케이스마다
    while(tc--)
    {
        //컴비네이션을 구할 n과 k를 구한다
        scanf("%d %d", &k, &n);

        //n^2시간에 컴비네이션을 구한다
        for (int i = 1; i <= n; i++)
        {
            tri[i][0] = 1;
            tri[i][i] = 1;

            for (int j = 1; j < i; j++)
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }

        //해당 테스트 케이스의 컴비네이선을 출력한다
        printf("%d\n", tri[n][k]);
    }

	return 0;
}