#include <cstdio>

//col[i][j] : i번째 집을 j번째 색으로 칠할 때 드는 비용
int col[1000][3];

int main()
{
	//집의 개수
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d", &col[i][0], &col[i][1], &col[i][2]);

		//i가 0이 아닐 때, 즉 이전 집에 대한 정보가 있을 때
		if (i != 0)
		{
			//각 비용에 대해 같은 색으로 칠하는 비용이 아닌 나머지 비용의 최솟값을
			//현재 색으로 칠하는 비용에 더한다
			col[i][0] += (col[i - 1][1] < col[i - 1][2] ? col[i - 1][1] : col[i - 1][2]);
			col[i][1] += (col[i - 1][0] < col[i - 1][2] ? col[i - 1][0] : col[i - 1][2]);
			col[i][2] += (col[i - 1][0] < col[i - 1][1] ? col[i - 1][0] : col[i - 1][1]);
		}
	}

	//코드의 편의성을 위해 num에 1을 빼 준다
	num -= 1;

	//col[num]에는 모든 집의 최소 비용이 저장되어 있으므로
	//이 세 최소비용 중 최솟값을 col[num][0]에 넣는다
	if (col[num][0] > col[num][1]) col[num][0] = col[num][1];
	if (col[num][0] > col[num][2]) col[num][0] = col[num][2];

	//모든 집을 칠할 때 드는 비용의 최솟값을 출력한다
	printf("%d\n", col[num][0]);

    return 0;
}