#include <cstdio>

int main() {
    int N;
    int ans = 0;
    int buf = 0, prev = 0;
    for (scanf("%d", &N); N--;) {
        scanf("%d", &buf);
        if (buf - prev > 1) ans += buf;
        prev = buf; 
    }

    printf("%d\n", ans);

    return 0;
}
