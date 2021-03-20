#include <cstdio>

int w, h;
bool field[50][50];

//양배추가 상하좌우로 있는지 찾기 위해 bfs를 사용
void bfs(int x, int y)
{
    field[y][x] = false;

    if((x - 1 >= 0) && field[y][x - 1]) bfs(x - 1, y);
    if((y - 1 >= 0) && field[y - 1][x]) bfs(x, y - 1);
    if((x + 1 < w) && field[y][x + 1]) bfs(x + 1, y);
    if((y + 1 < h) && field[y + 1][x]) bfs(x, y + 1);
}

//길이가 너무 길어져 따로 나눔
int find_num(int cnt)
{
    //x, y: 밭의 각 칸을 지정할 인덱스
    //ret: 출력할 값
    int x, y, ret = 0;

    //심은 양배추의 수만큼 양배추의 위치를 입력받는다
    while (cnt--)
    {
        scanf("%d %d", &x, &y);
        field[y][x] = true;
    }

    //모든 칸을 찾아보면서 해당 칸에 양배추가 있다면
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            if (field[j][i])
            {
                //bfs를 통해 양배추 그룹을 찾아낸다
                bfs(i, j);
                //그룹 하나당 벌레 하나가 필요하다
                ret++;
            }

    return ret;
}

int main()
{
    //tc: 테스트 케이스의 수
    //cnt: 양배추의 수
    int tc, cnt;

    //테스트 케이스의 수를 입력받은 뒤
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d %d", &w, &h, &cnt);
        printf("%d\n", find_num(cnt));
    }

    return 0;
}