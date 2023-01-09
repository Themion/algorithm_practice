#include <cstdio>

#define MAX_A 200000

int main() {
    int N, a, b, ans = 0;
    bool bunker[MAX_A + 1] = { 0, };

    for (scanf("%d", &N); N--;) {
        scanf("%d %d", &a, &b); 
        ans += bunker[a] == b;
        bunker[a] = b;
    }

    for (a = 1; a <= MAX_A; a++) ans += bunker[a];

    printf("%d\n", ans);

    return 0;
}
