#include <cstdio>
#include <algorithm>

int ground[257] = { 0, };   //ground[i]: 바닥 높이가 i인 칸의 수
int N, M, B;                //N, M: 바닥의 크기, B: 주머니에 든 블록 수

int main()
{
    int height = 0, min = 257, max = 0; //height: 정답의 바닥 높이
                                        //min, max: 가능한 바닥 높이의 범위
    int t = 0x3f3f3f3f, t_temp;         //t: 정답의 경과 시간
                                        //t_temp: 검사중인 층의 경과 시간
    int buf;                            //buf: 입력 버퍼 및 주머니 계산 공간

    scanf("%d %d %d", &N, &M, &B);
    for (int i = 0; i < N * M; i++)
    {
        scanf("%d", &buf);
        ground[buf]++;
        min = (min < buf) ? min : buf;
        max = (max > buf) ? max : buf;
    }

    for (int i = min; i <= max; i++)    //정답으로 고려할만한 각 층에 대해
    {
        t_temp = 0; buf = B;            //경과 시간과 주머니를 초기화한 뒤
        
        for (int j = max; j > i; j--)   //층 위쪽 블록을 모두 제거하고
        {
            buf    += (j - i) * ground[j];
            t_temp += (j - i) * ground[j] * 2;
        }
        for (int j = min; j < i; j++)   //층 아래쪽 블록을 모두 채운다
        {
            buf    -= (i - j) * ground[j];
            t_temp += (i - j) * ground[j];
        }
        
        if (t >= t_temp && buf >= 0)    //경과 시간이 기존 정답보다 작고
        {                               //블록이 모자라지 않을 때
            t = t_temp;                 //해당 답을 정답으로 기록
            height = i;
        }
    }

    printf("%d %d\n", t, height);       //최소 시간과 그 중 최고 높이를 출력

    return 0;
}