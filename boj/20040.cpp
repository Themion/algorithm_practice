#include <cstdio>

#define MAX_N 500000

// M: 에지의 수
int  M;
// parent[i]: 노드 i의 부모 노드
int parent[MAX_N + 1];

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// node 노드가 속한 트리의 루트 노드를 반환
int root(int node)
{
    if (!parent[node] || node == parent[node]) return node;
    return root(parent[node]);
}

// 노드 a와 b가 속한 두 트리를 연결
bool push_edge(int a, int b)
{
    // 두 노드가 속한 트리의 루트 노드를 계산한 뒤
    a = root(a);
    b = root(b);

    // 두 노드 중 값이 더 작은 노드를 a에, 큰 노드를 b에 저장
    if (a > b) swap(a, b);

    // b의 부모를 a로 설정
    parent[b] = a;

    // a와 b가 같은지, 즉 두 노드 a와 b가 애초에 같은 트리에 속했는지를 반환
    return a == b;
}

int main()
{
    int a, b, ans = 0;
    // 노드의 수는 필요하지 않고 에지의 수만 입력받는다
    scanf("%*d %d", &M);

    // 각 에지에 대해
    for (int i = 1; i <= M; i++)
    {
        // 에지를 이루는 두 노드를 입력받은 뒤
        scanf("%d %d", &a, &b);
        // 두 노드가 같은 트리에 속했다면 break, 아니라면 연결
        if (push_edge(a + 1, b + 1)) 
        {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}