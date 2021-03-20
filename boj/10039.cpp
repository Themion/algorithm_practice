#include <cstdio>

int main()
{
	//점수 score를 입력받아 ret에 더한 뒤 평균을 구한다
	//이때 점수는 항상 40점 이상인 5의 배수이다
	int score, ret = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &score);
		if (score < 40) score = 40;
		ret += score;
	}

	//점수 다섯의 평균을 출력한다
	printf("%d\n", ret / 5);

    return 0;
}