#include <cstdio>
#include <cmath>

int main()
{
    //a: 올라가는 거리, b: 미끄러지는 거리, v: 나무 길이
    unsigned int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    //첫 날부터 마지막 전 날까지 a - b미터를 올라가고,
    //마지막 날에는 a 미터를 올라간다
    printf("%d\n", (int)ceil((double)(v - a) / (a - b)) + 1);

    return 0;
}