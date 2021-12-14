#include <cstdio>

int main() {
    // N * M 크기 초콜릿을 1 * M 크기 초콜릿으로 쪼개는 데에 N - 1회
    // 각 1 * M 크기 초콜릿을 1 * 1 크기 초콜릿으로 쪼개는 데에 M - 1회
    // N - 1 + N * (M - 1) = N - 1 + (N * M - N) = N * M - 1
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%d", N * M - 1);

    return 0;
}
