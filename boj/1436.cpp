#include <cstdio>

//ret: 출력할 숫자를 저장할 컨테이너
int ret[10000] = { 666, };

int main()
{
	//test: 해당 숫자가 종말의 숫자인지 확인할 공간
	//num: 출력할 종말의 숫자의 인덱스, i: 인덱싱에 쓸 변수
	//rank: 10의 제곱수. 어느 숫자가 종말의 숫자라면 rank로 나눈 뒤 1000으로 나눴을 때의 나머지가 666일 것이다
	int test = 1666, num, i = 1, rank;
	//num을 입력받는다
	scanf("%d", &num);
	num -= 1;

	//for문보다는 while문이 적합함
	while (i <= num)
	{
		//1의 자리 수부터 시작하여
		rank = 1;
		//해당 자리 수 위가 666보다 크다면
		while (test / rank >= 666)
		{
			//해당 자리수 근처에 666이 있다면
			if ((test / rank) % 1000 == 666)
			{
				//test가 종말의 숫자이므로 이 수를 ret에 넣는다
				ret[i++] = test;
				//이 이상의 연산은 불필요하므로 break한다
				break;
			}
			rank *= 10;
		}

		//다음 수에 대해 계산한다
		test += 1;
	}

	//num번째 종말의 숫자를 출력
	printf("%d\n", ret[num]);

    return 0;
}