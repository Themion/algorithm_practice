#include <cstdio>

int main()
{
    //x: 만들고자 하는 막대의 길이
    //i: 현재 만들 수 있는 토막 중 가장 긴 토막의 길이
    //ret: 길이 x의 막대를 만들 때 필요한 토막의 수
    int x, i, ret = 0;
    scanf("%d", &x);

    while(x)
    {
        //현재 만들 수 있는 토막 중 가장 긴 토막을 만든다
        for (i = 1; i <= x; i *= 2);
        //for문을 벗어날 때 i는 반드시 x보다 크다
        x -= i / 2;
        //토막을 하나 만들었다
        ret++;
    }

    printf("%d\n", ret);

    return 0;
}