#include <cstdio>

int main() {
    int x, ans = 0;
    scanf("%d", &x);
    // x를 2진법으로 나타내면 어떤 토막이 필요한지 알 수 있다.
    for (int i = 1; i <= 64; i *= 2) ans += (x & i) == i;

    printf("%d\n", ans);

    return 0;
}
