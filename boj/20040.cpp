#include <iostream>

using namespace std;

#define MAX_N 500000

// parent[i]: 노드 i의 부모 노드
int parent[MAX_N + 1];

void swap(int &a, int &b) { int t = a; a = b; b = t; }

// node 노드가 속한 트리의 루트 노드를 반환
int root(int node) {
    if (!parent[node] || node == parent[node]) return node;
    return parent[node] = root(parent[node]);
}

// 노드 a와 b가 속한 두 트리를 연결
bool push_edge(int& a, int& b) {
    // 두 노드가 속한 트리의 루트 노드를 계산한 뒤
    // 두 노드 중 값이 더 작은 노드를 a에, 큰 노드를 b에 저장
    if ((a = root(a)) > (b = root(b))) swap(a, b);
    // a와 b가 같은지, 즉 두 노드 a와 b가 애초에 같은 트리에 속했는지를 반환
    return a == b;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M, a, b, ans = 0;
    // 노드의 수는 필요하지 않고 에지의 수만 입력받는다
    cin >> ans >> M;

    // 각 에지에 대해
    for (ans = 1; ans <= M; ans++) {
        // 에지를 이루는 두 노드를 입력받은 뒤
        cin >> a >> b;
        // 두 노드가 같은 트리에 속했다면 break, 아니라면 연결
        if (push_edge(++a, ++b)) break;
        else parent[b] = a;
    }

    // ans가 M보다 크다면 사이클을 완성하지 못한 것이므로 0을 출력
    printf("%d\n", ans > M ? 0 : ans);

    return 0;
}
