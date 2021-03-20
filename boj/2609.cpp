#include <cstdio>

int main()
{
	//a, b : 최대공약수, 최소공배수를 구할 두 수
	//cont : a와 b의 공약수를 이 변수에 곱한다
	int a, b, i, cont = 1;
	scanf("%d %d", &a, &b);

	//for문에 b를 사용하기 위해 a와 b를 정렬해준다
	if (a < b) { i = a; a = b; b = i; }

	//b가 가변적이므로 공약수를 구하면 구할수록 줄어든다
	//i가 b를 넘으면 i는 절대 b의 약수가 될 수 없으므로
	//i의 상한선을 b로 정한다
	for (i = 2; i <= b; i++)
	{
		//i가 a와 b의 공약수라면 cont에 i를 곱하고 a와 b를 i로 나눈다
		while ((a % i == 0) && (b % i == 0))
		{
			cont *= i;
			a /= i;
			b /= i;
		}
	}

	//a와 b의 최소공배수는 a와 b의 서로소 부분을 cont와 곱한 것이다
    //최소공배수와 서로소를 이용해 최소공배수를 출력한다
	printf("%d\n%d\n", cont, a * b * cont);

    return 0;
}