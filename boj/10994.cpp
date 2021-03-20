#include <cstdio>

//정사각형 도형을 저장할 공간
bool ret[401][401];

int main()
{
	//입력받은 수를 출력할 정사각형 도형의 한 변의 길이로 변환
	int size;
	scanf("%d", &size);
	size = 4 * size - 3;
	
	//rng: size - 1을 따로 저장한다
	//alpha: 정사각형 도형을 프랙탈화 시킬 때 사용
	int rng = size - 1, alpha = 0;

	//rng / 2회만큼 반복
	while (rng >= 2 * alpha)
	{
		// 정중앙에 위치하는 rng - (2 * alpha) 크기의 정사각형 테두리를 만든다
		for (int i = alpha; i <= rng - alpha; i++)
		{
			ret[i][alpha] = true;
			ret[alpha][i] = true;

			ret[rng - i][rng - alpha] = true;
			ret[rng - alpha][rng - i] = true;
		}

		//각 테두리 사이의 간격이 2이므로 alpha를 2씩 더한다
		alpha += 2;
	}

	//ret[i][j]값이 true면 *을, 아니라면 공백을 출력
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (ret[i][j]) printf("*");
			else printf(" ");
		}

		printf("\n");
	}

	return 0;
}