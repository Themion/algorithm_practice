#include <cstdio>

#define MAX_N (int)1e6
#define INF 0x3f3f3f3f

// cnt[i]: i를 1로 만들기 위한 최소 연산 횟수
short cnt[MAX_N + 1];

short min(short a, short b) { return a < b ? a : b; }

int main() {
	int N;
	scanf("%d", &N);
    // 2부터 N까지 차례대로
	for (int i = 2; i <= N; i++)
        // i - 1, i / 3, i / 2 중 연산 횟수가 가장 작은 값에 연산을 실행
        cnt[i] = 1 + min(cnt[i - 1], 
                         min(i % 3 ? INF : cnt[i / 3],
                             i % 2 ? INF : cnt[i / 2]));

    // N을 1로 만드는 연산의 최소 횟수를 출력
	printf("%d\n", cnt[N]);

    return 0;
}
