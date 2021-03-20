#include <cstdio>

int main()
{
	//times : 한 자리 수를 서로 붙여놀은 문자열
	//sum : 출력할 합
	int times, sum = 0;
	//num : 한 자리 수를 입력받기 위해 char 형식으로 선언
	char num;

	//times를 입력받는다.
	//버퍼를 비우기 위해 "%d"가 아닌 %d "를 사용.
	//숫자 다음에 오는 개행문자를 무시할 수 있다
	scanf("%d ", &times);

	for (int i = 0; i < times; i++)
	{
		//입력 형식 상 개행문자가 들어오지 않는다
		//num에 한 자리 수를 입력받는다
		scanf("%c", &num);
		//sum에 num을 더한다
		//num이 나타내는 숫자는 num - '0'
		sum += num - '0';
	}

	//sum을 출력
	printf("%d\n", sum);

    return 0;
}