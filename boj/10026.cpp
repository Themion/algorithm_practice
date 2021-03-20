#include <cstdio>
#include <queue>

int N;
char image[100][100];

// image[y][x]가 from이라면 to로 바꾸고, 이를 배열의 인접한 항목에도 반복
bool dfs(int y, int x, char from, char to)
{
    image[y][x] = to;

    int add[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} }, yy, xx;
    for (auto a : add)
    {
        yy = y + a[0]; xx = x + a[1];
        if (yy < 0 || yy >= N || xx < 0 || xx >= N) continue;
        if (image[yy][xx] == from) dfs(yy, xx, from, to);
    }

    return true;
}

int main()
{
    int ret[2] = { 0, 0 };
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("\n");
        for (int j = 0; j < N; j++) scanf("%c", &(image[i][j]));
    }

    // 구역을 계산하며 RGB 이미지를 적녹 색약에 맞게 a, b로 바꿔준다 
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        if      (image[i][j] == 'R' || image[i][j] == 'G')
            ret[0] += dfs(i, j, image[i][j], 'a');
        else if (image[i][j] == 'B')
            ret[0] += dfs(i, j, image[i][j], 'b');
    }
    // 구역을 계산한다. 색약이 구분한 구역은 표시를 위해 \0로 대체
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        if (image[i][j] == 'a' || image[i][j] == 'b')
            ret[1] += dfs(i, j, image[i][j], '\0');
    }

    printf("%d %d\n", ret[0], ret[1]);

    return 0;
}