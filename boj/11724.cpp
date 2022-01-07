#include <iostream>

using namespace std;

#define MAX_N 1000

// parent[i]: 노드 i의 부모 노드
int parent[MAX_N + 1];

// 노드 node가 속한 트리의 루트 노드를 재귀적으로 탐색
int root(int node) {
    if (parent[node] && parent[node] != node)
        return parent[node] = root(parent[node]);
    return parent[node] = node;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // visit[i]: 루트 노드가 i인 그래프를 탐색했다면 true
    bool visit[MAX_N + 1] = { 0, };
    // N: 노드의 수, M: 에지의 수, a, b: 각 에지를 이루는 두 노드, ans: 그래프의 수
    int N, M, a, b, ans = 0;

    // 노드와 에지의 수를 입력받은 뒤 각 에지에 대해
    for (cin >> N >> M; M--; ) {
        // 에지를 이루는 두 노드를 입력받고
        cin >> a >> b;

        // 두 노드가 속한 트리의 루트 노드를 계산한 뒤
        a = root(a);
        b = root(b);
        // 두 트리를 연결
        parent[a] = b;
    }

    // 각 노드가 속한 트리의 루트 노드만을 방문한 뒤
    for (int i = 1; i <= N; i++) visit[root(i)] = true;
    // 루트 노드의 개수를 계산해 ans에 저장
    for (int i = 1; i <= N; i++) ans += visit[i];

    // 루트 노드의 개수, 즉 연결 요소의 개수를 출력
    cout << ans << '\n';
    
    return 0;
}
