#include <cstdio>

int main() {
    // 구구단을 출력할 수
    int N;

    scanf("%d", &N);
    // 구구단의 N단을 출력
    for (int i = 1; i <= 9; i++) printf("%d * %d = %d", N, i, N * i);

    return 0;
}
