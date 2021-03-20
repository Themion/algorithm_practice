#include <cstdio>
#include <vector>

int main()
{
	//N: 배열의 크기, K: 순열의 간격
	//idx: 인덱싱에 쓸 변수
	int N, K, idx = 0;
	
	//N과 K를 입력받는다
	scanf("%d %d", &N, &K);
	//순열에 N만큼의 공간을 만든다 뒤 값을 채운다
	std::vector<int> num(N);
	for (int i = 0; i < N; i++) num[i] = i + 1;

	//순열 출력 시작
	printf("<");

	//순열의 각 순번에 대해
	for (int i = 0; i < N; i++)
	{
		//순열의 i - 1번째 성분을 이용해 i번째 성분을 구한다
		idx = (idx + K - 1) % num.size();

		//순열의 i번째 성분을 출력한 뒤 해당 성분을 순열에서 제거한다
		printf("%d", num[idx]);
		num.erase(num.begin() + idx);
		//해당 성분이 마지막 성분이 아니라면 컴마를 출력해야 한다
		if (i < N - 1) printf(", ");
	}

	//순열의 출력이 끝났다면 괄호를 닫는다
	printf(">\n");

    return 0;
}