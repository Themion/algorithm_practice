#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

#define MAX 10000
#define _node first
#define _dist second

// visit[i]: 노드 i를 방문했다면 true
bool visit[MAX + 1];
// 트리의 최대 지름
int ans = 0;
// tree[i]: 노드 i와 연결된 에지(들)
vector<edge> tree[MAX + 1];

void swap(int &a, int &b) { int temp = a; a = b; b = temp; }
void set_max(int &a, int b) { a = a > b ? a : b; }

int dfs(int node) {
    // node의 자식 노드를 루트로 삼는 서브 트리의 반지름 중 가장 긴 두 반지름
    int dist[2] = { 0, 0 };

    // node를 방문했음을 표시
    visit[node] = true;

    // node의 자식 노드에 대해
    for (edge e : tree[node]) if (!visit[e._node]) {
        // 각 서브 트리의 가장 긴 반지름을 
        // 현재 트리의 두 번째로 긴 반지름과 비교하여 갱신
        set_max(dist[1], dfs(e._node) + e._dist);
        // 가장 긴 두 반지름을 비교하여 정렬
        if (dist[0] < dist[1]) swap(dist[0], dist[1]);
    }

    // 트리의 지름을 두 반지름의 합과 비교하여 갱신
    set_max(ans, dist[0] + dist[1]);
    // 가장 긴 반지름을 반환
    return dist[0];
}

int main() {
    int n, a, b, c;

    // 트리를 입력받은 뒤
    scanf("%d", &n);
    while (n-- > 1) {
        scanf("%d %d %d", &a, &b, &c);
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    // 루트 노드에서부터 차례로 서브 트리를 탐색하며 지름을 찾는다
    dfs(1);

    // 트리의 지름을 출력
    printf("%d\n", ans);

    return 0;
}
