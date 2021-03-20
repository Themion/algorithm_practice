#include <cstdio>
#include <queue>
#include <vector>

#define MAX_N 1001
#define _cost first
#define _node second

using namespace std;

// <int, int> 형의 pair를 <cost: int, node: int> 형의 클래스 edge로 간주
typedef pair<int, int> edge;
// edge를 우선순위 큐에 넣어 차례로 접근한다
typedef priority_queue<edge, vector<edge>, greater<edge>> edge_q;

int N, M, X;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

// 다익스트라 알고리즘을 통해 최단 거리를 계산한다
void dijkstra(vector<edge> graph[], vector<int> &cost)
{
    // 접근 가능한 에지를 상시 정렬하기 위한 우선순위 큐
    edge_q pq;

    // 루트 노드에서 접근 가능한 에지를 모두 넣는다
    for (auto e: graph[X]) pq.push(e);
    // 접근한 에지를 제거
    graph[X].clear();

    // 접근 가능한 에지가 존재할 때
    while (!pq.empty())
    {
        // 비용이 가장 적은 에지를 우선순위 큐에서 제거
        edge e = pq.top();
        pq.pop();

        // 기존의 최소 거리와 최소 비용 에지를 경유한 거리 중
        // 가장 작은 거리를 사용
        cost[e._node] = min(cost[e._node], e._cost);
        // 접근한 노드에서 아직 큐에 넣지 않은 에지를 모두 큐에 push
        for (auto ed: graph[e._node])
            pq.push({ed._cost + e._cost, ed._node});
        // 접근한 노드에서 큐에 넣은 에지를 모두 제거
        graph[e._node].clear();
    }
}

int main()
{
    // start, dest, cost: 에지를 입력받을 때 사용
    // ret: 다익스트라로 계산한 거리 합의 최솟값을 저장
    int start, dest, cost, ret = 0;
    // start_v[i]: 노드 i에서 시작하는 에지의 집합
    // dest_v[i]: 노드 i에서 끝나는 에지의 집합
    vector<edge> start_v[MAX_N], dest_v[MAX_N];
    // start_v[i]: 노드 i에서 노드 X로 가는 경로의 최소 비용
    // dest_v[i]: 노드 X에서 노드 i로 가는 경로의 최소 비용
    vector<int> start_cost, dest_cost;

    scanf("%d %d %d", &N, &M, &X);

    // 최초 비용을 매우 큰 값인 0x3f3f3f3f로 초기화
    start_cost = vector<int>(N + 1, 0x3f3f3f3f);
    dest_cost  = vector<int>(N + 1, 0x3f3f3f3f);
    // X에서 X까지의 비용은 항상 0
    start_cost[X] = 0;
    dest_cost[X] = 0;

    // 각 에지를 입력받아 저장
    while (M--)
    {
        scanf("%d %d %d", &start, &dest, &cost);
        start_v[start].push_back({cost, dest});
        dest_v[dest].push_back({cost, start});
    }

    // 다익스트라를 이용해 노드 X부터와 최단 경로와 노드 X로의 최소 비용을 계산
    dijkstra(start_v, start_cost);
    dijkstra(dest_v, dest_cost);
    
    // 왕복 비용의 합의 최대를 계산하여 출력
    for (int i = 1; i <= N; i++) 
        ret = max(ret, start_cost[i] + dest_cost[i]);
    printf("%d\n", ret);

    return 0;
}