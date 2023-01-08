#include <cstdio>

#define MAX_LEN 50

int cmp(int a, int b) { return a > b ? a : b; }

int main() {
    // 괄호 문자열의 길이
    int len = 0;
    // 필요한 특정 괄호의 개수
    int cnt;
    // 필요한 '('의 수
    int l_brac = 0;
    // 필요한 ')'의 수
    int r_brac = 0;
    // 괄호 문자열을 입력받을 공간
    char S[MAX_LEN + 1] = { 0, };

    // 괄호 문자열을 입력받은 뒤 그 길이를 계산
    scanf("%s", S);
    for (; S[len] != '\0'; len++);

    // 문자열을 왼쪽부터 차례로 탐색하여 필요한 '('의 수를 계산
    // 문자열의 왼쪽에 ')'가 들어갈 경우 불필요한 괄호 문자열이 생기므로 오로지 '('만 추가
    cnt = 0;
    for (int i = 0; i < len; i++) {
        cnt += (S[i] == ')') ? 1 : -1;
        l_brac = cmp(cnt, l_brac); 
    }

    // 문자열을 오른쪽부터 차례로 탐색하여 필요한 ')'의 수를 계산
    // 문자열의 오른쪽에 '('가 들어갈 경우 불필요한 괄호 문자열이 생기므로 오로지 ')'만 추가
    cnt = 0;
    for (int i = len - 1; i >= 0; i--) {
        cnt += (S[i] == '(') ? 1 : -1;
        r_brac = cmp(cnt, r_brac); 
    }

    // 필요한 두 괄호 문자의 수를 더한 값을 반환
    printf("%d\n", l_brac + r_brac);

    return 0;
}
