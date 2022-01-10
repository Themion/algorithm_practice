#include <cstdio>

#define MAX 1000000
#define INF 0x3f3f3f3f

char min(char a, char b) { return a < b ? a : b; }

int main() {
    // step[X]: X를 1로 만들기 위한 연산 횟수의 최솟값
    char step[MAX + 1] = { 0, };
    // N: 1로 만들 수, X: 순회용 인덱스
    int N, X = 2;

    // N을 입력받고 2부터 N까지 모든 수에 대해 연산 횟수의 최솟값을 계산
    for (scanf("%d", &N); X <= N; X++)
        step[X] = min(min(X % 3 ? INF : step[X / 3], X % 2 ? INF : step[X / 2]), 
                      step[X - 1]) + 1;

    // N부터 N / 3, N / 2, N - 1 중
    // 1로 만드는 연산 횟수의 최솟값이 가장 작은 수를 차례로 출력
    for (printf("%d\n", step[--X]); N = X; ) {
        printf("%d%c", N, N > 1 ? ' ' : '\n');
        X = N - 1;
        if (!(N % 3) && step[N / 3] < step[X]) X = N / 3;
        if (!(N % 2) && step[N / 2] < step[X]) X = N / 2;
    }

    return 0;
}
