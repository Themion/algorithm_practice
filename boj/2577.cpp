#include <cstdio>

int main()
{
	//a, b, c : 입력받을 세 수
	//mul : 세 수의 곱을 저장한다
	//ret : mul에 0부터 9까지 얼마나 쓰였는지를 저장
	int a, b, c, mul, ret[10] = { 0, };
	scanf("%d %d %d", &a, &b, &c);
	mul = a * b * c;

	//mul의 1의 자리 수를 판별하여 해당 수가 나온 횟수를 1 늘린 뒤
	//mul을 10으로 나누어 다시 mul의 1의 자리 수를 판별한다
	while (mul > 0)
	{
		ret[mul % 10] += 1;
		mul /= 10;
	}
	
	//a, b, c 세 수의 곱에 0부터 9까지의 숫자가 얼마나 쓰였는지 출력
	for (int i = 0; i < 10; i++) printf("%d\n", ret[i]);

    return 0;
}