#include <algorithm>
#include <cstdio>

int N, M, item[10], arr[10];

void backtrack(int idx, int start)
{
    // 수열의 길이가 최대치에 도달했다면 수열을 출력
    if (idx == M)
    {
        for (int i = 0; i < M; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    // 수열을 이룰 수 있는 각 수를 arr에 넣어 백트래킹
    for (int i = start; i < N; i++)
    {
        arr[idx++] = item[i];
        backtrack(idx, i);
        arr[idx--] = 0;
    }
}

int main()
{
    // 수열의 길이와 수열에 사용할 수 있는 수를 입력받아 정렬한다
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", item + i);
    std::sort(item, item + N);
    
    backtrack(0, 0);

    return 0;
}