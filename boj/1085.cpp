#include <cstdio>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    //x, y: 현재 좌표, w, h: 직사각형의 우상단 꼭지점의 좌표
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    //현재 좌표에서 가장 가까운 면을 찾은 뒤 해당 면을 출력
    printf("%d\n", min(min(x, w - x), min(y, h - y)));

    return 0;
}