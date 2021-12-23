#include <cstdio>

#define INF 2001

int main() {
    // food[0]: 버거, [1]: 콜라, temp: 입력받을 버퍼
    int food[2] = { INF, INF }, buf;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &buf);
        // i <= 2일 경우 food[i]의 가격은 버거의 가격이고,
        // 그렇지 않다면 콜라의 가격이다
        if (food[i > 2] > buf) food[i > 2] = buf;
    }

    // 가장 싼 세트메뉴의 가격을 출력한다
    printf("%d\n", food[0] + food[1] - 50);

    return 0;
}
