#include <cstdio>

// N, area: 문제의 입력값
short N, area[100][100];
// area가 비에 침수된 결과
bool graph[100][100];

void set_max(int &a, int b) { a = a > b ? a : b; }
void set_max(int &a, short b) { set_max(a, (int)b); }
// 주어진 좌표가 안전한 지점인지 탐색
bool valid(int y, int x) 
{ return y >= 0 && y < N & x >= 0 && x < N && graph[y][x]; }

// 지점을 탐색한 뒤 주변 지역이 안전한 지점이라면 탐색
bool dfs(int y, int x)
{
    int add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // 현재 지점을 탐색
    graph[y][x] = false;
    
    // 상하좌우 주변 지점이 안전한 지점이라면 그 지점에서 dfs
    for (int i = 0; i < 4; i++) if (valid(y + add[i][0], x + add[i][1]))
        dfs(y + add[i][0], x + add[i][1]);

    return true;
}

// 비가 rain만큼 왔을 때 안전한 영역의 개수를 계산
int search(int rain)
{
    // 안전한 영역의 수는 기본적으로 0개
    int ret = 0;
    // 각 지점의 높이가 rain보다 높다면 그 지점은 안전한 지점이다
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        graph[i][j] = area[i][j] > rain;

    // dfs를 이용해 안전한 영역의 수를 계산
    // 연산을 줄이기 위해 dfs의 반환값은 항상 true(1)
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        if (graph[i][j]) ret += dfs(i, j);

    return ret;
}

int main()
{
    // ans: 안전한 지점의 최대 개수
    // max: 가장 높은 지점의 높이
    int ans = 1, max = 0;

    // area를 입력받으며 가장 높은 지점의 높이를 계산
    scanf("%hd", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        scanf("%hd", &(area[i][j]));
        set_max(max, area[i][j]);
    }

    // 비가 오지 않은 경우 안전한 영역의 개수는 1개
    // 비가 max 이상 올 경우 모든 지점이 침수하므로 안전한 영역의 개수는 0개
    // 비가 1부터 (max - 1)만큼 올 때의 안전한 영역의 개수를 계산
    for (int i = 1; i < max; i++) set_max(ans, search(i));

    // 안전한 영역의 최대 개수를 출력
    printf("%d\n", ans);

    return 0;
}