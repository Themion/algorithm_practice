#include <cstdio>

#define MAX_N 8

// visit[i]: 수열에 i가 사용되었다면 true, 아니라면 false
bool visit[MAX_N + 1];
// str: 출력할 수열을 문자열 형태로 저장
char str[2 * MAX_N + 1];
// N: 사용할 자연수의 종류, M: 수열의 길이
int N, M;

void backtrack(int len) {
    // len이 M * 2라면 수열을 모두 채운 것이므로 수열을 출력한 뒤 종료
    if (len == M * 2) {
        printf("%s\n", str);
        return;
    }

    // 1부터 N 중 사용되지 않은 수가 있다면
    for (int i = 1; i <= N; i++) if (!visit[i]) {
        // 수열에 추가한 뒤
        str[len] = i + '0';
        str[len + 1] = ' ';
        visit[i] = true;
        // 수열의 다음 수를 채우고
        backtrack(len + 2);
        // 수열에서 i를 제거
        visit[i] = false;
    }
}

int main() {
    // N과 M을 입력받은 뒤 조건을 만족하는 수열을 모두 출력
    scanf("%d %d", &N, &M);
    backtrack(0);
    return 0;
}
