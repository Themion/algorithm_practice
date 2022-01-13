#include <cstdio>

int main() {
    int N;
    // 개교한 해가 1946이므로 년도 N은 개교 (N - 1946)주년이다
    scanf("%d", &N);
    printf("%d\n", N - 1946);

    return 0;
}
