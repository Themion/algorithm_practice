#include <cstdio>

#define MAX_N 200

int main () {
    // map[i][j]: 도시 i에서 도시 j로 이동이 가능하다면 true, 아니라면 false
    bool map[MAX_N][MAX_N] = {{ 0, }};
    // N: 도시의 수, M: 여행 계획의 경로 길이
    // from, to: 각 경로의 시작과 끝 도시
    int N, M, from, to;
    
    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        scanf("%d", &from);
        map[i][j] = map[j][i] = from;
    }

    // 플로이드-워셜 기법을 이용해 각 도시가 연결되어 있는지 확인
    for (int k = 0; k < N; k++) {
        map[k][k] = true;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            map[i][j] |= map[i][k] && map[k][j];
    }

    // 여행을 시작할 도시를 입력받은 뒤
    scanf("%d", &from);
    // 각 경로에 대해
    while (--M) {
        // 경로의 끝 지점을 입력받고
        scanf("%d", &to);
        // from에서 to로 이동하는 경로가 없다면 NO를 출력하고 종료
        if (!map[from - 1][to - 1]) break;
        // 현재 경로의 끝을 다음 경로의 시작으로 지정
        from = to;
    }

    // 이동 불가능한 경로가 있다면 M은 자연수가 되므로
    // M에 따라 해당하는 답을 출력한 뒤 종료
    return printf("%s\n", M ? "NO" : "YES") & 0;
}
