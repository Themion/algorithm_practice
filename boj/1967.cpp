#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

#define _node first
#define _cost second

int ans = 0;
bool visit[10001];
vector<edge> tree[10001];

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
    set_max(ans, max[0] + max[1]);

    // 가장 긴 경로를 반환
    return max[0];
}

int main()
{
    int n, a, b, c;

    // 트리를 입력받은 뒤
    scanf("%d", &n);
    while (n-- > 1)
    {
        scanf("%d %d %d", &a, &b, &c);
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    // 루트 노드에서부터 차례로 서브 트리를 탐색하며 지름을 찾는다
    visit[1] = true;
    dfs(1);

    // 트리의 지름을 출력
    printf("%d\n", ans);

    return 0;
}