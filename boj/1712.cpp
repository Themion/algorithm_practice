#include <cstdio>
#include <cmath>

int main() {
    // A: 고정 비용, B: 가변 비용, C: 노트북 가격
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    // 노트북 가격이 가변 비용보다 크다면 고정 비용에 마진(C - B)을 나눈 값을,
    // 그렇지 않다면 -1을 출력
    printf("%d\n", (B < C) ? (A / (C - B) + 1) : -1);

    return 0;
}
