#include <cstdio>

#define N_MAX 100
#define INF 0x3f3f3f3f

// item[i]: 노드 i애 위치한 아이템의 수
// graph[i][j]: 노드 i에서 노드 j까지의 거리
short item[N_MAX], graph[N_MAX][N_MAX];
// n: 그래프의 노드의 수, m: 탐색 가능한 범위
int n, m;

void set_min(short &a, short b) { a = a < b ? a : b; }
void set_max(int& a, int b) { a = a > b ? a : b; }

int main()
{
    int r, ans = 0;

    scanf("%d %d %d", &n, &m, &r);
    // 노드 안의 아이템의 개수를 입력받으며 graph 초기화
    for (int i = 0; i < n; i++)
    {
        scanf("%dh", item + i);
        for (int j = 0; j < n; j++) graph[i][j] = INF * (i != j);
    }

    // grahp를 입력받는다
    while (r--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }

    // 플로이드-와셜로 노드 간의 최소 거리 탐색
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                set_min(graph[i][j], graph[i][k] + graph[k][j]);

    // 각 노드 i에 대해
    for (int i = 0; i < n; i++)
    {
        // 노드 i에 착륙했을 때 획득 가능한 아이템의 수
        int sum = 0;
        // graph를 탐색하며 아이템을 습득
        for (int j = 0; j < n; j++) if (graph[i][j] <= m) sum += item[j];
        // 습득한 아이템의 수가 기존 아이템의 수보다 크다면 ans를 갱신
        set_max(ans, sum);
    }

    printf("%d\n", ans);

    return 0;
}