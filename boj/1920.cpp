#include <algorithm>
#include <cstdio>

//배열을 저장할 컨테이너
int find[100000];

int main()
{
	//size: 배열의 실제 크기
	//t: 찾을 수의 개수, buf: 찾을 수를 저장할 공간
	int size, t, buf;

	//배열의 크기와 해당 크기만큼의 배열을 입력받은 뒤 정렬한다
	scanf("%d", &size);
	for (int i = 0; i < size; i++) scanf("%d", &find[i]);
	std::sort(find, find + size);

	//찾을 수의 개수를 입력받은 뒤
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		//해당 횟수만큼 수를 입력받아 이진탐색을 실행한다
		scanf("%d", &buf);
		printf("%d\n", std::binary_search(find, find + size, buf));
	}

	return 0;
}