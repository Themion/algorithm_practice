#include <cstdio>

int main()
{
    //사분면을 y축을 기준으로 180도 회전시킨다
    int quad[2][2] = {{1, 2},
                      {4, 3}};
    int y, x;
    scanf("%d %d", &x, &y);
    printf("%d\n", quad[y < 0][x < 0]);

    return 0;
}