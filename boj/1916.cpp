#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define MAX_N 1000
#define _cost first
#define _node second

typedef pair<int, int> edge;

// N: 노드의 수, M: 에지의 수, cost[i]: 시작 노드에서 i번 노드까지의 비용
int N, M, cost[MAX_N + 1];
// 다익스트라 탐색에 사용할 우선순위 큐
priority_queue<edge, vector<edge>, greater<edge>> q;
// v[i]: i번 노드에서 시작하는 에지의 집합
vector<edge> v[MAX_N + 1];

// 에지 e를 q에 push하며 비용을 갱신
int push(edge e) {
    // e를 사용해서 비용이 갱신되지 않는다면 return
    if (cost[e._node] <= e._cost) return 0;

    // 비용을 갱신한 뒤
    cost[e._node] = e._cost;
    // e의 도착 노드에서 시작하는 모든 에지에 대해
    for (auto e_ : v[e._node]) 
        // 비용 갱신이 가능하면 push
        if (cost[e_._node] > cost[e._node] + e_._cost)
            q.push({cost[e._node] + e_._cost, e_._node});

    return e._node;
}

// start 노드에서 dest 노드까지의 최소 비용을 계산
int dijkstra(int start, int dest) {
    // 모든 비용을 INF로 초기화한 뒤
    fill_n(cost, N + 1, INF);

    // start 노드에서 start 노드로 이동하는 가상의 에지를 push
    push({0, start});
    // dest 노드를 탐색할 때까지 탐색 가능한 모든 에지를 push
    while (!q.empty() && push(q.top())!= dest) q.pop();
    // start 노드에서 dest 노드까지의 최소 비용을 반환
    return cost[dest];
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // start, dest: start 노드에서 dest 노드로 이동하는 에지
    int start, dest;

    // 문제의 조건을 입력받는다
    cin >> N >> M;
    while (M--) {
        // cost는 [1, N] 범위만 사용하므로 cost[0]을 임시로 사용
        cin >> start >> dest >> cost[0];
        v[start].emplace_back(cost[0], dest);
    }

    // 시작 노드와 도착 노드를 입력받아 
    cin >> start >> dest;
    cout << dijkstra(start, dest) << '\n';

    return 0;
}
