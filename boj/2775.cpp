#include <cstdio>

//apartment[k][n]: k층 n호에 사는 거주민의 수
int apartment[15][15] = {{ 0, }};

int get_num(int k, int n)
{
    //아직 해당 방의 거주민 수를 알아내지 못했다면
    if (!apartment[k][n])
    {
        //0층인 경우에는 호 수만큼 사람이 살고 있고
        if (k == 0) apartment[k][n] = n;
        //그렇지 않은 경우는 아파트 규칙에 맞게 거주민 수를 유추한다
        else for (int i = 1; i <= n; i++)
            apartment[k][n] += get_num(k - 1, i);
    }

    //거주민 수를 반환한다
    return apartment[k][n];
}

int main()
{
    //tc: 테스트 케이스의 수, k, n: 아파트의 층과 호 수
    int tc, k, n;
    scanf("%d", &tc);

    //각 테스트 케이스에 대해
    while (tc--)
    {
        //거주민 수를 알고자 하는 방의 층과 호 수를 입력받은 뒤
        scanf("%d\n%d", &k, &n);
        //동적 계획법을 이용해 이를 계산한다
        printf("%d\n", get_num(k, n));
    }

    return 0;
}