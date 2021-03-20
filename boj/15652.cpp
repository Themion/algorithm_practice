#include <cstdio>

// idx: 수열의 현재 크기, arr: 수열을 저장할 배열
int N, M, idx = 0, arr[10];

void backtrack(int start)
{
    // 수열의 크기가 M이 되었을 때 수열을 출력
    if (idx == M)
    {
        for (int i = 0; i < M; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    // 시작점부터 N까지 가능한 수를 모두 수열에 넣는다
    for (int i = start; i <= N; i++)
    {
        arr[idx++] = i;
        backtrack(i);
        arr[idx--] = 0;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    backtrack(1);

    return 0;
}