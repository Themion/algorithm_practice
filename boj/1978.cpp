#include <cstdio>

//num[i]: i가 소수라면 false, 아니라면 true
bool num[1001];

int main()
{
	//N: 입력받을 수의 개수, temp: 소수 계산 및 버퍼로 사용할 공간
	//ret: 출력에 쓸 변수
	short N, temp, ret;

	//0과 1은 소수가 아니다
	num[0] = true; num[1] = true;

	//i가 500 이상일 경우 i * 2 > 1000이므로 범위에서 벗어난다
	for (int i = 2; i <= 500; i++)
	{
		//temp * i는 소수가 아니다
		temp = 2;
		while (temp * i <= 1000) num[i * temp++] = true;
	}

	//수의 개수를 입력받는다
	scanf("%hd", &N);
	//모두 소수라고 가정
	ret = N;
	//각 수를 입력받아 해당 수가 소수가 아니라면 1씩 뺀다
	for (int i = 0; i < N; i++)
	{
		scanf("%hd", &temp);
		ret -= num[temp];
	}

	//소수의 개수를 출력한다
	printf("%hd\n", ret);

	return 0;
}