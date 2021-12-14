#include <cstdio>

// tree[i][j]: i의 (j==0:왼쪽, j==1:오른쪽) 자식
char tree[26][2];

// 재귀적 전위 순회
void front(int parent) {
    // 현재 노드를 출력
    printf("%c", parent + 'A');
    // 현재 노드의 좌우 자식 노드가 존재한다면 전위 순회를 실행
    if (tree[parent][0] != '.') front(tree[parent][0] - 'A');
    if (tree[parent][1] != '.') front(tree[parent][1] - 'A');
}

// 재귀적 중위 순회
void mid(int parent) {
    // 현재 노드의 왼쪽 자식 노드가 존재한다면 중위 순회를 실행
    if (tree[parent][0] != '.') mid(tree[parent][0] - 'A');
    // 현재 노드를 출력
    printf("%c", parent + 'A');
    // 현재 노드의 오른쪽 자식 노드가 존재한다면 전위 순회를 실행
    if (tree[parent][1] != '.') mid(tree[parent][1] - 'A');
}

// 재귀적 후위 순회
void back(int parent) {
    // 현재 노드의 좌우 자식 노드가 존재한다면 후위 순회를 실행
    if (tree[parent][0] != '.') back(tree[parent][0] - 'A');
    if (tree[parent][1] != '.') back(tree[parent][1] - 'A');
    // 현재 노드를 출력
    printf("%c", parent + 'A');
}

int main() {
    // 입력받을 노드의 개수
    int node;
    // 문자를 입력받을 버퍼
    char buf;

    // 문제의 조건을 입력받는다
    scanf("%d\n", &node);
    // 트리를 저장할 때 부모 노드를 인덱스로, 두 자식 노드를 값으로 저장
    for (int i = 0; i < node; i++) {
        scanf("%c", &buf);
        scanf(" %c %c%*c", tree[buf - 'A'], tree[buf - 'A'] + 1);
    }

    // 각 순회 결과를 출력
    front(0);
    printf("\n");
    mid(0);
    printf("\n");
    back(0);
    printf("\n");

    return 0;
}
