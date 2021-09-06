#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> edge;

#define MAX_N 100000
#define _C first
#define _A second.first
#define _B second.second

// N, M: 주어진 조건에서 노드와 에지의 수
int N, M;
// 각 노드가 속한 트리에서 노드의 부모, 혹은 루트 노드
int parent[MAX_N + 1] = { 0, };
// 에지를 저장할 공간
vector<edge> v;

// 입력받은 노드를 포함하는 트리의 루트를 재귀적으로 탐색하여 반환
int root(int node)
{
    if (parent[node] == node || !parent[node]) return node;
    return root(parent[node]);
}

int main()
{
    // cnt = 현재 에지들이 이루는 트리의 수, ans: 모든 트리의 가중치의 합
    int cnt, ans = 0;

    // 노드와 에지의 수를 입력받은 뒤
    scanf("%d %d", &N, &M);
    
    // 트리의 수를 노드의 수로 설정
    cnt = N;
    // 에지의 집합 v의 크기를 정의
    v = vector<edge>(M);

    // 각 에지를 입력받은 뒤 cost 순으로 정렬
    for (edge &e : v) scanf("%d %d %d", &e._A, &e._B, &e._C);
    sort(v.begin(), v.end());

    // cost가 작은 에지부터 순서대로
    for (edge e : v)
    {
        // 트리의 수를 2개 미만으로 줄였다면 루프를 탈출
        if (cnt <= 2) break;
        
        // 현재 에지의 두 노드를 각 노드가 속한 트리의 루트로 치환
        // 두 노드가 같은 트리에 속해 있다면 continue
        int A_ = root(e._A), B_ = root(e._B);
        if (A_ == B_) continue;

        // 서로 다른 트리를 에지로 연결했으므로 cnt를 1 줄인 뒤
        cnt--;
        // ans에 현재 에지의 가중치를 더하고
        ans += e._C;
        // 두 루트 노드 중 값이 더 작은 노드를 루트 노드로 설정
        parent[(A_ > B_ ? A_ : B_)] = (A_ < B_ ? A_ : B_);

    }

    // 가중치의 합을 출력
    printf("%d\n", ans);

    return 0;
}