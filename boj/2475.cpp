#include <cstdio>

int main() {
    int buf, sum = 0;

    // 수를 다섯 번 입력받아 제곱해 모두 더한 뒤
    for (int i = 0; i < 5; i++) {
        scanf("%d", &buf);
        sum += buf * buf;
    }

    // 이렇게 구한 값을 10으로 나눈 나머지를 출력
    printf("%d\n", sum % 10);

    return 0;
}
