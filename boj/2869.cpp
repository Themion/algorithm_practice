#include <cstdio>
#include <cmath>

int main() {
    // A: 올라가는 거리, B: 미끄러지는 거리, V: 나무 길이
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);

    // 첫 날부터 마지막 전 날까지 A - b미터를, 마지막 날에는 A 미터를 올라간다
    printf("%d\n", (int)ceil((double)(V - A) / (A - B)) + 1);

    return 0;
}
