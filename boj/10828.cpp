#include <cstdio>

//스택을 저장할 배열
int stk[10000];

int main()
{
	//idx: 스택의 top 다음을 가리킬 인덱스
	//t: 테스트 케이스를 for루프로 돌리기 위한 변수
	int idx = 0, t;
	//각 명령어를 char타입 하나만으로 구분할 수 있다
	char buf;

	//테스트 케이스의 수를 입력받는다
	scanf("%d\n", &t);

	for (int tc = 0; tc < t; tc++)
	{
		//명령어의 첫 글자를 통해 명령을 판단
		scanf("%c", &buf);

		switch (buf)
		{
			//만약 명령이 p로 시작한다면
			case ('p'):
				//다음 글자를 통해 push와 pop을 구분한다
				scanf("%c", &buf);

				//만일 명령이 push라면
				if (buf == 'u')
				{
					//인자값이 나올 때까지 명령을 입력받는다
					while (buf != ' ') scanf("%c", &buf);
					//인자를 입력받아 스택에 저장한다
					scanf("%d\n", &stk[idx++]);
				}
				//만일 명령이 pop이라면
				else if (buf == 'o')
				{
					//명령을 전부 스킵한다
					while (buf != '\n') scanf("%c", &buf);
					//스택이 비어있다면 -1을 출력
					if (idx == 0) printf("%d\n", -1);
					//스택에 값이 있다면
					else
					{
						//스택의 맨 윗칸을 출력한 뒤 비운다
						printf("%d\n", stk[idx - 1]);
						stk[--idx] = 0;
					}
				}

				break;

			//만일 명령이 size라면
			case('s'):
				//명령을 전부 스킵한다
				while (buf != '\n') scanf("%c", &buf);
				//스택의 크기를 출력
				printf("%d\n", idx);

				break;

			//만일 명령이 empty라면
			case('e'):
				//명령을 전부 스킵한다
				while (buf != '\n') scanf("%c", &buf);
				//스택이 비어있다면 1을, 그렇지 않다면 0을 출력
				if (idx == 0)	printf("%d\n", 1);
				else			printf("%d\n", 0);

				break;

			//만일 명령이 top이라면
			case ('t'):
				//명령을 전부 스킵한다
				while (buf != '\n') scanf("%c", &buf);
				//스택에 값이 들어있다면 스택의 맨 윗값을, 그렇지 않다면 -1을 출력
				if (idx != 0)	printf("%d\n", stk[idx - 1]);
				else			printf("%d\n", -1);

				break;
		}
	}

    return 0;
}