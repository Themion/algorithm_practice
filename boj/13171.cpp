#include <cstdio>
#include <cmath>
#include <vector>

typedef unsigned long long ull;

//오버플로우를 방지하기 위해 mod로 나눈 나머지를 저장한다
const ull mod = 1000000007;

int main()
{
	//a, x: 구하는 값은 (a ^ x) % mod이다
	//ret: (a ^ x) % mod를 저장할 공간
	ull a, x, ret = 1;

	//a와 x를 입력받는다
	scanf("%lld %lld", &a, &x);
    a %= mod;

	//x를 2진법으로 보았을 때
	while (x)
	{
        //x가 홀수라면 ret에 a를 곱한다
		if (x % 2) ret = (ret * a) % mod;
        //x를 2로 나누고 a를 제곱한다
		x >>= 1; a = (a * a) % mod;
	}

	//ret을 출력한다
	printf("%lld\n", ret);

	return 0;
}