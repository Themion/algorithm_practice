#include <cstdio>

//used[i]: 알파벳 i + 'A'를 이미 지났다면 true, 아니라면 false
bool used[26];
//알파벳 보드를 저장할 공간
char arr[20][20];
//r, c: 알파벳 보드의 크기, max: 현재까지 지난 최대 칸 수
int r, c, max = 0;

//좌표 (x, y)를 cnt번만에 도착했을 때 다음으로 갈 곳을 찾는다
void step(int x, int y, int cnt)
{
	//만일 현재 발판의 알파벳이 이미 지난 알파벳인 경우
	if (!used[arr[x][y] - 'A'])
	{
		//현재 알파벳을 지났음을 표시한 뒤
		used[arr[x][y] - 'A'] = true;
		//현재까지 지난 발판의 수를 하나 늘리고
		cnt += 1;
		//max를 갱신한다
		if (max < cnt) max = cnt;

		//현재 발판의 상하좌우가 존재한다면 해당 칸에 대해서 같은 과정을 실행한다
		if (x - 1 >= 0) step(x - 1, y, cnt);
		if (x + 1 < r) step(x + 1, y, cnt);
		if (y - 1 >= 0) step(x, y - 1, cnt);
		if (y + 1 < c) step(x, y + 1, cnt);

		//현재 칸의 알파벳을 지나지 않았던 것으로 계산한다
		used[arr[x][y] - 'A'] = false;
	}
}

int main()
{
	//보드의 크기와 각 칸을 입력받는다
	scanf("%d %d%*c", &r, &c);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) scanf("%c", &arr[i][j]);
		scanf("%*c");
	}

	//DFS를 실행한 다음 최대 이동 횟수를 출력한다
	step(0, 0, 0);
	printf("%d", max);

	return 0;
}