#include <cstdio>
#include <queue>
#include <vector>

#define MAX_N 1001
#define INF 0x3f3f3f3f
#define _cost first
#define _node second

using namespace std;

typedef pair<int, int> edge;

int N, M, X;
// 접근 가능한 에지를 상시 정렬하기 위한 우선순위 큐
priority_queue<edge, vector<edge>, greater<edge>> q;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void push(vector<edge> v, edge e) {
    // 접근한 노드에서 아직 큐에 넣지 않은 에지를 모두 큐에 push
    for (auto e_ : v) q.push({e_._cost + e._cost, e_._node});
    // 한 번 방문한 노드의 에지는 사이클 방지를 위해 제거
    v.empty();
}

// 다익스트라 알고리즘을 통해 최단 거리를 계산한다
void dijkstra(vector<edge> v[], int cost[]) {
    // 최초 비용을 매우 큰 값인 INF로 초기화
    fill_n(cost, N + 1, INF);
    // X에서 X로 이동하는 비용은 항상 0
    cost[X] = 0;
    // X에 연결된 그래프를 모두 q에 push
    push(v[X], {0, 0});

    // 접근 가능한 에지가 존재할 때
    while (!q.empty()) {
        // 비용이 가장 적은 에지를 우선순위 큐에서 제거
        edge e = q.top();
        q.pop();

        // 굳이 이용할 필요가 없는 노드라면 이용하지 않는다
        if (cost[e._node] <= e._cost) continue;

        // 기존의 최소 거리와 현재 에지를 경유한 거리 중 가장 작은 거리를 사용
        cost[e._node] = e._cost;
        push(v[e._node], e);
    }
}

int main() {
    // start, dest, cost: 에지를 입력받을 때 사용
    // ans: 다익스트라로 계산한 거리 합의 최솟값을 저장
    int start, dest, cost, ans = 0;
    // start_cost[i]: 노드 i에서 노드 X로 가는 경로의 최소 비용
    // dest_cost[i]: 노드 X에서 노드 i로 가는 경로의 최소 비용
    int start_cost[MAX_N], dest_cost[MAX_N];
    // start_v[i]: 노드 i에서 시작하는 에지의 집합
    // dest_v[i]: 노드 i에서 끝나는 에지의 집합
    vector<edge> start_v[MAX_N], dest_v[MAX_N];

    scanf("%d %d %d", &N, &M, &X);

    // 각 에지를 입력받아 저장
    while (M--) {
        scanf("%d %d %d", &start, &dest, &cost);
        start_v[start].push_back({cost, dest});
        dest_v[dest].push_back({cost, start});
    }

    // 다익스트라를 이용해 노드 X부터와 최단 경로와 노드 X로의 최소 비용을 계산
    dijkstra(start_v, start_cost);
    dijkstra(dest_v, dest_cost);
    
    // 왕복 비용의 합의 최대를 계산하여 출력
    for (int i = 1; i <= N; i++) 
        ans = max(ans, start_cost[i] + dest_cost[i]);
    printf("%d\n", ans);

    return 0;
}
