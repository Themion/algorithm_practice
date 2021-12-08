#include <iostream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f
#define MAX_N 800
#define _cost first
#define _node second

using namespace std;

typedef pair<int, int> edge;

// N: 노드의 개수, cost: 다익스트라 알고리즘으로 구한 각 노드까지의 거리
int cost[MAX_N + 1] = { 0, };
// graph[i]: 노드 i와 연결된 에지를 <cost, node> 꼴로 저장
vector<edge> graph[MAX_N + 1];

int min(int a, int b) { return a < b ? a : b; }

// 다익스트라 알고리즘을 통해 start 노드에서 다른 노드까지의 비용을 계산
void dijkstra(int start) {
    // 모든 에지를 탐색하기 위한 우선순위 큐
    priority_queue<edge, vector<edge>, greater<edge>> q;

    // 각 노드까지 걸리는 시간을 INF로 초기화
    fill_n(cost, MAX_N + 1, INF);

    // 시작 노드에서 시작 노드로 향하는 가상의 에지를 push
    q.push({0, start});
    
    // q 안에서 비용이 작은 에지 순으로
    while (!q.empty()) {
        edge e = q.top();
        q.pop();

        // 현재 에지를 사용해서 비용 감소가 발생하지 않는다면 continue
        if (cost[e._node] <= e._cost) continue;

        // 현재 에지를 사용해 그래프를 탐색
        cost[e._node] = e._cost;
        for (auto e_ : graph[e._node])
            q.push({cost[e._node] + e_._cost, e_._node});
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 노드의 개수, E: 에지의 개수
    // a, b, c : 각 에지를 입력받을 때 사용할 공간, v: 두 경유 노드
    // v0v1: 1 -> v0 -> v1 -> N, v1v0: 1 -> v1 -> v0 -> N
    // ans: v0v1과 v1v0 중 작은 값을 저장해 함수 호출을 줄인다
    int N, E, a, b, c, v[2], v0v1, v1v0, ans = 0;
    
    // 문제 조건 입력
    cin >> N >> E;
    while (E--) {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> v[0] >> v[1];

    // 시작 노드와 v[0], v[1]에서 다른 노드까지 걸리는 비용을 각각 계산한 뒤
    // 시작 노드에서 시작해 v[0], v[1] 노드를 모두 거쳐 노드 N까지 이동하는
    // 경로의 최소 비용을 계산
    dijkstra(1);
    v0v1 = min(INF, cost[v[0]]);
    v1v0 = min(INF, cost[v[1]]);

    dijkstra(v[0]);
    v0v1 = min(INF, v0v1 + cost[v[1]]);
    v1v0 = min(INF, v1v0 + cost[N]);

    dijkstra(v[1]);
    v0v1 = min(INF, v0v1 + cost[N]);
    v1v0 = min(INF, v1v0 + cost[v[0]]);

    // 다익스트라 기법으로 얻은 경로의 최솟값을 계산
    ans = v0v1 < v1v0 ? v0v1 : v1v0;
    // 두 경유 노드를 거쳐 1 -> N 경로를 완성시킬 수 있다면
    // 그 경로의 비용을 출력
    cout << ((ans < INF) ? ans : -1) << '\n';

    return 0;
}
