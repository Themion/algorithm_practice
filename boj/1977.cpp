#include <cmath>
#include <cstdio>

int main()
{
	//min, max: 각 제곱수의 범위
	int min, max, res;

	//제곱수의 범위를 입력받는다
	scanf("%d\n%d", &min, &max);
	//res에 임시적으로 min의 루트값을 저장한다
	res = pow(min, 0.5);
	//res의 제곱이 min보다 작다면 res에 1 더한 값을
	//그렇지 않다면 res를 min에 저장한다
	min = ((res * res < min) ? res + 1 : res);
	//max값을 max의 루트값으로 변경한다
	max = pow(max, 0.5);

	//주어진 범위 사이에 완전제곱수가 존재한다면
	if (min <= max)
	{
		//res를 0으로 초기화한 뒤
		res = 0;
		//min부터 max까지를 제곱한 수를 모두 더해 res에 저장한다
		for (int i = min; i <= max; i++)
			res += i * i;
		//res와 min*min을 출력한다
		printf("%d\n%d\n", res, min * min);
	}
	//그렇지 않다면 -1을 출력한다
	else printf("%d\n", -1);

	return 0;
}