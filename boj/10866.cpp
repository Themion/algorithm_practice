#include <cstdio>

//문제에서 입력은 최대 10000줄이다
const int SIZE = 10000;
//front, back: 입출력을 실행할 공간의 포인터
//deque: deque를 원형 배열로 저장할 공간
int front = SIZE - 1, back = 0, deque[SIZE];

int main()
{
    //tc: 각 입력의 수, tmp: 임시 변수
    int tc, tmp;
    //명령을 한 글자씩 입력받는다
    char buf;
    scanf("%d%*c", &tc);

    while(tc--)
    {
        tmp = 0;
        scanf("%c", &buf);

        switch (buf)
        {
        //push or pop
        case ('p'):
            //push는 _ 이전에 글자가 4자 나온다
            //pop은  _ 이전에 글자가 3자 나온다
            while (buf != '_')
            {
                scanf("%c", &buf);
                tmp++;
            }

            //push
            if (tmp == 4)
            {
                //front인지 back인지 판단
                scanf("%c", &buf);

                //front 위치에 push한 뒤 front를 한 칸 빼 주고 scaling한다
                if (buf == 'f')
                {
                    while (buf != ' ') scanf("%c", &buf);
                    scanf("%d", &deque[front--]);
                    front = (front + SIZE) % SIZE;
                }
                //back 위치에 push한 뒤 front를 한 칸 더해 주고 scaling한다
                else if (buf == 'b')
                {
                    while (buf != ' ') scanf("%c", &buf);
                    scanf("%d", &deque[back++]);
                    back = back % SIZE;
                }
            }

            //pop
            else if(tmp == 3)
            {
                //front인지 back인지 판단
                scanf("%c", &buf);

                if (buf == 'f')
                {
                    //deque에 값이 있다면
                    //front 다음 칸의 값을 출력한 뒤 해당 값을 제거
                    //front에 한 칸 더하고 scaling함
                    if ((front + 1) % SIZE != back)
                    {
                        printf("%d\n", deque[(front + 1) % SIZE]);
                        deque[front++] = 0;
                        front = front % SIZE;
                    }
                    //deque에 값이 없다면 -1을 출력
                    else printf("-1\n");
                }
                else if (buf == 'b')
                {
                    //deque에 값이 있다면
                    //back 이전 칸의 값을 출력한 뒤 해당 값을 제거
                    //back 한 칸 빼고 scaling함
                    if ((front + 1) % SIZE != back)
                    {
                        printf("%d\n", deque[(back + SIZE - 1) % SIZE]);
                        deque[back--] = 0;
                        back = (back + SIZE) % SIZE;
                    }
                    //deque에 값이 없다면 -1을 출력
                    else printf("-1\n");
                }
            }
            break;

        //size
        case ('s'):
            //deque의 크기는 back - front이다
            //초기 상태에서 back과 front가 1 차이나니 결과값에 1을 빼 준다
            tmp = back - front - 1;
            //deque가 원형 큐 꼴이므로 front > back일 수 있다
            while(tmp < 0) tmp += SIZE;
            printf("%d\n", tmp);
            break;

        //empty
        case ('e'):
            //front와 back이 인접하다면 해당 큐는 비어있음
            printf("%d\n", (front + 1) % SIZE == back);
            break;

        //front
        case ('f'):
            //front와 back이 인접하다면 -1을 출력
            if ((front + 1) % SIZE != back) printf("-1\n");
            //그렇지 않다면 deque에 값이 있으므로 front 다음 값을 출력
            else printf("%d\n", deque[(front + 1) % SIZE]);
            break;

        case ('b'):
            if ((front + 1) % SIZE != back) printf("-1\n");
            //그렇지 않다면 deque에 값이 있으므로 back 이전 값을 출력
            else printf("%d\n", deque[(back + SIZE - 1) % SIZE]);
            break;
        }

        //입력을 중간에 끊었으므로 모든 명령어를 입력받는다
        while (buf != '\n') scanf("%c", &buf);
    }

    //VS code에선 마지막 출력이 정상적으로 나오지 않는 버그가 있음
    //boj와 디버깅에선 제대로 출력됨
    return 0;
}