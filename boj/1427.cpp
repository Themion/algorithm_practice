#include <cstdio>

//cnt[i]: 숫자 i가 나온 횟수
int cnt[10];

int main()
{
	//입력을 문자열로 생각하여 버퍼에 한 글자씩 입력받는다
	char buf;
	
	//계속해서 한 문자씩 입력받는다
	while (scanf("%c", &buf) == 1)
	{
		//버퍼에 들어간 값이 숫자라면 해당 숫자가 나온 횟수를 1 더한다
		if((buf - '0' >= 0) && (buf - '0' <= 9))    cnt[buf - '0']++;
		//공백 문자나 잘못된 입력이 들어온다면 break
		else                                        break;
	}
    
	//배열을 역순으로 출력
	for (int i = 9; i >= 0; i--) while (cnt[i]-- != 0) printf("%d", i);
	printf("\n");

    return 0;
}