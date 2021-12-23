#include <cstdio>

#define MAX_LEN 4000

void set_max(int &a, int b) { a = a > b ? a : b; }

int main() {
    // 공통 부분 문자열을 찾을 문자열
    char A[MAX_LEN + 1] = "", B[MAX_LEN + 1] = "";
    // a, b: 두 문자열의 길이, ans: 최장 공통 부분 문자열의 길이
    int a = 0, b = 0, ans = 0;
    // lcs[b_]: b_에서 끝나는 공통 부분 문자열의 길이
    short lcs[MAX_LEN] = { 0, };

    scanf("%s", A);
    scanf("%s", B);

    // 입력받은 두 문자열 A와 B의 길이를 구한다
    for (; A[a]; a++); 
    for (; B[b]; b++);

    // A의 a_, B의 b_에서 끝나는 공통 부분 문자열을 찾는다
    // b_를 증가하는 순으로 찾는다면 이전에 찾은 길이가 이후에 찾을 길이를 오염시키므로
    // b_는 감소하는 방향으로 공통 부분 문자열을 찾는다
    for (int a_ = 0; a_ < a; a_++) for (int b_ = b - 1; b_ >= 0; b_--) {
        // b_의 이전 문자에서 끝난 공통 부분 문자열의 다음 글자가 a_라면
        // b_의 부분 문자열은 이전 문자열의 길이에 글자 하나를 추가한 문자열이 된다
        // 그렇지 않다면 문자열의 연속성이 깨졌으므로 초기화
        lcs[b_] = A[a_] == B[b_] ? lcs[b_ - 1] + 1 : 0;

        // lcs의 최댓값을 ans에 저장
        set_max(ans, lcs[b_]);
    }

    // 최장 부분 문자열의 길이를 출력
    printf("%d\n", ans);

    return 0;
}
