#include <cstdio>

//tree[i][j]: i의 (j==0:왼쪽, j==1:오른쪽) 자식
char tree[26][2];

//재귀적 전위 순회
void front(int parent)
{
    //현재 노드를 출력
    printf("%c", parent + 'A');
    //현재 노드의 좌우 자식 노드에 대해 만일 존재한다면 전위 순회를 실행
    if (tree[parent][0] != '.') front(tree[parent][0] - 'A');
    if (tree[parent][1] != '.') front(tree[parent][1] - 'A');

    //만일 현재 노드가 루트 노드였다면 순회를 마쳤으므로 '\n'을 출력해 열을 바꿔준다
    if (parent == 0) printf("\n");
}

//재귀적 중위 순회
void mid(int parent)
{
    //현재 노드의 왼쪽 자식 노드에 대해 만일 존재한다면 중위 순회를 실행
    if (tree[parent][0] != '.') mid(tree[parent][0] - 'A');
    //현재 노드를 출력
    printf("%c", parent + 'A');
    //현재 노드의 오른쪽 자식 노드에 대해 만일 존재한다면 전위 순회를 실행
    if (tree[parent][1] != '.') mid(tree[parent][1] - 'A');

    //만일 현재 노드가 루트 노드였다면 순회를 마쳤으므로 '\n'을 출력해 열을 바꿔준다
    if (parent == 0) printf("\n");
}

//재귀적 후위 순회
void back(int parent)
{
    //현재 노드의 좌우 자식 노드에 대해 만일 존재한다면 후위 순회를 실행
    if (tree[parent][0] != '.') back(tree[parent][0] - 'A');
    if (tree[parent][1] != '.') back(tree[parent][1] - 'A');
    //현재 노드를 출력
    printf("%c", parent + 'A');

    //만일 현재 노드가 루트 노드였다면 순회를 마쳤으므로 '\n'을 출력해 열을 바꿔준다
    if (parent == 0) printf("\n");
}

int main()
{
    //입력받을 노드의 개수
    int node;
    //문자를 입력받을 버퍼
    char buf;

    //노드의 개수를 입력받는다
    scanf("%d\n", &node);
    //각 노드마다
    for (int i = 0; i < node; i++)
    {
        //무슨 노드인지 입력받는다
        scanf("%c", &buf);
        //왼쪽 자식 노드를 입력받는다
        scanf(" %c", &tree[buf - 'A'][0]);
        //오른쪽 자식 노드를 입력받고 따라오는 '\n'은 무시한다
        scanf(" %c%*c", &tree[buf - 'A'][1]);
    }

    front(0);
    mid(0);
    back(0);
}