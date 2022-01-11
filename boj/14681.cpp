#include <cstdio>

int main() {
    // y, x: 사분면을 판정할 점의 좌표, quad: 사분면의 번호
    int y, x, quad[2][2] = {{2, 1}, {3, 4}};
    // 좌표를 입력받아 해당 좌표의 사분면을 판정해 출력
    scanf("%d %d", &x, &y);
    printf("%d\n", quad[y < 0][x > 0]);

    return 0;
}
