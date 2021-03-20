#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> coord;

#define _y first
#define _x second

// 그림이 그려진 도화지
bool map[500][500];
// N, M: 도화지의 크기, ans: 도화지 안의 그림의 최대 크기
int N, M, ans = 0;

void set_max(int& a, int b) { a = a > b ? a : b; }
// 좌표 + 좌표
coord operator+(coord a, int add[2])
{ return {a._y + add[0], a._x + add[1]}; }

// 주어진 좌표가 도화지 안의 좌표라면 true, 아니라면 false
bool valid(coord c)
{ return c._y >= 0 && c._y < N && c._x >= 0 && c._x < M; }

// 주어진 좌표를 포함하는 그림을 탐색
bool bfs(int y, int x)
{
    // 한 좌표와 인접한 좌표를 구할 때 사용
    int add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // 그림의 크기
    int size = 0;
    // bfs에 사용할 큐
    queue<coord> q;
    // 가장 먼저 탐색한 좌표를 큐에 넣고 도화지에서 삭제
    q.push({y, x});
    map[y][x] = false;

    while (!q.empty())
    {
        // 큐 안의 모든 좌표에 대해
        coord c = q.front();
        q.pop();
        
        // 좌표 수만큼 size에 1씩 더한다
        size += 1;

        for (int i = 0; i < 4; i++)
        {
            // 각 좌표와 인접한 좌표에 대해
            coord c_ = c + add[i];
            // 좌표가 도화지 안의 좌표이고 아직 탐색하지 않은 그림이라면
            if (valid(c_) && map[c_._y][c_._x]) 
            {
                // 좌표를 큐에 넣고 그림에서 삭제
                q.push(c_);
                map[c_._y][c_._x] = false;
            }
        }
    }

    // 그림의 최대 사이즈를 갱신
    set_max(ans, size);
    // 연산의 압축을 위해 true를 반환
    return true;
}

int main()
{
    int cnt = 0;
    
    // 도화지의 상태를 입력받는다
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        scanf("%d", &map[i][j]);

    // 도화지의 각 좌표에 대해
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) 
        // 그림 안의 좌표라면 그림을 탐색한 뒤 그림의 수를 1 늘린다
        if (map[i][j]) cnt += bfs(i, j);

    // 그림의 수와 그림의 최대 크기를 출력
    printf("%d\n%d\n", cnt, ans);

    return 0;
}