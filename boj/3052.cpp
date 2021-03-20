#include <cstdio>

int main()
{
    bool mod[42] = {false, };
    int buf, cnt = 0;

    //수를 열 번 입력받은 뒤
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &buf);
        //해당 수를 42로 나눈 나머지가 나옴을 표시한다
        mod[buf % 42] = true;
    }

    //identical한 나머지가 나온 횟수만큼 cnt에 1씩 더한 뒤
    for (int i = 0; i < 42; i++) cnt += mod[i];
    //cnt를 출력한다
    printf("%d\n", cnt);
    
    return 0;
}