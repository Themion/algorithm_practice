#include <cstdio>

int main()
{
	//input : 설탕의 무게
	//t3 : input이 5로 나누어 떨어지지 않으면 계속해서 1씩 더함
	int input, t3 = 0;
	scanf("%d", &input);

	while (input >= 0)
	{
		//input이 5로 나누어 떨어진다면 (input / 5) + t3을 출력
		if (input % 5 == 0)
		{
			printf("%d\n", (input / 5) + t3);
			break;
		}
		//input이 나누어 떨어지지 않는다면 input에 3을 빼고 t3에 1을 더함
		else
		{
			input -= 3;
			t3 += 1;
		}
	}

	//input이 음수가 될 때까지 5로 나누어 떨어지지 않는다면 -1을 출력
	if (input < 0) printf("-1\n");

    return 0;
}