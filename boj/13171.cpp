#include <cstdio>

typedef unsigned long long ull;

#define MOD 1000000007

int main() {
    // ans = (A ^ X) % MOD
    ull A, X, ans = 1;
    
    // A를 입력받은 뒤 (A * A)의 오버플로우를 방지하기 위해 MOD로 나눈 나머지를 사용
    scanf("%lld", &A);
    A %= MOD;

    // X를 이진수로 봤을 때 X의 각 자리에 대해
    for (scanf("%lld", &X); X; X /= 2) {
        // X의 현재 자리가 1이라면 ans와 A를 곱한 뒤
        if (X % 2) ans = (ans * A) % MOD;
        // A를 제곱해 다음 자리를 비교
        A = (A * A) % MOD;
    }

    // A ^ X를 출력
    printf("%lld\n", ans);

    return 0;
}
