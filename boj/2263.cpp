#include <iostream>

using namespace std;

#define MAX_N 100000

// in: 중위 순회 트리, post: 후위 순회 트리
// idx_of_in[i]: 중위 순회에서 노드 i의 인덱스
int in[MAX_N], post[MAX_N], idx_of_in[MAX_N + 1];

// 중위 순회의 범위 [i_s, i_e), 후위 순회의 범위 [p_s, p_e)를 인자로 받아
// 부분 트리의 루트 노드를 출력하고 두 자식 트리에 대해 재귀
void search(int i_s, int i_e, int p_s, int p_e) {
    // root: 후위 순회의 마지막 노드, 즉 루트 노드
    // len: 현재 트리의 길이
    int root = post[--p_e], len;

    // 루트 노드를 출력
    cout << root << ' ';

    // 중위 순회에서 왼쪽 서브 트리는 현재 트리의 시작부터 루트 노드 바로 직전까지
    // 만일 이 트리의 길이가 1 이상이라면 왼쪽 서브 트리를 탐색
    if (len = idx_of_in[root] - i_s) search(i_s, i_s + len, p_s, p_s + len);
    // 중위 순회에서 오른쪽 서브 트리는 루트 노드 바로 직후부터 현재 트리의 끝까지
    // 만일 이 트리의 길이가 1 이상이라면 오른쪽 서브 트리를 탐색
    if (len = i_e - (idx_of_in[root] + 1)) search(i_e - len, i_e, p_e - len, p_e);
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    // 중위 순회와 후위 순회를 입력받은 뒤
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    // 중위 순회에서 각 노드의 인덱스를 탐색
    for (int i = 0; i < n; i++) idx_of_in[in[i]] = i;

    // 전체 트리에서 전위 순회를 탐색
    search(0, n, 0, n);
    cout << '\n';

    return 0;
}
