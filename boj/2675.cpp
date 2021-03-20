#include <cstdio>

int main()
{
	//입력받은 문자열을 저장할 컨테이너
	char buf;
	//tc : 테스트 케이스의 수
	//rec : 각 테스트 케이스마다 반복할 수
	int tc, rec;

	scanf("%d", &tc);

	//매 테스트 케이스마다 문자열을 입력받은 뒤
	//문자열의 각 문자를 rec만큼 반복하여 출력한다
	for (int i = 0; i < tc; i++)
	{
	    scanf("%d %c", &rec, &buf);

        while(buf != '\n')
        {
            for(int j = 0; j < rec; j++) printf("%c", buf);
            scanf("%c", &buf);
        }

        printf("\n");
	}

    return 0;
}