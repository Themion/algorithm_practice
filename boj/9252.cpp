#include <cstdio>

// A, B: LCS를 구할 두 문자열
char A[1001], B[1001];
// len[i + 1][j + 1]: A[0:i]와 B[0:j]의 LCS
short len[1001][1001];

// 재귀법으로 LCS를 찾아 출력
void print(int a, int b)
{
    // A와 B의 인덱스 중 하나라도 0 이하로 떨어진다면 재귀 종료
    if (a <= 0 || b <= 0) return;
    // A와 B에서 값이 같은 인덱스를 발견했다면
    else if (A[a - 1] == B[b - 1])
    {
        // 해당 인덱스 이전까지의 문자열 중 LCS를 출력한 뒤
        print(a - 1, b - 1);
        // 일치하는 문자를 출력
        printf("%c", A[a - 1]);
    }
    // 그렇지 않다면 부분 문자열의 길이를 최대한 줄인다
    else if (len[a][b] == len[a - 1][b]) print(a - 1, b);
    else if (len[a][b] == len[a][b - 1]) print(a, b - 1);
}

int main()
{
    //a, b: A와 B의 길이
    int a = 0, b = 0;
    //A와 B를 입력받는다
    do { scanf("%c", &A[a]); } while (A[a++] != '\n');
    do { scanf("%c", &B[b]); } while (B[b++] != '\n');
    //A와 B의 길이에 맞게 각 인덱스를 1씩 빼 준다
    a--; b--;

    //A와 B에 대해 동적 계획법으로 LCS의 길이를 구한다
    for (int i = 0; A[i] != '\n'; i++) for (int j = 0; B[j] != '\n'; j++)
    {
        len[i + 1][j + 1] = len[i][j] + (A[i] == B[j]);
        if (len[i + 1][j + 1] < len[i + 1][j]) len[i + 1][j + 1] = len[i + 1][j];
        if (len[i + 1][j + 1] < len[i][j + 1]) len[i + 1][j + 1] = len[i][j + 1];
    }

    // A와 B의 LCS의 길이를 출력한 뒤 재귀적으로 LCS를 찾아 출력
    printf("%d\n", len[a][b]);
    print(a, b);
    printf("\n");

    return 0;
}