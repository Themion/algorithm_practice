#include <cstdio>

int main() {
    int y;
    scanf("%d", &y);
    // 같은 해에 태국은 2541년, 한국은 1998년이었으므로 그 차만큼 더한 값을 출력
    printf("%d\n", y - 2541 + 1998);

    return 0;
}
