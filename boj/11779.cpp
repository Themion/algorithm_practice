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
// route[i]: 시작 노드에서 노드 i까지의 경로
vector<int> route[MAX_N + 1];

// a에 b를 push한 후의 벡터를 반환
vector<int> operator+(vector<int> a, int b) {
    a.push_back(b);
    return a;
}

// 에지 e를 q에 push하며 비용과 경로를 갱신
int push(edge e) {
    // e의 도착 노드에서 시작하는 모든 에지 e_를 사용해 비용 갱신이 가능하다면
    for (auto e_ : v[e._node]) if (cost[e_._node] > cost[e._node] + e_._cost) {
        // 경로와 비용을 갱신한 뒤 e_를 q에 push
        route[e_._node] = route[e._node] + e_._node;
        q.push({cost[e_._node] = cost[e._node] + e_._cost, e_._node});
    }

    // 에지 e의 도착 노드를 반환
    return e._node;
}

// start 노드에서 dest 노드까지의 최소 비용을 계산
int dijkstra(int start, int dest) {
    // 모든 비용을 INF로 초기화한 뒤
    fill_n(cost, N + 1, INF);

    // start 노드에서 start 노드로의 비용과 경로를 초기화
    cost[start] = 0;
    route[start].emplace_back(start);

    // start 노드에서 start 노드로 이동하는 가상의 에지를 push
    push({cost[start], start});
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
    for (cin >> N >> M; M--; ) {
        // cost는 [1, N] 범위만 사용하므로 cost[0]을 임시로 사용
        cin >> start >> dest >> cost[0];
        v[start].emplace_back(cost[0], dest);
    }

    // 시작 노드와 도착 노드를 입력받은 뒤
    cin >> start >> dest;
    // 시작 노드에서 도착 노드로 이동하는 데 드는 최소 비용과 그 경로의 길이를 출력
    cout << dijkstra(start, dest) << '\n' << route[dest].size() << '\n';
    // 시작 노드에서 도착 노드로 이동하는 최소 경로를 출력
    for (auto n : route[dest]) cout << n << ' ';
    cout << '\n';

    return 0;
}
