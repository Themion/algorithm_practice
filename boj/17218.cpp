#include <cstdio>
#include <cstring>

#define LEN 40
#define i_ (i - 1)
#define j_ (j - 1)
#define len(str) strlen(str)

int main() {
    // A, B: 두 비밀번호, ans: 비밀번호의 최장 공통 문자열
    char A[LEN + 1] = "", B[LEN + 1] = "", ans[LEN + 1][LEN + 1][LEN] = {{ "" }};
    // a, b: 각각 A와 B의 길이
    int a, b;

    // A와 B를 입력받은 뒤 그 길이를 저장
    scanf("%s\n%s", A, B);
    a = len(A);
    b = len(B);
    
    // A와 B의 각 문자에 대해
    for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) {
        // 두 문자가 같은 지점을 발견한다면
        if (A[i_] == B[j_]) {
            // 둘의 이전 문자까지의 공통 문자열을 복사하고 맨 뒤에 비교한 문자를 추가
            strcpy(ans[i][j], ans[i_][j_]);
            ans[i][j][len(ans[i][j])] = A[i_];
        }
        // 그렇지 않다면 A의 이전 문자까지, 혹은 B의 이전 문자까지를 비교한
        // 최장 공통 문자열 중 더 긴 것을 할당
        else strcpy(ans[i][j], 
                    len(ans[i_][j]) > len(ans[i][j_]) ? ans[i_][j] : ans[i][j_]);
    }

    // 두 비밀번호의 최장 공통 문자열을 출력
    printf("%s\n", ans[a][b]);

    return 0;
}
