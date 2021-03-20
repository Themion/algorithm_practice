#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define MAX_N 1001
#define _cost first
#define _node second

typedef pair<int, int> edge;
typedef priority_queue<edge, vector<edge>, greater<edge>> edge_q;

int N, M;
// graph[start]: start에서 출발하는 노드의 집합
vector<edge> graph[MAX_N];

void set_min(int &a, int &b) { a < b ? b = a : a = b; }

// 다익스트라를 이용해 최단거리 탐색
int dijkstra(int start, int dest)
{
    // costs[i]: start에서 i까지의 최소 비용
    int costs[MAX_N];
    // 각 에지를 정렬하여 순차적으로 탐색할 때 사용할 우선순위 큐
    edge_q q;

    // 최소 비용을 전부 무한대로 설정한 뒤 시작 노드의 비용을 초기화
    fill_n(costs, N + 1, INF);
    costs[start] = 0;
    // 시작 노드와 연결된 노드를 q에 push
    for (edge e : graph[start]) q.push(e);

    // 탐색 가능한 에지가 존재할 때
    while (!q.empty())
    {
        // 비용이 가장 작은 에지를 q에서 제거
        edge e = q.top();
        q.pop();

        // 기존 비용과 에지의 비용을 비교해 더 작은 쪽으로 통일
        set_min(e._cost, costs[e._node]);

        // 에지와 연결된 노드의 모든 에지에 대해
        // 기존 최소값을 갱신할 수 있는 노드가 있다면
        for (edge e_ : graph[e._node])
            if (costs[e_._node] > e._cost + e_._cost)
            {
                // 에지의 값을 갱신될 최소값으로 바꾼 뒤 최소값을 갱신
                e_._cost += e._cost;
                costs[e_._node] = e_._cost;
                // 에지를 q에 push
                q.push(e_);
            }
    }

    // start 노드에서 dest 노드까지의 최소 비용을 반환
    return costs[dest];
}

int main()
{
    // start에서 dest까지 이동할 때 cost만큼의 비용을 소모
    int start, dest, cost;

    // 그래프를 입력받아 v에 저장
    scanf("%d\n%d", &N, &M);
    while (M--)
    {
        scanf("%d %d %d", &start, &dest, &cost);
        graph[start].push_back({cost, dest});
    }

    // 시작 노드와 끝 노드을 입력받아 최소 비용을 다익스트라로 계산
    scanf("%d %d", &start, &dest);
    printf("%d\n", dijkstra(start, dest));

    return 0;
}