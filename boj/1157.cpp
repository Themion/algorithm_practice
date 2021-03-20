#include <cstdio>

//times : 0부터 25까지는 해당 알파벳이 나온 횟수, 26은 big의 사용을 위해 0번 나온 알파벳으로 가정
int times[27];

int main()
{
	//문자를 저장하는 버퍼
	char buf;

	//big : 가장 많이 나온 알파벳을 가리킴
	//temp : buf가 무슨 알파벳인지 저장. 인덱스로만 쓰이는 것이 아니므로 변수로 생성
	int big = 26, temp;

	//어떤 문자를 입력받을 때마다
	while (scanf("%c", &buf) == 1)
	{
		//그 문자가 소문자인지, 대문자인지, 아니면 공백 문자인지 판정
		if		((buf >= 'a') && (buf <= 'z'))	temp = (int)(buf - 'a');
		else if ((buf >= 'A') && (buf <= 'Z'))	temp = (int)(buf - 'A');
		else									break;

		//해당 알파벳이 나온 횟수를 저장
		times[temp] += 1;
		//여태까지 나온 알파벳 중 가장 많이 나온 알파벳을 갱신
		if (times[big] < times[temp]) big = temp;
	}

	//가장 많이 나온 알파벳을 버퍼에 저장
	buf = big + 'A';

	//알파벳 big만큼 나온 알파벳이 또 있다면 버퍼에 '?'을 저장
	for (int i = 0; i < 26; i++)
	{
		if (i == big) continue;
		if (times[i] == times[big])
		{
			buf = '?';
			break;
		}
	}

	//버퍼를 출력한다
	printf("%c\n", buf);

    return 0;
}