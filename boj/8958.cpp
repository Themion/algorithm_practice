#include <cstdio>

int main()
{
	//문자열을 모두 저장할 필요는 없다
	//한 글자씩 저장할 버퍼
	char buf;
	//tc : 테스트 케이스의 수
	//ret : 매 테스트 케이스마다 출력할 점수
	//add : 점수의 가중치
	int tc, ret, add;

	//테스트 케이스의 수를 입력받는다
	scanf("%d ", &tc);

	for (int t = 0; t < tc; t++)
	{
		//매 테스트 케이스마다 ret와 add를 초기화한다
		ret = 0;
		add = 1;

		//문자열의 최대 길이는 79, 여기에 공백 문자까지 합하여 총 80
		for (int i = 0; i < 80; i++)
		{
			//문자열의 한 글자를 입력받는다
			scanf("%c", &buf);
			//만일 그 글자가 O라면 ret에 가중치를 더하고 가중치를 1 올린다
			if      (buf == 'O') ret += add++;
			//만일 그 글자가 X라면 가중치를 1로 초기화한다
			else if (buf == 'X') add = 1;
			//만일 그 글자가 공백문자라면 문자열이 끝났으므로 for문을 벗어난다
			else if (buf == '\n') break;
		}

		//ret를 출력
		printf("%d\n", ret);
	}

    return 0;
}