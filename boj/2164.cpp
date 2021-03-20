#include <cstdio>

//카드 덱을 큐의 형태로 저장
int card[500000];

int main()
{
	//N: 덱의 초기 카드 수, start, end: 덱의 시작과 끝의 인덱스
	int N, start, end;

	//덱의 크기를 입력받아 이에 맞는 덱을 만든다
	scanf("%d", &N);
    //N은 가변적이므로 N을 다른 곳에 저장해둔다
	const int size = N;
	for (int i = 0; i < size; i++) card[i] = i + 1;

	//시작과 끝 인덱스를 지정해준 뒤
	start = 0; end = N - 1;
	//덱의 매수가 1이 될 때까지
	while (N > 1)
	{
		//맨 위 카드를 버린 뒤
		card[start] = 0;
		start = (start + 1) % size;
        //카드 매수가 한 장 줄었으므로 이를 저장하고
		N -= 1;

		//맨 위 카드를 맨 아래 카드의 밑으로 옮긴다
		end = (end + 1) % size;
		card[end] = card[start];
		card[start] = 0;
		start = (start + 1) % size;
	}

	//마지막으로 남은 카드를 출력한다
	printf("%d\n", card[end]);

    return 0;
}