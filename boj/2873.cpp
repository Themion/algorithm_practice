#include <cstdio>

//롤러코스터의 기쁨 지수를 저장할 공간
int roll[1000][1000];

int main()
{
	//R, C: 롤러코스터의 행과 열의 크기
	//r_min: R과 C가 모두 양수일 때 이동하지 않을 위치의 기쁨 지수
	//place: R과 C가 모두 양수일 때 이동하지 않을 위치의 좌표
	int R, C, r_min = 0x3f3f3f3f, place[2] = { 0, 1 };
    
	scanf("%d %d", &R, &C);

	//R과 C가 모두 양수일 때 예외처리를 위한 변수
	bool yes = (R % 2 == 0) && (C % 2 == 0);

	//롤러코스터의 기쁨 지수와 r_min을 입력
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			//각 기쁨 지수를 입력
			scanf("%d", &roll[i][j]);

			//R과 C가 모두 양수라면
			if ((yes) && ((i + j) % 2 == 1))
			{
				//roll[i][j]가 이동하지 않을 칸보다 작다면
				if (r_min > roll[i][j])
				{
					//r_min과 place를 변경
					r_min = roll[i][j];
					place[0] = i;
					place[1] = j;
				}
			}
		}
	}

	//행의 개수가 홀수라면 모든 위치를 전부 지날 수 있다
	if (R % 2 == 1)
	{
		for (int i = 0; i < (R / 2); i++)
		{
			for (int j = 1; j < C; j++) printf("R");
			printf("D");
			for (int j = 1; j < C; j++) printf("L");
			printf("D");
		}

		for (int j = 1; j < C; j++) printf("R");
	}

	//열의 개수가 홀수라면 모든 위치를 전부 지날 수 있다
	else if (C % 2 == 1)
	{
		for (int i = 0; i < (C / 2); i++)
		{
			for (int j = 1; j < R; j++) printf("D");
			printf("R");
			for (int j = 1; j < R; j++) printf("U");
			printf("R");
		}

		for (int j = 1; j < R; j++) printf("D");
	}

	//행과 열이 모두 짝수라면 어느 칸 하나를 지날 수 없다
	else
	{
		int pivot = place[0] / 2;

		for (int i = 0; i < pivot; i++)
		{
			for (int j = 1; j < C; j++) printf("R");
			printf("D");
			for (int j = 1; j < C; j++) printf("L");
			printf("D");
		}

		//가상의 점 p는 p의 x좌표값을 2로 나눈 값 k가 pivot과 같은 구간에 존재하는 움직이는 점이다.
		//now는 p의 x좌표와 y좌표의 값을 각각 2로 나눈 값을 저장한다.
		//place의 y좌표의 값을 2로 나눴을 때 그 값이 now[1]과 같을 때까지 p를 N자 모양으로 움직인 뒤,
		//place를 회피하기 위해 특수한 행동을 행할 것이다.
		//이 이후는 p를 다시 N자 모양으로 움직인다.
		int now[2] = { pivot * 2, 0 };

		while (now[1] < (place[1] / 2))
		{
			printf("DRUR");
			now[1] += 1;
		}

		if (place[0] % 2 == 1)  printf("RD");
		else					printf("DR");

		now[1] += 1;

		while (now[1] < (C / 2))
		{
            printf("RURD");
			now[1] += 1;
		}

		for (int i = pivot + 1; i < R / 2; i++)
		{
			printf("D");
			for (int j = 1; j < C; j++) printf("L");
			printf("D");
			for (int j = 1; j < C; j++) printf("R");
		}
	}

	printf("\n");

    return 0;
}