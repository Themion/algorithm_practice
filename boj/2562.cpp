#include <cstdio>

int main()
{
    int idx, max = -1, buf;
    //수를 9번 입력받아
    for (int i = 1; i <= 9; i++)
    {
        //입력받은 수가 최대 수라면
        scanf("%d", &buf);
        //입력받은 수와 그 순서를 저장한 뒤
        if(max < buf)
        {
            max = buf;
            idx = i;
        }
    }

    //최댓값과 그 순서를 출력한다
    printf("%d\n%d", max, idx);

    return 0;
}