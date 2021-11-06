#include <cstdio>
#include <queue>

using namespace std;

// 각 백돌의 좌표 (y, x)를 pair로 저장해 큐에 push
typedef pair<int, int> coord;
typedef queue<coord> que;

#define MAX_N 1000

// dir 방향으로 다음 칸의 방향을 매크로를 이용해 계산
#define dY add[dir][0]
#define dX add[dir][1]
// NOW, PREV, POST: 각각 dir 방향으로 현재 좌표, 이전 좌표, 다음 좌표의 연속값
#define NOW score[dir][y][x]
#define PREV score[dir][y - dY][x - dX]
#define POST score[dir][y + dY][x + dX]

//0: 세로
//1: 가로
//2: 기울기 1 대각
//3: 기울기 -1 대각

// board: 냥목 게임판
// score[dir][y][x]: 게임판에서 좌표 (y, x)를 포함한 dir 방향의 연속된 흑돌의 길이
int N, board[MAX_N][MAX_N], score[4][MAX_N][MAX_N];
int add[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

// a와 b 중 더 큰 값을 a에 저장
void set_max(int& a, int b) { a = a > b ? a : b; }

// 좌표 (y, x)가 바둑판 위에 존재한다면 true, 아니라면 false
bool is_valid(int y, int x) { return y >= 0 && y < N&& x >= 0 && x < N; }

// 좌표 (y, x)를 포함하는 dir 방향의 연속된 흑돌의 길이를 반환
int set_score(int dir, int y, int x) {
    // 아직 흑돌의 길이를 계산하지 못했다면
    if (!NOW) {
        // 이전 좌표가 존재하는 좌표값이라면 현재 연속값을 아래와 같이 설정한다
        // 현재 좌표에 흑돌이 있다면 이전까지의 연속값 + 1,
        //                   없다면 0
        if (is_valid(y - dY, x - dX)) 
            NOW = board[y][x] == 1 ? PREV + 1 : 0;
        // 만일 연속값이 0이 아니고 다음 좌표가 존재한다면
        // 다음 값을 재귀적으로 계산한 뒤 현재값과 비교해
        // 더 큰 값을 현재 연속값으로 갱신
        if (NOW && is_valid(y + dY, x + dX))
            set_max(NOW, set_score(dir, y + dY, x + dX));
    }
    // 계산된 흑돌의 길이를 반환
    return NOW;
}

int main() {
    int y, x, ans = 0;
    que q;

    // 게임판의 상태를 입력받으면서 백돌의 좌표를 q에 push
    scanf("%d", &N);
    for (y = 0; y < N; y++) for (x = 0; x < N; x++) {
        scanf("%d", &(board[y][x]));
        if (board[y][x] == 2) q.push({ y, x });
    }

    // 게임판의 좌우 및 위쪽 모서리의 초기 연속값틀 해당 좌표의 흑돌이 있는지로 설정
    for (int i = 0; i < N; i++) {
        score[1][i][0] = score[2][i][0] = (board[i][0] == 1);
        score[0][0][i] = score[2][0][i] = score[3][0][i] = (board[0][i] == 1);
        score[3][i][N - 1] = (board[i][N - 1] == 1);
    }

    for (int i = 0; i < N; i++) {
        // 가로 및 세로 연속값을 계산한 뒤 최댓값을 갱신
        for (int j = 1; j < N; j++) {
            set_max(ans, set_score(0, j, i));
            set_max(ans, set_score(1, i, j));
        }

        // 기울기가 1인 흑돌의 연속값을 계산한 뒤 최댓값을 갱신
        for (int j = 1; i + j < N; j++) {
            set_max(ans, set_score(2, i + j, j));
            set_max(ans, set_score(2, j, i + j));
        }

        // 기울기가 -1인 흑돌의 연속값을 계산한 뒤 최댓값을 갱신
        for (int j = 1; j <= N - 1 - i; j++) {
            set_max(ans, set_score(3, j, N - 1 - i - j));
            set_max(ans, set_score(3, i + j, N - 1 - j));
        }
    }

    // 모든 백돌에 대해
    while (!q.empty()) {
        // 백돌의 좌표를 q에서 가져온 뒤
        coord c = q.front();
        q.pop();

        // 매크로를 위해 변수 y, x에 저장
        y = c.first; x = c.second;
        // 각 방향에 대해
        for (int dir = 0; dir < 4; dir++) {
            // 백돌을 흑돌로 바꾸었으므로 연속값의 최솟값은 반드시 1
            int chk = 1;
            // 이전 좌표값과 다음 좌표값이 존재한다면 해당 연속값을 더한다
            if (is_valid(y - dY, x - dX)) chk += PREV;
            if (is_valid(y + dY, x + dX)) chk += POST;
            // 최댓값 갱신
            set_max(ans, chk);
        }
    }

    // 가장 큰 연속된 흑돌의 길이를 출력
    printf("%d\n", ans);

    return 0;
}