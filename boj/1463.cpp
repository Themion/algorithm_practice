#include <cstdio>

#define MAX 0x3f3f3f3f

// cnt[i]: i에서 1로 바꿀 때 필요한 연산의 수
int cnt[1000001];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
	// div: 어느 수가 2 혹은 3으로 나누어 떨어질 수 있다면 그 연산 수를,
	//      그렇지 않다면 매우 큰 수를 저장
	int X, div[2];
	scanf("%d", &X);

	// 2부터 차례로 연산 횟수를 계산
	for (int i = 2; i <= X; i++)
	{
		// i가 3 혹은 2로 나누어 떨어질 수 있다면 그 연산 횟수를 가져온다
		div[0] = (i % 3 == 0) ? cnt[i / 3] : MAX;
        div[1] = (i % 2 == 0) ? cnt[i / 2] : MAX;

		// i에서 변환 가능한 수 중 1로 만드는 연산 횟수가 가장 적은 수로 변환
		// 변환하는데 1만큼의 연산이 소모됨
		cnt[i] = min(cnt[i - 1], min(div[0], div[1])) + 1;
	}

	// 최소 연산 횟수 출력
	printf("%d\n", cnt[X]);

    return 0;
}