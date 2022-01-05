#include <cstdio>

typedef unsigned long long ull;

#define MOD 1000000007

// (N ^ (MOD - 2))를 구하는 함수
ull pow(ull N) {
    // a: N의 2 ^ k승, ans: N ^ (MOD - 2)를 저장할 공간
    ull a = N % MOD, ans = 1;

    // x를 이진법으로 보았을 때 x의 각 자리에 대해
    for (int x = MOD - 2; x; x /= 2) {
        // 현재 자리가 1이라면 ans에 a를 곱한다
        if (x % 2) ans = (ans * a) % MOD;
        // a를 제곱한다
        a = (a * a) % MOD;
    }

    // N을 (MOD - 2)제곱한 결과를 반환
	return ans;
}

int main() {
    // 이항 계수의 N, K
    int N, K;
    // nf: N!, kf: K!, nkf: (N - K)!
    ull nf = 1, kf = 1, nkf = 1;
    
    // N과 K를 읽어들인다
	scanf("%d %d", &N, &K);
    
    // N!, K!, (N - K)!를 MOD로 나눈 나머지를 구한다
    for (ull i = 2; i <= N; i++) {
        nf = (nf * (i % MOD)) % MOD;
        if (i == K) kf = nf;
        if (i == N - K) nkf = nf;
    }

    // N!과 K!, (N - K)!를 구한 값을 MOD로 나눈 나머지만 알고 있으니
    // 일반적인 이항 계수처럼 계산할 수 없다
    // 페르마의 소정리, 즉 소수 p에 대해 a ^ (p - 1) = 1 (mod p)에 따라
    // (K! * (N - K)!) ^ (MOD - 2) % MOD = 1 / (K! * (N - K)!)이므로
    // 이 결과를 계산해 N!과 곱한 값을 반환
    printf("%lld\n", (nf * pow(kf * nkf)) % MOD);

	return 0;
}
