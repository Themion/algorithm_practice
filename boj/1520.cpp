#include <iostream>

using namespace std;

#define MAX_N 500
#define dY(i) y + add[i][0]
#define dX(i) x + add[i][1]

// visit[y][x]: 칸 (x, y)에 도달하는 경우의 수를 구한 적 있다면 true, 아니라면 false
bool visit[MAX_N][MAX_N] = {{ 1, }};
// map: 각 칸의 높이, add: 각 칸과 인접한 칸을 구할 때 사용할 변수
short map[MAX_N][MAX_N] = {{ 0, }}, add[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// N, M: 칸의 크기, ans[y][x]: 칸 (x, y)에 도달하는 경우의 수
int N, M, ans[MAX_N][MAX_N] = {{ 1, }};

bool valid(int y, int x) { return y >= 0 && y < N && x >= 0 && x < M; }

// 칸 (x, y)에 도달하는 경우의 수
int dfs(int y, int x) {
    // 만일 이전에 (x, y)를 방문한 적이 없다면
    if (!visit[y][x]) {
        // 현재 칸에 방문했음을 표시한 뒤
        visit[y][x] = 1;
        // 각 인접한 칸에 대해 해당 칸이 지도 안의 칸이고 현재 칸보다 높이가 높다면
        // 현재 칸에 도달하기 위해 해당 인접한 칸으로 이동할 수도 있다
        for (int i = 0; i < 4; i++)
            if (valid(dY(i), dX(i)) && map[y][x] < map[dY(i)][dX(i)])
                ans[y][x] += dfs(dY(i), dX(i));
    }

    // 칸 (x, y)에 도달하는 경우의 수를 반환
    return ans[y][x];
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 문제의 조건을 입력받은 뒤
    cin >> N >> M;
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) cin >> map[y][x];

    // 마지막 칸에 도달하는 경우의 수를 계산
    cout << dfs(N - 1, M - 1)<< '\n';

    return 0;
}
