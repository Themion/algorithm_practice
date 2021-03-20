#include <cstdio>

int main()
{
    //체스판의 각 칸의 정보를 입력받을 버퍼
    char buf;
    //흰 칸 위에 존재하는 말의 수
    int ret = 0;

    //체스판의 각 칸에 대해
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            //칸 상태는 항상 입력받는다
            scanf("%c", &buf);
            //현재 칸이 흰색 칸이라면 해당 칸 위의 말의 수를 ret에 더한다
            if((i + j) % 2 == 0) ret += (buf == 'F');
        }

        //string과 string 사이의 공백 문자를 입력받는다
        scanf("\n");
    }

    //흰 칸 위의 말의 수를 출력한다
    printf("%d\n", ret);

    return 0;
}