#include <cstdio>

#define MAX_N 1001

// visit[i]: i번 노드를 방문했다면 true, 아니라면 false
bool visit[MAX_N];
// N: 그래프의 노드의 수, graph[i]: i번 노드가 가리키는 노드
int N, graph[MAX_N];

// dfs를 이용해 그래프 탐색
int dfs(int node)
{
    // node를 방문한 적이 있다면 1을 반환
    if (visit[node]) return 1;
    // node를 방문함을 표시
    visit[node] = true;
    // 현재 노드에서 dfs 시 경로의 길이를 반환
    return 1 + dfs(graph[node]);
}

int main()
{
    // ans: 최장 탐색 경로의
    // max: 최장 탐색 경로의 시작 노드
    // temp: dfs의 결과를 저장할 공간
    int ans = 0, max = 0, temp;

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", graph + i);

    for (int i = 1; i <= N; i++)
    {
        // visit 배열을 초기화
        for (int it = 1; it <= N; it++) visit[it] = false;
        // i번 노드에서부터 dfs를 실행
        temp = dfs(i);
        // i번 노드에서의 dfs 경로가 이전까지의 최장 경로보다 길 경우
        // 최장 경로를 갱신
        if (max < temp)
        {
            max = temp;
            ans = i;
        }
    }

    // 최장 경로의 시작 노드를 출력
    printf("%d\n", ans);

    return 0;
}