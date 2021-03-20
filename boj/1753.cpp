#include <cstdio>
#include <queue>
#include <vector>

#define INF 0x3f3f3f3f
#define MAX_V 20001
#define _cost first
#define _node second

using namespace std;

typedef pair<int, int> edge;
typedef priority_queue<edge, vector<edge>, greater<edge>> edge_q;

int V, E, K;
// 다익스트라 알고리즘으로 구한 각 노드까지의 거리
int cost[MAX_V];
// graph[i]: 노드 i와 연결된 에지를 <cost, node> 꼴로 저장
vector<edge> graph[MAX_V];

// 다익스트라 알고리즘을 통해 start 노드에서 다른 노드까지의 비용을 계산
void dijkstra()
{
    edge_q pq;

    // 각 노드까지 걸리는 시간을 MAX로 초기화
    fill_n(cost, MAX_V, INF);

    // 시작 노드의 에지를 pq에 넣은 뒤 시작 노드까지의 비용을 0으로 설정
    for (auto e: graph[K]) pq.push(e);
    cost[K] = 0;
    
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
    int u, v, w;

    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    
    while (E--)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({w, v});
    }

    dijkstra();

    // 다익스트라 결과 경로가 존재한다면 그 비용을, 없다면 INF를 출력
    for (int i = 1; i <= V; i++)
    {
        if (cost[i] != INF) printf("%d\n", cost[i]);
        else                printf("INF\n");
    }

    return 0;
}