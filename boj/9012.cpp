#include <cstdio>

int main()
{
    //괄호 문자열을 입력받을 공간
    char buf;
    //tc: 테스트 케이스의 수
    //cnt: 몇개의 괄호가 열려있는지를 카운트한다
    int tc, cnt;

    scanf("%d\n", &tc);

    for (int t = 0; t < tc; t++)
    {
        //맨 처음엔 어떤 괄호도 열려있지 않다
        cnt = 0;

        //괄호 문자열을 문자 단위로 입력받아서
        while (scanf("%c", &buf) == 1)
        {
            //괄호가 얼마나 열려있는지를 계속해서 갱신한다
            if      (buf == '(') cnt++;
            else if (buf == ')') cnt--;
            else if (buf == '\n') break;

            //어느 시점에서 열린 괄호의 수가 음수라면 break
            if (cnt < 0) break;
        }

        //문자열이 끝났을 때 열린 괄호의 수가 0이 아니라면 NO를 출력
        if(cnt != 0)
        {
            while (buf != '\n') scanf("%c", &buf);
            printf("NO\n");
        }
        //그렇지 않다면 YES를 출력
        else printf("YES\n");
    }

    return 0;
}