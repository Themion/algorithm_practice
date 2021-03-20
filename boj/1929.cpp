#include <cstdio>

//에라토스테네스의 체를 간접적으로 구현
//해당 인덱스가 소수라면 false, 아니라면 true
bool era[1000001];

int main()
{
	//start, end : 소수의 범위
	//k : 소수를 구할 때 쓸 곱셈수
	int start, end, k;
	scanf("%d %d", &start, &end);

	//0과 1은 반드시 소수가 아니므로 예외처리 해 준다
	era[0] = true; era[1] = true;

	//2부터 end까지 모든 수에 대해
	for (int i = 2; i <= end; i++)
	{
		//2 이상을 곱해서 나온 수는 모두 소수가 아니다
		k = 2;

		//i * k가 end 초과라면 굳이 할 필요가 없다
		while (i * k <= end) era[i * k++] = true;
	}

	//era에서 소수인 수들만 골라 출력한다
	for (int i = start; i <= end; i++) if (!era[i]) printf("%d\n", i);

    return 0;
}