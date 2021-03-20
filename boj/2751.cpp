#include <algorithm>
#include <cstdio>

//입력받은 배열을 저장할 컨테이너
int cont[1000000];

int main()
{
	//입력받은 자연수의 개수
	int n;
	scanf("%i", &n);

	//배열을 입력받음
	for (int i = 0; i < n; i++) scanf("%i", &cont[i]);

	//STL을 이용하여 정렬
	std::sort(cont, cont + n);

	//정렬된 배열을 출력
	for (int i = 0; i < n; i++) printf("%i\n", cont[i]);

    return 0;
}