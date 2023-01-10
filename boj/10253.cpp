#include <cstdio>

int test_case() {
    // 입력받은 분수의 분자
    int a;
    // 입력받은 분수의 분모
    int b;
    // 각 단위분수의 분모
    int x;

    // 분수를 입력받은 뒤 분수가 단위분수 꼴이 될 때까지
    for (scanf("%d %d", &a, &b); b % a;) {
        // 분수보다 작은 단위분수 중 가장 큰 단위분수를 계산한 뒤
        x = (b / a) + 1;

        // (a / b) - (1 / x) = (ax / bx) - (b / bx) = (ax - b) / bx
        // 현재 분수에서 단위분수를 뺌
        a = a * x - b;
        b = b * x;
    }

    // 단위분수의 분모를 출력
    printf("%d\n", b / a);

    return 0;
}

int main() {
    int T;
    for (scanf("%d", &T); T--; test_case());
    return 0;
}
