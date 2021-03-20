#include <cstdio>

bool paper[128][128] = {{ false, }};
int cnt[2] = {0, 0};

//색종이 분할정복
bool DNQ(int y, int x, int size)
{
    if (size == 1)  //검사하고자 하는 색종이의 크기가 1이라면
    {
        //해당 색종이 수를 1만큼 늘리고
        cnt[paper[y][x]] += 1;
        //반드시 한 종류의 색종이만 사용하므로 true를 반환
        return true;
    }

    int yy, xx;         //yy, xx: 좌표를 미리 계산한 다음 사용한다
    bool ret = true;    //ret: 현재 색종이가 단색일 때만 true
    size /= 2;          //색종이를 네개로 나누므로 size로 절반씩 감소

    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
    {
        //네 조각의 왼쪽 위 귀퉁이의 좌표를 계산한 뒤
        yy = y + i * size; xx = x + j * size;
        //네 조각이 단색인지, 또 네 조각의 색이 서로 같은지 확인
        ret &= DNQ(yy, xx, size) && paper[y][x] == paper[yy][xx];
    }

    //위의 이중 for문 결과 단색인 것 같다면 네 조각을 하나로 계산
    if (ret) cnt[paper[y][x]] -= 3;

    //이 조각이 단색인지 여부를 반환
    return ret;
}

int main()
{
    int N, buf;
    scanf("%d", &N);
    //입력값 0, 1은 bool로 형변환 시 false, true로 변환
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        scanf("%d", &(paper[i][j]));

    //입력받은 색종이의 조합을 분할 정복으로 계산
    DNQ(0, 0, N);

    //사용된 흰 종이, 파란 종이의 수를 출력
    printf("%d\n%d\n", cnt[0], cnt[1]);

    return 0;
}