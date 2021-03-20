#include <cstdio>

//[i][j] 칸이 검은 색이면 true, 아니라면 false
bool board[50][50];

int main()
{
	//x,y : 판자의 사이즈, min : 칠해야 하는 최소 횟수
	//res : 판자를 잘라낸 뒤 칠하는 횟수를 셀 때 쓸 변수
	int x, y, min = 2500, res[2] = { 0 };
	//입력을 버퍼를 통해 받는다
	char buf;

	//판자의 크기와 칠해진 상태를 입력받는다
	scanf("%d %d\n", &x, &y);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			scanf("%c", &buf);
			if (buf == 'B') board[i][j] = true;
			else board[i][j] = false;
		}
        //개행문자는 날린다
		scanf("%*c");
	}

	//판자가 8*8 크기가 될 수 있는 모든 경우에 대해
	for (int xx = 0; xx <= x - 8; xx++) for (int yy = 0; yy <= y - 8; yy++)
	{
		//맨 처음은 칠하지 않은 상태이다
		res[0] = 0; res[1] = 0;

		//판자를 흰검흰검...으로 칠하는 횟수와 검흰검흰... 으로 칠하는 횟수를 센다
		for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)
		{
			if (board[xx + i][yy + j] == (i + j) % 2) res[0] += 1;
			else res[1] += 1;
		}

		//두 칠하는 횟수 중 더 작은 쪽을 res[0]에 저장한다
		if (res[0] > res[1]) res[0] = res[1];
		//min과 res[0]을 비교해 더 작은 쪽을 min에 저장한다
		if (min > res[0]) min = res[0];
	}

	//min을 출력한다
	printf("%d\n", min);

    return 0;
}