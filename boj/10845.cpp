#include <cstdio>

//큐를 저장할 배열
int q[10000];

int main()
{
	//front: 큐의 맨 앞을 가리킬 인덱스, back: 큐의 back 다음을 가리킬 인덱스
	//t: 테스트 케이스를 for루프로 돌리기 위한 변수
	int front = 0, back = 0, t;
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
				//인자를 입력받아 큐에 저장한다
				scanf("%d\n", &q[back++]);
			}
			//만일 명령이 pop이라면
			else if (buf == 'o')
			{
				//명령을 전부 스킵한다
				while (buf != '\n') scanf("%c", &buf);
				//큐가 비어있다면 -1을 출력
				if (front == back) printf("%d\n", -1);
				//큐에 값이 있다면
				else
				{
					//큐의 맨 앞칸을 출력한 뒤 비운다
					printf("%d\n", q[front]);
					q[front++] = 0;
				}
			}

			break;

		//만일 명령이 size라면
		case('s'):
			//명령을 전부 스킵한다
			while (buf != '\n') scanf("%c", &buf);
			//큐의 크기를 출력
			printf("%d\n", back - front);

			break;

		//만일 명령이 empty라면
		case('e'):
			//명령을 전부 스킵한다
			while (buf != '\n') scanf("%c", &buf);
			//큐가 비어있다면 1을, 그렇지 않다면 0을 출력
			if (front == back)	printf("%d\n", 1);
			else				printf("%d\n", 0);

			break;

		case ('f'):
			//명령을 전부 스킵한다
			while (buf != '\n') scanf("%c", &buf);
			//큐에 값이 들어있다면 큐의 front값을, 그렇지 않다면 -1을 출력
			if (front != back)	printf("%d\n", q[front]);
			else				printf("%d\n", -1);

			break;

		//만일 명령이 back이라면
		case ('b'):
			//명령을 전부 스킵한다
			while (buf != '\n') scanf("%c", &buf);
			//큐에 값이 들어있다면 큐의 back값을, 그렇지 않다면 -1을 출력
			if (back != front)	printf("%d\n", q[back - 1]);
			else				printf("%d\n", -1);

			break;
		}
	}

    return 0;
}