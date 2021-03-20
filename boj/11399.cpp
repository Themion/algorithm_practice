#include <algorithm>
#include <cstdio>

//인덱스 번째 사람이 돈을 인출하는데 걸리는 시간
int cont[1001];

int main()
{
	//size : 실제로 쓰이는 cont의 크기
	//ret : 각 사람이 돈을 인출하는데 필요한 시간의 합
	int size, ret = 0;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++) scanf("%d", &cont[i]);

	//i번째 사람이 기다리는 시간은 1번부터 i-1번째 사람이 돈을 인출하는데 걸린 시간의 총합이다
	//즉 인덱스가 작을수록 해당 인덱스의 값 역시 작아야 한다
	std::sort(cont + 1, cont + size + 1);
	//시간 복잡도를 줄이기 위해 cont[0]을 가중치로 둔다
	cont[0] = size;

	//ret에 i번째 사람이 걸리는 시간 * 가중치를 더한다
	//가중치는 size부터 시작해서 인덱스가 1 늘수록 1씩 준다
	for (int i = 1; i <= size; i++)
	{
		ret += cont[i] * cont[0];
		cont[0] -= 1;
	}

	//ret을 출력한다
	printf("%d\n", ret);

    return 0;
}