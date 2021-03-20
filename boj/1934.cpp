#include <cstdio>

int main()
{
	//a, b : 최대공약수, 최소공배수를 구할 두 수
	//cont : 공약수를 저장할 변수
	int a, b, tc, cont, i;

	scanf("%d", &tc);
	for (int t = 0; t < tc; t++)
	{
		cont = 1;
		scanf("%d %d", &a, &b);

		//for문에 b를 사용하기 위해 a와 b를 정렬해준다
		if (a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		//b가 가변적이므로 공약수를 구하면 구할수록 줄어든다
		//i가 b를 넘으면 i는 절대 b의 약수가 될 수 없으므로
		//i의 상한선을 b로 정한다
		for (i = 2; i <= b; i++)
		{
			//i가 a와 b의 공약수라면 공약수에 i를 곱하고 a와 b를 i로 나눈다
			while ((a % i == 0) && (b % i == 0))
			{
				cont *= i;
				a /= i;
				b /= i;
			}
		}

		//최대공약수는 cont만으로 구할 수 있으므로 
		//a와 b의 공약수가 아닌 부분을 전부 b에 옮긴다
		//a에 b * cont를 곱하면 a는 최소공배수가 된다
		a *= b * cont;

		//답을 출력한다
		printf("%d\n", a);
	}

    return 0;
}