#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 노드의 개수, a, b: 각 에지를 이루는 두 노드, parent[i]: 노드 i의 부모 노드
    // q: 큐, len: 큐의 길이
    int N, a, b, parent[MAX_N + 1] = { 0, }, q[MAX_N] = { 1, }, len = 1;
    // v[i]: 노드 i에 연결된 노드의 집합
    vector<int> v[MAX_N + 1];

    // 각 에지에 대해
    for (cin >> N; --N; ) {
        // 에지에 연결된 두 노드를 입력받아 v에 각각 저장
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // bfs: i번째로 발견된 노드 q[i]에 연결된 노드 j의 부모가 발견되지 않았다면
    for (int i = 0; i < len; i++) for (auto j : v[q[i]]) if (!parent[j]) {
        // j의 부모를 q[i]로 설정한 뒤 j를 q에 push
        parent[j] = q[i];
        q[len++] = j;
    }

    // 2번 노드부터 차례로 노드의 부모를 출력
    for (int i = 2; parent[i]; i++) cout << parent[i] << '\n';

    return 0;
}
