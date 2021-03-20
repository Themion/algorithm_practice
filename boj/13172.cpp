#include <cstdio>

typedef unsigned long long ull;

//오버플로우를 방지하기 위해 mod로 나눈 나머지를 저장한다
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
    //주사위의 수
    int M;
    //N: 각 주사위의 면 수, S: 각 주사위의 모든 면에 적힌 숫자를 더한 값
    //ret: 각 주사위의 기댓값의 총합
    ull N, S, ret = 0;
    scanf("%d", &M);

    //각 주사위에 대해
    while(M--)
    {
        //주사위의 면 수와 각 면의 값의 합을 입력받아
        scanf("%lld %lld", &N, &S);
        //기댓값을 저장한 뒤 ret에 더한다
        ret = (ret + S * pow(N)) % mod;
    }

    //ret을 출력한다
    printf("%lld\n", ret);

    return 0;
}