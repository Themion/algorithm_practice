#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> coord;

#define y first
#define x second

int N, M, map[100][100];
// 좌표의 상하좌우를 구할 때 이용할 값
int add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// 치즈가 놓인 칸을 저장할 큐
queue<coord> q;

// 좌표와 add를 더할 때 사용할 operator
coord operator+(coord c, int a[2]) { return {c.y + a[0], c.x + a[1]}; }
bool valid(coord c) { return c.y >= 0 && c.y < N && c.x >= 0 && c.x < M; }

// 좌표 c와 그 상하좌우의 빈 공간을 외부공기로 바꾼다
void melt(coord c)
{
    // 좌표 c의 값을 외부 공기로 바꾼 뒤
    map[c.y][c.x] = 2;

    // c의 상하좌우 칸에 대해 빈 칸인 경우 melt
    for (int i = 0; i < 4; i++) 
    {
        coord c_ = c + add[i];
        if (valid(c_) && map[c_.y][c_.x] == 0) melt(c_);
    }
}

// 이번 시간에 녹일 치즈를 모두 녹이는 함수
bool tick()
{
    // 함수 실행 시 q의 길이
    int size = q.size();
    // q에서 녹일 치즈의 좌표값을 따로 저장
    queue<coord> q_;

    // q의 모든 원소에 대해
    for (int it = 0; it < size; it++)
    {
        // q의 front를 따로 저장해 사용
        coord c = q.front();
        q.pop();

        // 좌표 c와 인접한 외부 공기 칸의 수
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            // c의 상하좌우 좌표 c_에 대해
            coord c_ = c + add[i];
            // c_가 가능한 좌표이고 그 값이 2라면 외부 공기 수를 1 증가
            if (valid(c_) && map[c_.y][c_.x] == 2) cnt++;
        }

        // c의 외부 공기의 수가 2 미만이라면 q에, 2 이상이라면 q_에 push
        (cnt < 2 ? q : q_).push(c);
    }

    // q_의 모든 원소에 대해 melt를 시행
    while (!q_.empty())
    {
        melt(q_.front());
        q_.pop();
    }

    // 한 시간이 지났으므로 true를 반환
    return true;
}

int main()
{
    // 치즈가 전부 녹을 때까지 걸리는 시간
    int ans = 0;

    // 치즈가 놓인 모눈종이의 상태를 입력받는다
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) 
    {
        scanf("%d", &(map[i][j]));
        if (map[i][j]) q.push({i, j});
    }
    // 빈 공기 중 외부공기를 모두 표시
    melt({0, 0});

    // 치즈가 모두 녹을 때까지 ans에 1씩 더한다
    while (!q.empty()) ans += tick();

    // 치즈가 전부 녹을 때까지 걸리는 시간을 출력
    printf("%d\n", ans);

    return 0;
}