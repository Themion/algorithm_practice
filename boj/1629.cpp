#include <cstdio>

int main() {
    // ans = (A ^ B) % C
    unsigned long long A, B, C, ans = 1;
    scanf("%lld %lld %lld", &A, &B, &C);

    // B를 비트마스킹 형식으로 활용
    while (B) {
        // B가 홀수라면 ans에 A를 곱한다
        if (B % 2) ans = (ans * A) % C;
        // B를 2로 나누고 A를 제곱한다
        B /= 2;
        A = (A * A) % C;
    }

    printf("%lld\n", ans);

    return 0;
}
