#include <cstdio>

#define MAX_N 100

// graph: 그래프, virus[i]: i번 노드를 방문했다면 true, 그렇지 않다면 false
bool graph[MAX_N][MAX_N], virus[MAX_N];
// 노드의 수
int N;

int dfs(int node) {
    // node번 컴퓨터를 통해 감염된 컴퓨터의 수
    int ret = virus[node] = true;

    // node와 연결된 임의의 노드 i에 대해 그 노드를 방문하지 않았다면
    for (int i = 0; i < N; i++) if (graph[node][i] && !virus[i]) {
        // node에 연결된 에지를 해제한 뒤
        graph[node][i] = graph[i][node] = false;
        // 전파한 노드에 대해 dfs
        ret += dfs(i);
    }

    return ret;
}

int main() {
    // a, b: 그래프를 입력받을 때 사용할 변수, cnt: 연결된 컴퓨터 쌍의 수
    int a, b, cnt;

    // 컴퓨터의 수와 그래프를 입력받는다
    scanf("%d\n%d", &N, &cnt);
    while (cnt--) {
        scanf("%d %d", &a, &b);
        graph[--a][--b] = true;
        graph[b][a] = true;
    }

    // 감염된 컴퓨터 수에서 0번 컴퓨터를 뺀 수를 출력
    printf("%d\n", dfs(0) - 1);

    return 0;
}
