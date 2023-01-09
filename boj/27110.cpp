#include <cstdio>

int cmp(int a, int b) { return a < b ? a : b; }

int main() {
    int N, A, B, C;
    scanf("%d\n%d %d %d", &N, &A, &B, &C);
    printf("%d", cmp(N, A) + cmp(N, B) + cmp(N, C));
    return 0;
}
