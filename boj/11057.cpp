#include <cstdio>

#define MOD 10007

int main() {
    // N: 오르막 수의 자리수, cnt[i]: 1의 자리가 i인 오르막 수의 개수
    // ans: N자리의 오르막 수의 개수
    int N, cnt[10] = { 0, }, ans = 0;

    // 한 자리 수는 모두 오르막 수이다
    for (int i = 9; i >= 0; i--) cnt[i] = 1;
    // 두 자리 수부터
    for (scanf("%d", &N); --N; ) {
        // 1의 자리가 j인 N - 1자리 오르막 수의 뒤에 i를 더해
        // 1의 자리가 i인 N자리 오르막 수를 만든다
        // 이 때 j의 범위에 i가 포함되면 1의 자리가 i인 N - 1자리 오르막 수를
        // 두 번 계싼하게 되므로 j의 최댓값은 i - 1이다
        for (int i = 9; i >= 0; i--) for (int j = i - 1; j >= 0; j--)
            cnt[i] = (cnt[i] + cnt[j]) % MOD;
    }
    // 1의 자리 별로 나눈 오르막 수의 개수를 모두 더해 ans에 저장한 뒤 출력
    for (int i = 9; i >= 0; i--) ans = (ans + cnt[i]) % MOD;
    printf("%d\n", ans);

    return 0;
}
