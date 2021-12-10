#include <iostream>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f
#define MAX_N 800
#define _cost first
#define _node second

using namespace std;

typedef pair<int, int> edge;
typedef priority_queue<edge, vector<edge>, greater<edge>> pq;

// visit[i]: 노드 i에 방문했다면 true
bool visit[MAX_N + 1];
// N: 노드의 개수, v: 두 경유 노드
// cost: 다익스트라 알고리즘으로 구한 각 노드까지의 거리
int N, v[2], cost[MAX_N + 1] = { 0, };
// 모든 에지를 탐색하기 위한 우선순위 큐
pq q;
// graph[i]: 노드 i와 연결된 에지를 <cost, node> 꼴로 저장
vector<edge> graph[MAX_N + 1];

int min(int a, int b) { return a < b ? a : b; }

void push(edge e) {
    // e를 방문했거나 사용해서 비용 감소가 발생하지 않는다면 return
    if (visit[e._node] || cost[e._node] <= e._cost) return;

    // e를 이용해서 그래프를 탐색한 뒤
    visit[e._node] = true;
    cost[e._node] = e._cost;

    // e와 연결된 노드의 각 에지 중 
    for (auto e_ : graph[e._node]) 
        // 아직 방문하지 못한 노드와 연결된 에지를 q에 push
        if (!visit[e_._node])
            q.push({cost[e._node] + e_._cost, e_._node});
}

// 다익스트라 알고리즘을 통해 start 노드에서 다른 노드까지의 비용을 계산
void dijkstra(int start) {
    // visit과 cost를 초기화한 뒤
    fill_n(visit, MAX_N + 1, false);
    fill_n(cost, MAX_N + 1, INF);
    q = pq();

    // 시작 노드에서 시작 노드로 향하는 가상의 에지를 push
    push({0, start});
    
    // 목적지와 경유지를 모두 방문할 때까지
    // 모든 에지를 비용이 작은 에지 순으로 탐색
    while (!q.empty() && 
           (cost[v[0]] == INF || cost[v[1]] == INF || cost[N] == INF)) {
        push(q.top());
        q.pop();
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // E: 에지의 개수, a, b, c : 각 에지를 입력받을 때 사용할 공간
    // v0v1: 1 -> v0 -> v1 -> N, v1v0: 1 -> v1 -> v0 -> N
    // ans: v0v1과 v1v0 중 작은 값을 저장해 함수 호출을 줄인다
    int E, a, b, c, v0v1, v1v0, ans = 0;
    
    // 문제 조건 입력
    cin >> N >> E;
    while (E--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
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
    // 두 경유 노드를 거쳐 1 -> N 경로를 완성시킬 수 있다면 그 경로의 비용을 출력
    cout << ((ans < INF) ? ans : -1) << '\n';

    return 0;
}
