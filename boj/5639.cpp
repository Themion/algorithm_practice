#include <algorithm>
#include <cstdio>

// 트리를 전위 순회한 결과를 저장한 배열
int tree[10000];

using namespace std;

// 트리의 인덱스 범위 [s, e)에서 전위 순회를 후위 순회로 전환
void f2b(int s, int e) {
    // 트리가 존재하지 않아 범위에 오류가 발생할 경우 return
    if (s >= e) return;
    // 범위가 1인 경우 루트 노드만 존재하므로 루트 노드를 출력한 뒤 종료
    if (e - s == 1) {
        printf("%d\n", tree[s]);
        return;
    }

    // 현재 노드의 왼쪽 서브트리가 끝나는 인덱스
    // 범위 (s, e)에서 lower_bound를 실행할 경우
    // 두 서브 트리를 나누는 지점을 정확히 찾을 수 있다
    int m = lower_bound(tree + s + 1, tree + e, tree[s]) - tree;

    // 후위 순회 실행
    f2b(s + 1, m);
    f2b(m, e);
    printf("%d\n", tree[s]);
}

int main() {
    // 전체 트리의 길이
    int len = 0;
    // 트리를 입력받는다
    for (; scanf("%d", tree + len) != EOF && tree[len]; len++);
    // 전위 순회의 결과를 후위 순회로 전환
    f2b(0, len);

    return 0;
}
