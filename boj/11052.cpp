#include <cstdio>

#define MAX_N 1000

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // N: 구매할 카드의 개수, P[i]: 카드를 i장 구매할 때의 가격의 최댓값
    int N, P[MAX_N + 1] = { 0, };

    // 구매할 카드의 개수를 입력받은 뒤
    scanf("%d", &N);
    // 각 카드의 개수에 대해
    for (int n = 1; n <= N; n++) {
        // 카드가 n개 들어있는 카드팩의 가격을 입력받은 뒤
        scanf("%d", P + n);
        // 카드가 i개와 n - i개 들어있는 카드팩을 각각 구매할 때의 가격과 비교해
        // 더 큰 값으로 갱신
        for (int i = 1; i <= n / 2; i++) P[n] = max(P[n], P[i] + P[n - i]);
    }

    // 카드를 N개 구매할 때의 가격의 최댓값을 출력
    printf("%d\n", P[N]);

    return 0;
}
