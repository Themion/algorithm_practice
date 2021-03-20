#include <cstdio>

int main()
{
	//x는 달, y는 일
	int x, y, count = 0;
	scanf("%d %d", &x, &y);
	char day[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	//x월 y일부터 1일씩 빼가면서 요일을 계산
	//1월 1일에 멈춤
	while (x != 1 || y != 1)
	{
		//하루 빼고 count를 1 더함
		y -= 1;
		count += 1;

		//만일 k월 0일이 되었을 경우
		//k를 1 빼준 뒤 k월에 맞는 말일로 y를 변경 
		if (y == 0)
		{
			x -= 1;

			if (x == 2) y = 28;
			else if ((x == 4) || (x == 6) || (x == 9) || (x == 11)) y = 30;
			else y = 31;
		}
	}

	//count를 7로 나눈 나머지를 이용해 요일을 출력한다
	printf("%s\n", day[count % 7]);

    return 0;
}