#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

#define MAX_V 20000
#define INF 0x3f3f3f3f

#define _cost first
#define _node second

// visit[i]: 노드 i에 방문했다면 true
bool visit[MAX_V + 1];
// K: 시작 노드, cost[i]: 시작 노드에서 노드 i까지의 비용
int K, cost[MAX_V + 1];
// graph[i]: 노드 i와 연결된 에지를 <cost, node> 꼴로 저장
vector<edge> graph[MAX_V + 1];
// 다익스트라에 사용할 우선순위 큐
priority_queue<edge, vector<edge>, greater<edge>> q;

void push(edge e) {
    // e를 사용해서 비용 감소가 발생하지 않는다면 return
    if (visit[e._node] || cost[e._node] <= e._cost) return;

    // e를 이용해서 그래프를 탐색한 뒤
    visit[e._node] = true;
    cost[e._node] = e._cost;
    
    // e와 연결된 노드의 각 에지 중 비용 감소를 발생시키는 노드를 q에 push
    for (auto e_ : graph[e._node]) 
        if (!visit[e_._node] && cost[e_._node] > cost[e._node] + e_._cost)
            q.push({cost[e._node] + e_._cost, e_._node});
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // V, E: 그래프의 노드와 에지의 수
    // u, v, w: u에서 v로 향하고 가중치 w를 갖는 에지
    int V, E, u, v, w;

    // 문제의 조건을 입력받은 뒤
   cin >> V >> E >> K;
    while (E--) {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    // 각 노드까지 걸리는 시간을 MAX로 초기화
    fill_n(cost, MAX_V, INF);

    // 다익스트라 기법을 이용해 노드 K에서 다른 노드로의 비용을 계산
    // 시작 노드에서 시작 노드로 향하는 가상의 에지를 push한 뒤
    push({0, K});
    // 모든 에지를 비용이 작은 에지 순으로 탐색
    while (!q.empty()) {
        push(q.top());
        q.pop();
    }

    // 다익스트라 결과 경로가 존재한다면 그 비용을, 없다면 INF를 출력
    for (int i = 1; i <= V; i++) {
        if (cost[i] < INF) cout << cost[i] << '\n';
        else cout << "INF\n";
    }

    return 0;
}
