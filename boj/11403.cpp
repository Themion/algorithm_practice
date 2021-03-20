#include <cstdio>

bool graph[100][100] = {{false, }};

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            scanf("%d", &graph[i][j]);

    // 플로이드-와셜을 통해 모든 경로 탐색
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] |= graph[i][k] && graph[k][j];

    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    return 0;
}