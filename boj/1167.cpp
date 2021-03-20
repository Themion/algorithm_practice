#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

#define _node first
#define _cost second

int ret = 0;                     // ret: 계산한 트리의 지름을 저장할 공간
bool visit[100001] = { false, };    // visit[i]: 노드 i를 방문했다면 true
vector<edge> tree[100001];          // tree[i]: 노드 i와 연결된 에지(들)
                                    // 에지: pair<연결된 다른 노드, 길이>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void set_max(int &a, int b) { a = a > b ? a : b; }

int dfs(int node)
{
    // 서브 트리에서 리프 노드까지의 거리 중 가장 긴 두 거리
    // 반드시 오름차순으로 정렬
    int max[2] = { 0, 0 };

    // node와 연결된 노드 중 방문하지 않은 노드 _node에 대해
    for (edge e : tree[node]) if (!visit[e._node])
    {
        // _node를 방문함을 표시
        visit[e._node] = true;
        // _node에서 리프 노드까지의 거리 중 가장 긴 것을
        // max[1]과 비교해 더 큰 값을 저장
        set_max(max[1], dfs(e._node) + e._cost);
        // 정렬
        if (max[0] < max[1]) swap(max[0], max[1]);
    }

    // 가장 긴 두 경로의 합을 기존 트리의 지름과 비교
    set_max(ret, max[0] + max[1]);

    // 가장 긴 경로를 반환
    return max[0];
}

int main()
{
    int N, node, len, n;

    // 트리를 입력받는다
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d %d", &n, &node);
        while (node != -1)
        {
            scanf("%d", &len);
            tree[n].push_back({node, len});
            scanf("%d", &node);
        }
    }

    // 트리의 지름 계산
    dfs(1);
    // 계산한 트리의 지름을 출력한다
    printf("%d\n", ret);

    return 0;
}

/*  가장 먼 노드를 두 번 구하는 방식으로 계산
    부분 트리를 이용해 구하는 방식보다 약 20ms 정도 느림(왜?)



edge dfs(int n, int p, int dist)
{
    edge lng = edge(0, 0);

    visit[n] = true;
    vector<edge> child;

    for (auto e: tree[n]) if (e.node != p && !visit[e.node])
        child.push_back(dfs(e.node, n, dist + e.len));

    if (child.size() == 0) return edge(n, dist);

    for (auto c: child) lng = lng.len > c.len ? lng : c;

    return lng;
}
*/