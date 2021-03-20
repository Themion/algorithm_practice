#include <cstdio>

typedef unsigned long long ull;

int main()
{
    //ret = (a ^ b) % c
    ull a, b, c, ret = 1;
    scanf("%lld %lld %lld", &a, &b, &c);

    //b가 0이 아닌 동안
	while (b)
	{
        //b가 홀수라면 ret에 a를 곱한다
		if (b % 2) ret = (ret * a) % c;
        //b를 2로 나누고 a를 제곱한다
		b >>= 1; a = (a * a) % c;
	}

    printf("%lld\n", ret);

    return 0;
}