#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 200000

// C[i]: 노드 i를 칠할 색
int C[MAX_N + 1] = { 0, };
// graph[i]: 노드 i와 연결된 노드의 집합
vector<int> graph[MAX_N + 1];

int dfs(int node, int parent) {
    // node를 루트 노드로 하는 서브트리를 칠하는 최소 횟수
    // 현재 노드가 그 부모 노드와 색이 다르다면 색을 칠한다
    int ret = C[node] != C[parent];
    // 모든 자식 노드에 대해 dfs를 실행한 결과를 ret에 더해 반환
    for (auto n : graph[node]) if (n != parent) ret += dfs(n, node);
    return ret;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 노드의 개수, a, b: 에지를 입력받을 공간
    int N, a, b, ans = 0;

    // 노드의 수와 각 노드를 칠할 색을 입력받고
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> C[i];
    // 각 에지를 입력받아 graph에 노드의 집합 형태로 저장
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 트리를 칠할 최소 횟수를 출력
    cout << dfs(1, 0) << '\n';
    
    return 0;
}
