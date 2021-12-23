#include <cstdio>

#define MAX_M 1000000

int main() {
    // IOI 문자열을 찾을 문자열
    char S[MAX_M + 1];
    // N: IOI 문자열의 길이, M: S의 길이
    // idx: S와 비교할 IOI 문자열의 위치, ans: S에서 찾은 IOI 문자열의 개수
    int N, M, idx = 0, ans = 0;

    // 문제의 조건을 입력받은 뒤
    scanf("%d\n%d\n%s", &N, &M, S);
    // IOI 문자열의 순서를 그 길이로 바꾼다
    N = 2 * N + 1;

    // S의 문자에 대해
    for (int i = 0; i < M; i++) {
        // S와 IOI 문자열을 한 글자씩
        if (S[i] == (idx % 2 ? 'O' : 'I')) {
            // S에서 IOI 문자열을 모두 찾았다면 ans에 1을 더하고
            // 기존 비교를 재활용하기 위해 idx에서 2를 뺀다
            ans += (++idx == N);
            idx -= (idx == N) << 1;
        }
        // 매칭에 실패했다면 S[i]에 따라 idx를 다시 설정
        else idx = S[i] == 'I';
    }

    // S에서 찾은 IOI 문자열의 개수를 출력
    printf("%d\n", ans);

    return 0;
}
