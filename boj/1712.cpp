#include <cstdio>
#include <cmath>

int main()
{
    //a: 고정지출, b: 가변지출, c: 단가
    //ret: 결과값을 int 형으로 저장할 변수
    unsigned int a, b, c, ret;
    scanf("%d %d %d", &a, &b, &c);

    //단가가 맞지 않으면 -1을 출력
    if (c <= b) ret = -1;
    //수익이 발생한다면 수익분기점을 계산
    else ret = ceil(a / (c - b)) + 1;

    printf("%d\n", ret);

    return 0;
}