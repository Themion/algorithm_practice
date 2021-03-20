#include <cstdio>

int main()
{
    //tc: 테스트 케이스의 수
    //len, n: 각 테스트 케이스의 막대의 길이와 개미의 수
    //p: 개미의 위치를 저장할 공간
    //min, max: 각 테스트 케이스에서 개미가 전부 떨어지기까지의 최소/최대 시간
    int tc, len, n, p, min, max;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d", &len, &n);
        min = 0; max = 0;

        while(n--)
        {
            //각 개미의 위치를 p에 저장한 뒤
            scanf("%d", &p);
            //p에 양쪽 끝으로 이동하는 시간 중 짧은 쪽을 저장한 뒤
            //min과 비교해 더 큰 쪽을 min으로 지정한다
            p = p < len / 2 ? p : len - p;
            min = min < p ? p : min;
            //p를 len - p로 바꾼 뒤 max와 비교해 더 큰 쪽을 max로 지정한다
            p = len - p;
            max = max < p ? p : max;
        }

        //개미가 떨어지기까지의 최소/최대 시간을 출력한다
        printf("%d %d\n", min, max);
    }

    return 0;
}