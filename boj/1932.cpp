#include <cstdio>

//삼각형을 저장할 컨테이너
int tri[500][500];

int main()
{
	//삼각형의 높이,
	int size;
	
	//삼각형을 입력받는다
	scanf("%d", &size);
	for (int i = 0; i < size; i++) for (int j = 0; j <= i; j++) 
		scanf("%d", &tri[i][j]);

	//삼각형의 각 항에 대해
	for (int i = 1; i < size; i++)
	{
		tri[i][0] += tri[i - 1][0];

		//자신 바로 위 항과 그 이전 항을 비교해 더 큰 쪽의 값을 더한다
		for (int j = 1; j <= i + 1; j++)
			tri[i][j] += tri[i - 1][j - 1] > tri[i - 1][j] ? 
						 tri[i - 1][j - 1] : tri[i - 1][j];
	}

	//해당 공간에 tri[size - 1] 배열의 최댓값을 저장한다
	for (int i = 0; i < size; i++) 
		if (tri[0][0] < tri[size - 1][i]) tri[0][0] = tri[size - 1][i];

	//tri[size - 1] 안의 최댓값을 출력한다
	printf("%d\n", tri[0][0]);

    return 0;
}