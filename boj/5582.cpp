#include <cstdio>

// 공통 부분 문자열을 찾을 문자열
char a[4001] = "", b[4001] = "";
// lcs[b_]: b_에서 끝나는 공통 부분 문자열의 길이
short lcs[4000];

void set_max(int &a, int b) { a = a > b ? a : b; }

int main()
{
    int a_len = 0, b_len = 0, ans = 0;
    scanf("%s", a);
    scanf("%s", b);

    // 입력받은 두 문자열 a와 b의 길이를 구한다
    for (int i = 0; a_len * b_len == 0; i++)
    {
        if (!a_len && a[i] == '\0') a_len = i;
        if (!b_len && b[i] == '\0') b_len = i;
    }

    // a의 a_에서 시작해 b의 b_에서 끝나는 공통 부분 문자열을 찾는다
    for (int a_ = 0; a_ < a_len; a_++)
        for (int b_ = b_len - 1; b_ >= 0; b_--)
        {
            // b_의 이전 문자에서 끝난 공통 부분 문자열의 다음 글자가 a_라면
            // b_의 부분 문자열은 이전 문자열의 길이에
            // 글자 하나를 추가한 문자열이 된다
            // 그렇지 않다면 문자열의 연속성이 깨졌으므로 초기화
            lcs[b_] = a[a_] == b[b_] ? lcs[b_ - 1] + 1 : 0;

            // lcs의 최댓값을 ans에 저장
            set_max(ans, lcs[b_]);
        }

    // 최장 부분 문자열의 길이를 출력
    printf("%d", ans);

    return 0;
}