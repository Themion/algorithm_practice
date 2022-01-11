#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> coord;

#define MAX_N 8
#define _y first
#define _x second

// N, M: 연구실의 실제 크기, map: 연구실의 배치도
int N, M, map[MAX_N][MAX_N];
// 바이러스의 위치의 집합
queue<coord> virus;

int max(int a, int b) { return a > b ? a : b; }

// 좌표값을 입력받아 그 좌표의 다음 좌표를 반환
coord next(coord c) {
    c._x = (c._x + 1) % M;
    c._y += c._x == 0;

    return c;
}

// 좌표를 인자로 받아 그 좌표가 연구실 안의 좌표인지를 반환
bool valid(coord c)
{ return c._y >= 0 && c._x >= 0 && c._y < N && c._x < M; }

// 벽을 세운 뒤 바이러스로부터 안전한 공간을 계산
int fill_virus() {
    // m: map을 보존하기 위해 별도의 공간에 복사하여 계산
    // ret: 바이러스로부터 안전한 공간의 수
    int m[MAX_N][MAX_N], ret = 0;
    // BFS를 하는 과정에서 바이러스의 원래 위치를 잃어버릴 수 있으므로
    // 별도의 공간에 복사하여 계산
    queue<coord> q = virus;

    // map을 m에 복사하면서 빈 공간의 수를 계산
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        m[i][j] = map[i][j];
        if (!map[i][j]) ret++;
    }

    // BFS를 통해 연구실을 바이러스로 채운다
    while (!q.empty()) {
        coord c = q.front();
        q.pop();

        // 바이러스의 상하좌우가 연구실 내부이면서 빈 공간일 때
        for (coord crd: { coord(c._y + 1, c._x), coord(c._y, c._x + 1),
                          coord(c._y - 1, c._x), coord(c._y, c._x - 1) })
            if (valid(crd) && !m[crd._y][crd._x]) {
                // 해당 좌표를 q에 넣은 뒤 공간을 바이러스로 채운다
                q.push(crd);
                m[crd._y][crd._x] = 2;
                ret--;
            }
    }

    // 남은 빈 공간의 수를 반환
    return ret;
}

// 벽을 cnt개 세울 수 있을 때 좌표 c부터 차례로 벽을 세운다
int make_wall(coord c, int cnt) {
    // 벽을 모두 세웠다면 공간을 바이러스로 채워 안전한 칸의 수를 계산
    if (!cnt) return fill_virus();
    
    // 안전한 칸의 수를 계산해 저장할 변수
    int ret = 0;

    // 벽을 세울 좌표가 연구소 안의 좌표일 때
    while (valid(c)) {
        // 해당 좌표가 빈 공간이라면 벽을 세운 뒤 다음 단계를 계산하고 벽을 철거
        if (!map[c._y][c._x]) {
            map[c._y][c._x] = 1;
            ret = max(ret, make_wall(next(c), cnt - 1));
            map[c._y][c._x] = 0;
        }

        // 다음 좌표에서 벽을 세운다
        c = next(c);
    }

    // 안전한 칸 수의 최댓값을 반환
    return ret;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 문제의 조건을 입력받으면서 바이러스의 좌표는 따로 저장
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> map[i][j];
        if (map[i][j] == 2) virus.push({ i, j });
    }

    // 안전 영역의 최대 크기를 출력
    cout << make_wall({0, 0}, 3) << '\n';

    return 0;
}
