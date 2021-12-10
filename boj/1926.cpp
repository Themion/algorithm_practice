#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> coord;

#define _y first
#define _x second

#define MAX_N 500

// 그림이 그려진 도화지
bool map[MAX_N][MAX_N];
// N, M: 도화지의 크기, ans: 도화지 안의 그림의 최대 크기
int N, M, ans = 0;

void set_max(int &a, int b) { a = a > b ? a : b; }
// 좌표 + 좌표
coord operator+(coord a, int add[2]) {
    return {a._y + add[0], a._x + add[1]};
}

// 주어진 좌표가 도화지 안의 좌표라면 true, 아니라면 false
bool valid(coord c) {
    return c._y >= 0 && c._y < N && c._x >= 0 && c._x < M;
}

// 주어진 좌표를 포함하는 그림을 탐색
bool bfs(int y, int x) {
    // 한 좌표와 인접한 좌표를 구할 때 사용
    int add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // 그림의 크기
    int size = 0;
    // bfs에 사용할 큐
    queue<coord> q;
    // 가장 먼저 탐색한 좌표를 큐에 넣고 도화지에서 삭제
    q.push({y, x});
    map[y][x] = false;

    while (!q.empty()) {
        // 큐 안의 모든 좌표에 대해
        coord c = q.front();
        q.pop();

        // 좌표 수만큼 size에 1씩 더한다
        size += 1;

        for (int i = 0; i < 4; i++) {
            // 각 좌표와 인접한 좌표에 대해
            coord c_ = c + add[i];
            // 좌표가 도화지 안의 좌표이고 아직 탐색하지 않은 그림이라면
            if (valid(c_) && map[c_._y][c_._x]) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt = 0;

    // 문제의 조건을 입력받는다
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        cin >> map[i][j];

    // 각 좌표에 대해 그래프가 존재한다면 bfs를 이용한 탐색
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) 
        if (map[i][j]) cnt += bfs(i, j);

    // 그림의 수와 그림의 최대 크기를 출력
    cout << cnt << '\n' << ans << '\n';

    return 0;
}
