#include <cstdio>

int main()
{
    //food[0]: 버거, [1]: 콜라
    //temp: 입력받을 버퍼
    int food[2] = {2001, 2001}, buf;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &buf);
        //버거는 3개, 콜라는 2개
        if (food[i > 2] > buf) food[i > 2] = buf;
    }

    printf("%d\n", food[0] + food[1] - 50);

    return 0;
}