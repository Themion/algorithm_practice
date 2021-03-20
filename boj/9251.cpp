#include <cstdio>

//a, b: 입력받을 두 문자열
char a[1001], b[1001];
//len[i + 1][j + 1]: a[0:i]와 b[0:j]의 LCS
short len[1001][1001];

int main()
{
    //aidx, bidx: a와 b의 길이
    int aidx = 0, bidx = 0;
    //a와 b를 입력받는다
    do { scanf("%c", &a[aidx]); } while (a[aidx++] != '\n');
    do { scanf("%c", &b[bidx]); } while (b[bidx++] != '\n');
    //a와 b의 길이에 맞게 각 인덱스를 1씩 빼 준다
    aidx--; bidx--;

    //a와 b에 대해 동적 계획법으로 LCS를 구한다
    for (int i = 0; a[i] != '\n'; i++) for (int j = 0; b[j] != '\n'; j++)
    {
        len[i + 1][j + 1] = len[i][j] + (a[i] == b[j]);
        if (len[i + 1][j + 1] < len[i + 1][j]) len[i + 1][j + 1] = len[i + 1][j];
        if (len[i + 1][j + 1] < len[i][j + 1]) len[i + 1][j + 1] = len[i][j + 1];
    }

    //이렇게 구한 LCS중 가장 큰 값을 출력한다
    printf("%d\n", len[aidx][bidx]);

    return 0;
}