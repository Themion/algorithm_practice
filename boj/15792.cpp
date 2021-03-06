#include <cstdio>

int main()
{
    //a, b: 두 수 A와 B를 저장할 공간
    //i: 소수점 연산에 사용할 count 변수
    int a, b, i = 0;
    scanf("%d %d", &a, &b);

    //소수점 앞의 정수 부분을 출력한다
    printf("%d", a / b);
    //a % b가 0이 아니라면, 즉 a / b의 결과가 정수가 아니라면
    if (a % b)
    {
        //우선 a를 b로 나눈 나머지를 a에 저장한다
        a %= b;
        //소숫점이 필요하므로 소숫점을 출력한다
        printf(".");
        //나눠야 할 부분이 아직 남아있고
        //아직 소숫점 아래 1천자리까지 계산하지 않았다면
        while ((a % b) && (i++ < 1000))
        {
            //자릿수를 한 칸 올려주고
            a *= 10;
            //a를 b로 나눈 몪을 계산한 뒤
            printf("%d", a / b);
            //a를 b로 나눈 나머지를 a에 저장한다
            if (a >= b) a %= b;
        }
    }

    return 0;
}