#include <cstdio>

typedef unsigned long long ull;

#define MOD 1000000007

// (N ^ (MOD - 2)) % MOD를 구하는 함수
int pow(ull N) {
    // ret = (N ^ (MOD - 2)) % MOD
    int ret = 1;

    // X = MOD - 2를 이진수로 봤을 때 X의 각 자리에 대해
    for (int X = MOD - 2; X; X /= 2) {
        // X의 현재 자리가 1이라면 ret와 N을 곱한 뒤
        if (X % 2) ret = (ret * N) % MOD;
        // N을 제곱해 다음 자리를 비교
        N = (N * N) % MOD;
    }

    // ret을 반환한다
    return ret;
}

int main() {
    // M: 주사위의 수, ans: 각 주사위의 기댓값의 총합
    int M, ans = 0;
    // N: 각 주사위의 면 수, S: 각 주사위의 모든 면에 적힌 숫자를 더한 값
    ull N, S;

    // 각 주사위에 대해
    for (scanf("%d", &M); M--; ) {
        // 주사위의 면 수와 각 면의 값의 합을 입력받아
        scanf("%d %d", &N, &S);
        // 기댓값을 계산한 뒤 ans에 더한다
        ans = (ans + S * pow(N)) % MOD;
    }

    // 각 주사위의 기댓값의 합을 출력
    printf("%lld\n", ans);

    return 0;
}
