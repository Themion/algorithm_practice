#include <cstdio>

#define INF 0x3f3f3f3f

// graph[i][j]: i에서 j까지 이동하는 최단거리
int graph[100][100];

// a를 a와 b 중 더 작은 값으로 설정
void set_min(int &a, int b) { a = a < b ? a : b; }

int main()
{
    int n, m, a, b, c;
    scanf("%d\n%d", &n, &m);

    // graph 초기화
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        graph[i][j] = INF * (i != j);

    // 그래프의 에지 값을 각각 입력받아 최솟값으로 설정
    while (m--)
    {
        scanf("%d %d %d", &a, &b, &c);
        set_min(graph[a - 1][b - 1], c);
    }

    // 플로이드-와셜
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                set_min(graph[i][j], graph[i][k] + graph[k][j]);

    // 그래프 출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
            printf("%d ", graph[i][j] < INF ? graph[i][j] : 0);
        printf("\n");
    }

    return 0;
}