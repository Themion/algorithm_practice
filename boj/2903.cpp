#include <cstdio>

int main()
{
    //n: 중앙 이동 알고리즘을 실행할 횟수
    //ret: 현재 점의 수
    int n, ret = 2;
    scanf("%d", &n);

    //전체 사각형의 점 수가 ret^2개이고 각 점이 만드는 사각형의 개수는 (ret - 1)^2개이다
    //각 사각형을 사등분하는 점을 찍어야 하므로 
    //알고리즘을 실행할 때마다 ret는 2 * ret - 1이 된다
    while(n--) ret += ret - 1;

    //한 변에 점이 ret개 있으므로 전체 점의 개수는 ret^2개이다
    printf("%d\n", ret * ret);

    return 0;
}