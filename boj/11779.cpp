#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;
typedef pair<int, vector<int>> route;

#define _cost first
#define _node second
#define _route second

#define MAX_N 1001
#define INF 0x3f3f3f3f

int n, m;
vector<edge> graph[MAX_N];

void set_min(int& a, int b) { a = a < b ? a : b; }

void dijkstra(int start, int dest)
{
    // cost[i]: start에서 i까지 이동할 때의 최소 비용
    vector<int> cost(n + 1, INF);
    // start에서 dest까지 이동하는 route
    route to_dest;
    // 다익스트라 탐색에 사용할 우선순위 큐
    priority_queue<route, vector<route>, greater<route>> q;

    // 시작점으로 이동하는 최소 비용은 항상 0
    cost[start] = 0;
    // 경로 탐색 전이므로 비용을 INF로 설정
    to_dest._cost = INF;

    // 시작점과 연결된 에지를 큐에 전부 넣는다
    for (edge e : graph[start]) q.push({e._cost, {start, e._node}});

    // 탐색 가능한 에지가 존재할 때
    while (!q.empty())
    {
        // q에서 원소 하나를 꺼낸다
        route r = q.top();
        // 현재 경로의 도착점
        int node = r._route.back();
        q.pop();

        // 현재 경로의 비용이 기존 경로보다 낮다면 이를 cost에 저장
        set_min(cost[node], r._cost);

        // 도착점에 연결된 모든 에지에 대해
        // 기존 최소값을 갱신할 수 있는 노드가 있다면
        for (edge e_ : graph[node])
            if (cost[e_._node] > r._cost + e_._cost)
            {
                // 현재 경로에 해당 노드를 추가한 경로를 q에 push
                route r_ = { r._cost + e_._cost, r._route };
                r_._route.push_back(e_._node);
                q.push(r_);
                
                // r_의 비용은 반드시 최소 비용이므로 이를 갱신
                cost[e_._node] = r_._cost;
            }

        // 현재 경로가 dest까지의 최소 경로라면 현재 경로를 to_dest에 저장
        if (node == dest && r._cost < to_dest._cost) to_dest = r;
    }

    // 최소 경로의 비용, 길이와 경로 안의 모든 노드를 출력
    printf("%d\n%d\n", to_dest._cost, (int)(to_dest._route.size()));
    for (int node: to_dest._route) printf("%d ", node);

    printf("\n");
}

int main()
{
    int s, e, c;

    // 그래프를 입력받는다
    scanf("%d\n%d", &n, &m);
    while(m--)
    {
        scanf("%d %d %d", &s, &e, &c);
        graph[s].push_back({c, e});
    }
    scanf("%d %d", &s, &e);

    // 다익스트라 실행
    dijkstra(s, e);

    return 0;
}