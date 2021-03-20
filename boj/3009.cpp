#include <cstdio>

int main()
{
    //min[a], max[a], sum[a]: 각각 a==0?x:y의 최솟값/최댓값/세 점의 합
    int min[2] = {1001, 1001}, max[2] = {0, 0}, sum[2] = {0, 0};
    //xx, yy: 점을 입력받을 때 버퍼로 사용할 변수
    int xx, yy;

    //세 점을 각각 입력받아 최솟값/최댓값/합을 계산한다
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &xx, &yy);

        min[0] = xx < min[0] ? xx : min[0];
        min[1] = yy < min[1] ? yy : min[1];

        max[0] = xx > max[0] ? xx : max[0];
        max[1] = yy > max[1] ? yy : max[1];

        sum[0] += xx; sum[1] += yy;
    }

    //세 점은 직사각형의 일부이므로 나머지 점은
    //(최솟값 + 최댓값) * 2에서 세 점의 합을 빼면 구할 수 있다
    printf("%d %d\n", 
        (min[0] + max[0]) * 2 - sum[0], 
        (min[1] + max[1]) * 2 - sum[1]);

    return 0;
}