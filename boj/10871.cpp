#include <cstdio>

//cont : 입력받은 수들을 저장할 공간. 변수 하나를 쓰는 것보다 배열이 더 빠르다
int cont[10000];

int main()
{
	//range : 입력받을 수의 개수
	//target : 각 수가 이 수보다 크면 출력한다
	int range, target;
	scanf("%d %d", &range, &target);

	//range만큼 수를 입력받은 뒤 target과 비교해 더 작으면 출력한다
	for (int i = 0; i < range; i++)
	{
		scanf("%d", &cont[i]);
		if (cont[i] < target) printf("%d ", cont[i]);
	}

	printf("\n");

    return 0;
}