#include <cstdio>

int main()
{
    //cnt: 배열의 크기, buf: 배열의 각 성분을 저장
    //ret: 배열의 인덱스와 값이 맞지 않는 성분의 수
    int cnt, buf, ret = 0;

    //배열의 크기를 입력받은 뒤
    scanf("%d", &cnt);
    //배열의 각 성분에 대해
    for (int i = 1; i <= cnt; i++)
    {
        //성분의 값을 입력받고
        scanf("%d", &buf);
        //ret에 그 둘이 다르다면 1을, 같다면 0을 더한다
        ret += buf != i;
    }

    //ret을 출력한다
    printf("%d\n", ret);
    return 0;
}