#include <cstdio>

int main()
{
	//input: 생성자를 구할 분해합, mkr: 생성자를 저장할 공간
	//sum, cnt: sum에 input을 저장해 input의 자리수를 cnt에 저장한다
	int input, mkr = 0, sum, cnt = 0;

	//분해합을 입력받은 뒤
	scanf("%d", &input);
	sum = input;

	//input의 자리수를 cnt에 저장
	while (sum > 0)
	{
		cnt += 1;
		sum /= 10;
	}

	//각 자리의 최대값은 9이므로 생성자의 최소값은 (분해합 - (9 *  분해합의 자리수))이다
	//생성자의 각 후보에 대해
	for (int i = input - (9 * cnt); i <= input; i++)
	{
		//mkr로 분해합을 만들어 sum에 저장한 뒤
		mkr = i; sum = i;
		while (mkr > 0)
		{
			sum += mkr % 10;
			mkr /= 10;
		}

		//이렇게 만든 분해합이 input과 같다면 mkr에 i를 넣고 루프문을 빠져나간다
		if (sum == input)
		{
			mkr = i;
			break;
		}
	}

	//분해합 input을 만들지 못했다면 mkr은 0이고
	//input을 만들었다면 mkr은 정답인 생성자이므로 결국 답은 mkr이다
	printf("%d\n", mkr);

    return 0;
}