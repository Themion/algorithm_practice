#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 1000

// edge[i][j]: 노드 i와 j가 연결되어 있다면 true, 아니라면 false
// visit: dfs에선 각 노드를 방문했다면 true, bfs에선 각 노드를 방문했다면 false
bool edge[MAX_N + 1][MAX_N + 1], visit[MAX_N + 1];
// N: 노드의 개수, V: 탐색을 시작할 노드
int N, V;

// dfs를 재귀적으로 구현
void dfs(int node) {
    // 현재 노드를 출력한 뒤 현재 노드를 방문했음을 표시한다
    printf("%d ", node);
    visit[node] = true;

    // 현재 노드와 연결된 노드 중 방문하지 않은 노드를 방문한다
    for (int i = 1; i <= N; i++) if ((edge[node][i]) && (!visit[i])) dfs(i);
}

// bfs를 큐를 이용하여 구현
void bfs() {
    // idx: 배열에 접근하기 위한 인덱스
    // arr: bfs 결과값을 저장하기 위한 배열
    int idx = 0, arr[MAX_N + 1] = { 0, };

    // 시작 노드를 배열에 넣고 방문함을 표시
    arr[idx++] = V;
    visit[V] = false;

    // 큐에 들어있는 노드에 대해
    for (int i = 0; arr[i]; i++) {
        // 현재 노드를 출력
        printf("%d ", arr[i]);

        // 현재 노드와 연결된 노드 중 아직 방문하지 않은 노드에 대해
        for (int n = 1; n <= N; n++) if (edge[arr[i]][n] && visit[n]) {
            // 그 노드를 배열에 넣고 방문했음을 표시한다
            arr[idx++] = n;
            visit[n] = false;
        }
    }

    // 모든 노드를 방문했으므로 줄을 바꾼다
    printf("\n");
}

int main() {
    // M: 에지의 개수, a, b: 에지를 입력받을 때 사용할 공간
    int M, a, b;

    // 문제의 조건을 입력받는다
    scanf("%d %d %d", &N, &M, &V);
    while (M--) {
        scanf("%d %d", &a, &b);
        edge[a][b] = true;
        edge[b][a] = true;
    }

    // dfs와 bfs를 순차적으로 실행
    dfs(V);
    printf("\n");
    bfs();

    return 0;
}
