#include <cstdio>

int main() {
    // 1부터 n까지 더하는 공식은 n * (n * 1) / 2이다
    int n;
    scanf("%d", &n);
    printf("%d\n", n * (n + 1) / 2);

    return 0;
}
