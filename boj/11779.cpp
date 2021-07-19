#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

#define _cost first
#define _node second

#define MAX_N 1001
#define INF 0x3f3f3f3f

int n, m;
vector<edge> graph[MAX_N];

//  a + b := a.push_back(b)
vector<int> operator+(vector<int> a, int b)
{
    a.push_back(b);
    return a;
}

void dijkstra(int start, int dest)
{
    // cost[i]: start에서 i까지 이동할 때의 최소 비용
    vector<int> costs(n + 1, INF);
    // routes[i]: start에서 i까지의 최소 비용 경로
    vector<vector<int>> routes(n + 1, vector<int>(0));
    // 다익스트라 탐색에 사용할 우선순위 큐
    priority_queue<edge, vector<edge>, greater<edge>> q;

    // 시작점으로 이동하는 최소 비용은 항상 0
    costs[start] = 0;
    // 시작점으로 이동하는 최소 비용 경로는 정해져 있다
    routes[start].push_back(start);

    // 시작점으로 이동하는 가상의 에지를 입력
    q.push({0, start});

    // 탐색 가능한 에지가 존재할 때
    while (!q.empty())
    {
        // 비용이 가장 작은 에지 e를 q에서 제거
        edge e = q.top();
        q.pop();

        // e를 사용했을 때의 비용이 기존 비용보다 크다면 continue
        if (costs[e._node] < e._cost) continue;

        // e를 사용한 뒤 기존 경로 중 비용을 절감할 수 있는 경로가 있다면
        for (auto e_ : graph[e._node]) if (costs[e_._node] > e._cost + e_._cost)
        {
            // 경로와 비용을 갱신한 뒤
            costs[e_._node] = e._cost + e_._cost;
            routes[e_._node] = routes[e._node] + e_._node;
            // 갱신한 에지 e_를 q에 push
            q.push({e._cost + e_._cost, e_._node});
        }
    }

    // start에서 dest까지의 비용과 경로의 길이, 경로를 출력
    printf("%d\n%d\n", costs[dest], (int)(routes[dest].size()));
    for (int node : routes[dest])
        printf("%d ", node);

    printf("\n");
}

int main()
{
    int s, e, c;

    // 그래프를 입력받은 뒤
    scanf("%d\n%d", &n, &m);
    while (m--)
    {
        scanf("%d %d %d", &s, &e, &c);
        graph[s].push_back({c, e});
    }
    scanf("%d %d", &s, &e);

    // 입력받은 그래프를 이용해 dijkstra 실행
    dijkstra(s, e);

    return 0;
}