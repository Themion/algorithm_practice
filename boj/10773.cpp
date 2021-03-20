#include <cstdio>

//call[i]: i가 0이라면 부르는 수의 개수, 아니라면 i번째로 부른 수
int call[100001];

int main()
{
	//input: 입력에 사용할 버퍼, idx: 인덱싱에 사용할 변수
	int input, idx = 1;
	//결과적으로 부른 수의 합
	unsigned long long sum = 0;

	//부를 수의 개수를 입력받는다
	scanf("%d", &call[0]);
	//각 수에 대해
	for (int i = 0; i < call[0]; i++)
	{
		//해당 수를 입력받고
		scanf("%d", &input);
		//그 수가 0이라면 스택에서 수를 뺀다
		if (input == 0) idx--;
		//아니라면 스택에 수를 넣는다
		else call[idx++] = input;
	}

	//스택에 들어있는 수를 모두 더한 뒤 출력한다
	for (int i = 1; i < idx; i++) sum += call[i];
	printf("%lld\n", sum);

    return 0;
}