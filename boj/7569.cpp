#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100
#define FOR(i, a, b) for(i = a; i < b; i++)

// 토마토가 담긴 칸의 좌표
class coord {
public:
    int h, n, m;
    coord() { h = n = m = 0; }
    coord(int h, int n, int m) { this->h = h; this->n = n; this->m = m; }

    // 좌표 간의 덧셈
    coord operator+(coord c) {
        return { this->h + c.h, this->n + c.n, this->m + c.m };
    }
};

// M, N, H: 상자의 크기, cnt: 설익은 토마토의 수
int M, N, H, cnt = 0;
// box[h][n][m]: 상자의 각 칸에 든 물건의 종류.
// 0 -> 설익은 토마토, 1 -> 익은 토마토, -1 -> 빈칸
short box[MAX_N][MAX_N][MAX_N];
// q 안의 좌표를 더할 때 사용할 변위
coord add[6]= {{0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}, {-1, 0, 0}, {1, 0, 0}};
// bfs에 사용할 큐
queue<coord> q;

// c가 상자 안의 좌표인지 여부를 반환
bool valid(coord c) {
    return c.h >= 0 && c.h < H && c.n >= 0 && c.n < N && c.m >= 0 && c.m < M;
}

int bfs() {
    // len: time 시간에 다 익은 토마토의 수, time: 토마토가 전부 익는데 걸리는 시간
    int len = q.size(), time = 0;
    // c: queue의 front, c_: c에 인접한 좌표
    coord c, c_;

    // 인접 칸에 영향을 미칠 수 있는 토마토가 존재한다면
    while(!q.empty()) {
        // q에서 좌표를 하나 가져온 뒤
        c = q.front();
        q.pop();
        // 인접 칸의 토마토를 익힐 수 있다면 익힌 칸을 q에 push
        for (auto a : add) {
            // c에 인접한 칸 c_에 대해
            c_ = c + a;
            // c_가 상자 밖의 좌표거나 안에 든 게 설익은 토마토가 아닐 경우 continue
            if (!valid(c_) || box[c_.h][c_.n][c_.m]) continue;

            // 설익은 토마토를 익은 토마토로 바꾸고 설익은 토마토의 수를 1 줄인다
            cnt -= (box[c_.h][c_.n][c_.m] = 1);
            // 다 익은 토마토의 좌표를 q에 push
            q.push(c_);
        }
        
        // time 시간에 다 익은 토마토를 모두 탐색했다면 time과 len을 갱신
        if (!--len) time += (bool)(len = q.size());
    }

    // 토마토가 다 익었다면 다 익는데 걸리는 시간을, 아니라면 -1을 반환    
    return !cnt ? time : -1;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // for문에서 사용할 변수
    int h, n, m;

    // 상자의 크기와 각 칸의 상태를 입력받은 뒤
    cin >> M >> N >> H;
    FOR(h, 0, H) FOR(n, 0, N) FOR(m, 0, M) {
        cin >> box[h][n][m];
        // 익은 토마토가 있는 칸을 q에 push
        if (box[h][n][m] == 1) q.push({h, n, m});
        // 설익은 토마토의 수를 저장
        cnt += !box[h][n][m];
    }

    // 입력받은 그래프를 탐색한 결과를 출력
    cout << bfs() << '\n';

    return 0;
}
