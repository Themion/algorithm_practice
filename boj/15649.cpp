#include <cstdio>

// visit[i]: 수 i가 수열에 들어간다면 true, 아니라면 fasle
bool visit[8];
// arr[i]: 수열의 i번째 수
int N, M, arr[8];

// 수열 생성
void recursive(int cnt)
{
    // 만든 수열의 길이가 M일 때 수열을 차례로 출력
    if (cnt == M)
    {
        for (int i = 0; i < M; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    // 수열을 만들 수 있는 각 수 중 수열에 포함되지 않은 수에 대해
    for (int i = 0; i < N; i++) if (!visit[i])
    {
        // 수열에 그 수를 넣은 뒤
        visit[i] = true;
        arr[cnt] = i + 1;

        // 만들어진 수열의 부분집합을 출력하고
        recursive(cnt + 1);

        // 수열에서 수를 제거
        arr[cnt] = 0;
        visit[i] = false;
    }
}

int main()
{
    // N과 M을 입력받아 수열을 생성한다
    scanf("%d %d", &N, &M);
    recursive(0);
    
    return 0;
}