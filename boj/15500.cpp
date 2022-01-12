#include <cstdio>

#define MAX_N 123
#define MAX_K 12345

// str에 원판 하나를 from에서 to로 옮겼음을 표시
void move(char *str, int from, int to) {
    str[0] = from;
    str[1] = to;
}

int main() {
    // pos[i]: i번 원판이 있는 기둥, p: 2번 기둥으로 옮길 원판이 있는 기둥
    bool pos[MAX_N + 1] = { 0, }, p;
    // 원판을 옮긴 기록을 저장할 공간
    char str[MAX_K][4] = { "", };
    // N: 원판의 개수, K: 원판을 옮긴 횟수
    // a[i][j]: i번 기둥에서 밑에서부터 j번째에 있는 원판
    // len[i]: i번 기둥에 있는 원판의 수
    int N, K = 0, a[2][MAX_N + 1] = {{ 0, }}, len[2] = { 0, };

    // 문제의 조건을 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", a[0] + i);

    // 0번 기둥의 길이를 N으로 정한 뒤
    len[0] = N;
    // 원판을 크기의 내림차순으로 2번 기둥으로 이동
    for (; N; N--) {
        // N번 원판이 있는 기둥을 p에 저장한 뒤
        p = pos[N];
        // 해당 기둥에서 N번 원판을 찾을 때까지
        while (len[p] && a[p][--len[p]] != N) {
            // p번 기둥에서 !p번 기둥으로 원판을 옮긴 뒤 이를 pos와 str에 표시
            a[!p][len[!p]] = a[p][len[p]];

            pos[a[!p][len[!p]++]] = !p;
            move(str[K++], p, !p);
        }
        // p번 기둥에서 N번 원판을 2번 기둥으로 이동
        move(str[K++], p, 2);
    }

    // 원판을 옮긴 횟수와 각 원판을 옮긴 기록을 문제의 조건에 맞게 출력
    printf("%d\n", K);
    for (int i = 0; i < K; i++) printf("%d %d\n", ++str[i][0], ++str[i][1]);

    return 0;
}
