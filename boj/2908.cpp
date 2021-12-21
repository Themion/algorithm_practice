#include <cstdio>

void invert(int n) {
    n = 100 * (n % 10) + (n / 100) + 10 * ((n / 10) % 10);
}

int main() {
    // 세 자리 수 A, B를 받아와서 역순으로 만든 뒤 더 큰 수를 출력한다
    int A, B;
    scanf("%d %d", &A, &B);

    invert(A); invert(B);

    printf("%d\n", A > B ? A : B);

    return 0;
}
