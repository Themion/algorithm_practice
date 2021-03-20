#include <cstdio>

//괄호 문자열을 저장할 공간
char str[100000] = "(";

int main()
{
	//idx: 인덱싱에 쓸 변수, cnt: 현재 올려둔 막대기의 수
	int idx = 0, cnt = 0;
	//sum: 토막이 완성된 막대기의 수
	unsigned long long sum = 0;
	//buf: 입력에 쓸 버퍼
	char buf;

	//첫 문자는 반드시 '('
	//두 번째 문자열부터 입력받는다
	scanf("%*c%c", &buf);

	//문자열이 끝날 때까지
	while (buf != '\n')
	{
		//레이저의 배치를 확인하면 "()"를 레이저 배치를 의미하는 '|'로 변경
		if ((str[idx] == '(') && (buf == ')')) str[idx] = '|';
		//그렇지 않다면 쇠막대기의 시작과 끝을 저장
		else { idx += 1; str[idx] = buf; }
		//문자열의 다음 글자를 입력받는다
		scanf("%c", &buf);
	}

	//문자열의 각 글자에 대해
	for (int i = 0; i <= idx; i++)
	{
		//해당 문자가 막대기의 시작을 의미한다면 막대기를 하나 더 배치한다
		if (str[i] == '(') cnt += 1;
		//해당 문자가 레이저를 의미한다면 놓인 막대기를 절단한다
		else if (str[i] == '|') sum += cnt;
		//해당 문자가 막대기의 끝을 알린다면 막대기 하나를 제거한다
		else if (str[i] == ')') { sum += 1; cnt -= 1; }
	}

	//총 토막 수를 출력한다
	printf("%lld\n", sum);

    return 0;
}