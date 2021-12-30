#include <cstdio>

int main() {
    // 주어진 수 A, B, C를 이용해 정해진 출력을 출력함
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n", (A + B) % C);
    printf("%d\n", (A % C + B % C) % C);
    printf("%d\n", (A * B) % C);
    printf("%d\n", (A % C * B % C) % C);

    return 0;
}
