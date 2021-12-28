#include <cstdio>

#define MAX_LEN 1000

short max(short a, short b) { return a > b ? a : b; }

int main() {
    // A, B: 입력받을 두 문자열
    char A[MAX_LEN + 1], B[MAX_LEN + 1];
    // a, b: A와 B를 탐색하기 위한 인덱스
    int a, b;
    // len[a % 2][b + 1]: A[0:a]와 B[0:b]의 LCS
    short len[2][MAX_LEN + 1] = {{ 0, }};

    // A와 B를 입력받는다
    scanf("%s\n%s", A, B);

    // A와 B에 대해 동적 계획법으로 LCS의 길이를 구한다
    for (a = 0; A[a]; a++) for (b = 0; B[b]; b++)
        len[!(a % 2)][b + 1] = max(len[a % 2][b] + (A[a] == B[b]), 
                                max(len[!(a % 2)][b], len[a % 2][b + 1]));

    // 구한 LCS의 최댓값을 출력
    printf("%hd\n", len[a % 2][b]);

    return 0;
}
