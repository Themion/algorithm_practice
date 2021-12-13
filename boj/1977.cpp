#include <cmath>
#include <cstdio>

// 1부터 n까지의 제곱의 합
int sigma(int n) { return n * (n + 1) * (2 * n + 1) / 6; }

int main() {
    // M, N: 주어진 수의 범위, min: 범위 내의 가장 작은 완전제곱수의 제곱근
    int M, N;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &M, &N);

    // 범위 내의 완전제곱수 중 가장 작은 수와 큰 수의 제곱근을 각각 M, N에 저장
    M = ceil(sqrt(M));
    N = sqrt(N);

    // M이 N보다 작거나 같다면 주어진 범위 사이에 완전제곱수가 있으므로
    // 주어진 범위 사이의 완전제곱수의 합은 1부터 각 제곱근까지의 제곱의 합의 차
    // 완전제곱수의 최솟값은 M의 제곱이다.
    if (M <= N) printf("%d\n%d\n", sigma(N) - sigma(M - 1), M * M);
    else printf("-1\n");

    return 0;
}
