#include <cstdio>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    int N, M;
    int x, c;
    char d;
    int pos = 1;
    int right, left;

    for (int i = scanf("%d %d", &N, &M) && 1; i < N; i++) {
        right = M + 1;
        left = 0;

        for (int j = scanf("%d ", &x); j <= x; j++) {
            scanf("%d %c", &c, &d);
            if (d == 'L') left = max(left, c);
            if (d == 'R') right = min(right, c);
        }

        if (x == 0) continue;
        else if (right <= pos && pos <= left) 
            pos = left + 1;
        else if (left <= right) {
            if (pos <= left) pos = left + 1;
            if (right <= pos) pos = M + 1;
        }
    }

    printf("%s\n", pos <= M ? "YES" : "NO");

    return 0;
}
