#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 0x3f3f3f3f
#define MAX_N 4000

// 그래프의 각 에지
class edge { 
public:
    // cost: 에지의 비용, node: 도착 노드 
    int cost, node; 
    edge(int cost_, int node_) { this->cost = cost_; this->node = node_; }
};

// 시작 노드에서 도착 노드로의 경로
class path : public edge {
public:
    // 현재 경로를 이루는 오솔길의 수가 홀수라면 true, 아니라면 false
    bool is_odd;
    path(int c, int n, bool is_odd_) : edge(c, n) { this->is_odd = is_odd_; }
};

// 우선순위 큐에 넣기 위한 연산자 오버로딩
bool operator>(path e1, path e2) { return e1.cost > e2.cost; }

// 여우가 이동하는 경로를 찾을 차례라면 true, 아니라면 false
bool fox = true;
// N: 그루터기의 수, M: 오솔길의 수
// cost[i][j]: 1번 그루터기에서 j번 그루터기까지의 경로의 최소 비용
// i가 0 혹은 1일 경우 최소 비용 경로를 이루는 오솔길의 수가 홀수 / 짝수인 경우,
// i가 2일 경우 여우의 경로
int N, M, cost[3][MAX_N];
// 다익스트라 탐색을 위한 우선순위 큐
priority_queue<path, vector<path>, greater<path>> q;
// road[i]: i번 그루터기와 연결된 오솔길
vector<edge> road[MAX_N];

// 1번 그루터기에서 시작한 경로 p에서 오솔길 하나를 통해 이동 가능한 경로 탐색
void push(path p) {
    // mul: 소숫점 계산을 피하기 위해 임의로 정한
    //      여우의 이동 비용에는 항상 2를,
    //      늑대의 홀수번째 비용에는 1을, 짝수번째 비용에는 4를 곱해야 한다
    // i, ii: cost의 인덱싱을 위한 변수
    // cost_: 경로 p에서 오솔길을 한 번 거친 후의 비용
    int mul = fox ? 2 : (p.is_odd ? 4 : 1),
        i = fox ? 2 : p.is_odd,
        ii = fox ? 2 : !p.is_odd,
        cost_;

    // 만일 p의 비용이 기존에 알려진 비용보다 작다면 비용을 갱신
    if (cost[i][p.node] > p.cost) cost[i][p.node] = p.cost;
    // 그렇지 않다면 메모리 초과 방지를 위해 return
    else return;

    // p의 도착 노드에 연결된 모든 오솔길 r에 대해
    for (auto r : road[p.node]) {
        // r을 거친 비용을 한 번 계산한 뒤
        cost_ = p.cost + r.cost * mul;
        // 계산한 비용이 기존 비용보다 작다면 이 경로를 q에 push
        if (cost[ii][r.node] > cost_) q.push({cost_, r.node, !p.is_odd});
    }
}

// 다익스트라 알고리즘을 통해 여우와 늑대의 최적 이동 경로를 각각 계산
void dijkstra() {
    // q에 시작 노드를 push한 뒤
    q.push({0, 0, 0});

    // 가능한 모든 경로를 비용 순으로 탐색
    while (!q.empty()) {
        push(q.top());
        q.pop();
    }

    // 여우의 경로 탐색이 끝났다면 늑대의 경로 탐색을 실행
    fox = !fox;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // a, b, d: 두 그루터기 a와 b를 잇는 오솔길의 비용 d
    // ans: 여우가 늑대보다 빨리 도착할 수 있는 그루터기의 수
    int a, b, d, ans = 0;

    // 문제의 조건을 입력받은 뒤
    cin >> N >> M;
    while (M--) {
        cin >> a >> b >> d;
        road[--a].push_back({ d, --b });
        road[b].push_back({d, a});
    }
    // cost를 모두 INF로 초기화
    fill_n(cost[0], 3 * MAX_N, INF);

    // 다익스트라를 두 번 실행해 여우의 이동 경로와 늑대의 이동 경로를 각각 계산
    dijkstra();
    dijkstra();

    // 1번 그루터기를 제외한 모든 그루터기에 대해
    // 여우가 늑대보다 반드시 더 빨리 도착할 수 있는 그루터기의 수를 계산
    for (int i = 1; i < N; i++) 
        if (cost[0][i] < cost[1][i] && cost[0][i] < cost[2][i]) ans++;

    // 여우가 늑대보다 빨리 도착할 수 있는 그루터기의 수를 출력
    cout << ans << '\n';

    return 0;
}
