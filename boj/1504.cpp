#include <cstdio>
#include <queue>
#include <vector>

/*



성능 매우 안좋음!!!!!!!!!!!!!!!11



*/

#define MAX 0x3f3f3f3f
#define MAX_N 801
#define _cost first
#define _node second

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> edge;
typedef priority_queue<edge, vector<edge>, greater<edge>> edge_q;

// cost: 다익스트라 알고리즘으로 구한 각 노드까지의 거리
int N, cost[MAX_N] = { 0, };
// graph[i]: 노드 i와 연결된 에지를 <cost, node> 꼴로 저장
vector<edge> graph[MAX_N];

ull min(ull a, ull b) { return a < b ? a : b; }

// 다익스트라 알고리즘을 통해 start 노드에서 다른 노드까지의 비용을 계산
void dijkstra(int start)
{
    edge_q pq;

    // 각 노드까지 걸리는 시간을 MAX로 초기화
    fill_n(cost, MAX_N, MAX);

    // 시작 노드의 에지를 pq에 넣은 뒤 시작 노드까지의 비용을 0으로 설정
    for (auto e: graph[start]) pq.push(e);
    cost[start] = 0;
    
    // pq 안에서 비용이 작은 에지 순으로
    while (!pq.empty())
    {
        edge e = pq.top();
        pq.pop();

        // 그래프를 탐색하여 비용이 절감된다면 해당 노드로 그래프를 탐색
        if (cost[e._node] > e._cost)
        {
            cost[e._node] = e._cost;
            for (auto ed : graph[e._node])
                pq.push({cost[e._node] + ed._cost, ed._node});
        }
    }
}

int main()
{
    int E, a, b, c, v[2];
    // v0v1: 시작 -> v0 -> v1 -> N
    // v1v0: 시작 -> v1 -> v0 -> N
    ull v0v1, v1v0, ret;
    scanf("%d %d", &N, &E);

    while (E--)
    {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    scanf("%d %d", v, v + 1);

    // 시작 노드와 v[0], v[1]에서 다른 노드까지 걸리는 비용을 각각 계산한 뒤
    // 시작 노드에서 시작해 v[0], v[1] 노드를 모두 거쳐 노드 N까지 이동하는
    // 경로의 최소 비용을 계산
    dijkstra(1);
    v0v1 = cost[v[0]];
    v1v0 = cost[v[1]];

    dijkstra(v[0]);
    v0v1 += cost[v[1]];
    v1v0 += cost[N];

    dijkstra(v[1]);
    v0v1 += cost[N];
    v1v0 += cost[v[0]];

    // 두 값 중 더 작은 값을 고르는 연산은 시간이 오래 걸리지 않는다
    printf("%lld\n", min(v0v1, v1v0) >= MAX ? -1 : min(v0v1, v1v0));

    return 0;
}