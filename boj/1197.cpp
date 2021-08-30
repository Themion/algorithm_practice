#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> edge;

#define MAX_V 10000
#define MAX_E 100000
#define _C first
#define _A second.first
#define _B second.second

vector<edge> v;
int visit[MAX_V + 1] = { 0, };

// 입력받은 노드를 포함하는 트리의 루트를 재귀적으로 탐색하여 반환
int root(int node)
{
    if (visit[node] == node || !visit[node]) return node;
    return root(visit[node]);
}

int main()
{
    // V, E, A, B, C: 그래프를 입력받을 때 사용하는 버퍼
    // ans: 최소 스패닝 트리의 가중치의 총합
    int V, E, A, B, C, ans = 0;
    scanf("%d %d", &V, &E);
    while (E--)
    {
        scanf("%d %d %d", &A, &B, &C);
        v.push_back({C, {A, B}});
    }

    // kruskal 알고리즘을 사용하기 위해 입력받은 그래프를 가중치 순으로 정렬
    sort(v.begin(), v.end());

    // 에지를 가중치 순으로 탐색하며 트리에 추가
    for (edge e : v)
    {
        // 에지의 양 노드를 포함하는 부분 트리의 루트를 계산한 뒤
        int A_ = root(e._A), B_ = root(e._B);
        // 두 루트가 같다면 continue
        if (A_ == B_) continue;
        // 두 부분 트리 중 루트의 값이 더 큰 트리를 나머지 트리의 루트 밑에 붙인다
        visit[(A_ > B_ ? A_ : B_)] = (A_ < B_ ? A_ : B_);
        // 현재 에지 e가 최소 스패닝 트리에 추가되었으므로 e의 가중치를 ans에 더함
        ans += e._C;
    }

    // 최소 스패닝 트리의 가중치의 총합을 출력
    printf("%d\n", ans);

    return 0;
}