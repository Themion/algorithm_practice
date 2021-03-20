#include <cstdio>

#define MAX_N 1024

int N, M;
// [(a, b)]를 테이블에서 (1, 1)부터 (a, b)까지의 합이라고 하자
// sum[a][b]: 입력받은 테이블에서 [(a, b)]
int sum[MAX_N + 1][MAX_N + 1] = {{ 0, }};

// 합을 구할 좌표를 입력받아 합을 출력
int test()
{
    // 합을 구할 좌표를 입력받은 뒤 알고리즘을 위해 x1, y1에서 1씩 뺀다
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--;

    // (x1, y1)부터 (x2, y2)까지의 합은
    // [(x2, y2)] - [(x1, y2)] - [(x2, y1)]와 같다
    // 이 때 [(x1, y1)]이 두 번 빼지므로 이를 한 번 더해야 함
    return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

int main()
{
    // 테이블을 입력받을 때
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
    {
        scanf("%d", &sum[i][j]);
        // 테이블의 각 값을 [(i, j)]로 바꿔 계산량을 줄인다
        // [(i, j)] = (i, j) + [(i - 1, j)] + [(i, j - 1)]
        // 이 때 [(i - 1, j - 1)]이 두 번 더해지므로 이 값을 한 번 빼야 함
        sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
    }
    while (M--) printf("%d\n", test());

    return 0;
}