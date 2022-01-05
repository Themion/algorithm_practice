#include <cstdio>

#define MAX_N 100

int main() {
    // graph[i][j]: i에서 j로 가는 경로가 있다면 true, 없다면 false
    bool graph[MAX_N][MAX_N];
    // 노드의 개수
    int N;

    // 문제의 조건을 입력받은 뒤
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        scanf("%d", &graph[i][j]);

    // 플로이드-워셜 실행
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            graph[i][j] |= graph[i][k] && graph[k][j];

    // 모든 정점 i, j에 대해 i에서 j로 가는 경로가 있는지 여부를 출력
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        printf("%d%c", graph[i][j], (j == N - 1) ? '\n' : ' ');

    return 0;
}
