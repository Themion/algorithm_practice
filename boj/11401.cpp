#include <cstdio>

typedef unsigned long long ull;

const ull mod = 1000000007;

//(N ^ (mod - 2)) % mod를 구하는 함수
ull pow(ull N)
{
    //a, x: 각각 N과 mod - 2를 저장할 임시 변수
    //ret: (N ^ x) % mod를 저장할 공간
    ull a = N % mod, x = mod - 2, ret = 1;

    //x를 2진법으로 보았을 때
	while (x)
	{
        //x가 홀수라면 ret에 a를 곱한다
		if (x % 2) ret = (ret * a) % mod;
        //x를 2로 나누고 a를 제곱한다
		x >>= 1; a = (a * a) % mod;
	}

    //ret을 반환한다
	return ret;
}

int main()
{
    //이항 계수의 N, K
    int N, K;
    //nf, kf, nkf: 각각 N!, K!, (N - K)!을 저장할 변수
    ull nf = 1, kf = 1, nkf = 1;
    
    //N과 K를 읽어들인다
	scanf("%d %d", &N, &K);
    
    //N!, K!, (N - K)!를 mod로 나눈 나머지를 구한다
    for (ull i = 2; i <= N; i++) 
    {
        nf = (nf * (i % mod)) % mod;
        if (i == K) kf = nf;
        if (i == N - K) nkf = nf;
    }

    //이항 계수 N!/(K!*(N - K)!)를 구한다
    //이 떄 반드시 mod로 나눈 나머지를 구해야 하므로
    //K!*(N - K)!의 역원을 구해 N!에 곱해주면 된다
    nf = (nf * pow((kf * nkf) % mod)) % mod;

    //이항 계수를 출력한다
    printf("%lld\n", nf);

	return 0;
}