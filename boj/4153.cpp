#include <cstdio>

void swap(int &a, int &b) { int temp = a; a = b; b = temp; }

int main() {
    // 직각삼각형의 세 변
    int a, b, c;

    // 각 테스트 케이스에 대해
    while (scanf("%d %d %d", &a, &b, &c) && a) {
        // 세 변을 오름차순으로 정렬
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);

        // 직각삼각형이라면 right, 아니라면 wront을 출력
        printf("%s\n", a * a + b * b == c * c ? "right" : "wrong");
    }

    return 0;
}
