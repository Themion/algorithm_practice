#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, pair<short, short>> edge;

#define MAX_V 10000
#define MAX_E 100000

#define _C first
#define _A second.first
#define _B second.second

short visit[MAX_V + 1] = { 0, };
edge v[MAX_E];

// 입력받은 노드를 포함하는 트리의 루트를 재귀적으로 탐색하여 반환
short root(short node) {
    if (visit[node] == node || !visit[node]) return node;
    return root(visit[node]);
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // V, E: 노드와 에지의 수
    // A, B, C: 노드 A와 B를 연결하고 가중치 C를 가지는 에지를 입력받을 변수
    // ans: 최소 스패닝 트리의 가중치
    int V, E, A, B, C, ans = 0;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        // 에지의 각 성분을 입력받아 파싱한 형태로 저장
        cin >> A >> B >> C;
        v[i] = {C, {(short)A, (short)B}};
    }

    // kruskal 알고리즘을 사용하기 위해 입력받은 그래프를 가중치 순으로 정렬
    sort(v, v + E);

    // 에지를 가중치 순으로 탐색하며 트리에 추가
    for (int i = 0; i < E; i++) {
        // 에지의 양 노드를 포함하는 부분 트리의 루트를 계산한 뒤
        A = root(v[i]._A), B = root(v[i]._B);
        // 두 루트가 같다면 continue
        if (A == B) continue;
        // 두 부분 트리 중 루트의 값이 더 큰 트리를 나머지 트리의 루트 밑에 붙인다
        visit[(A > B ? A : B)] = (A < B ? A : B);
        // 현재 에지 e가 최소 스패닝 트리에 추가되었으므로 e의 가중치를 ans에 더함
        ans += v[i]._C;
    }

    // 최소 스패닝 트리의 가중치의 총합을 출력
    cout << ans << '\n';

    return 0;
}
