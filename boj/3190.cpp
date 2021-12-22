#include <cstdio>
#include <deque>

using namespace std;

typedef pair<int, int> coord;

#define MAX_N 100
#define MAX_X 10000
#define _y first
#define _x second

// board: 각 칸이 1이라면 벽 혹은 뱀, 2라면 사과, 그 이외는 빈 칸
// cmd[i]: i초에 왼쪽으로 방향 전환을 한다면 3, 오른쪽으로 한다면 1
char board[MAX_N + 2][MAX_N + 2], cmd[MAX_X + 1];
// dir: 현재 뱀이 진행중인 방향, ans: 게임을 시작한 뒤 경과한 초 수
int dir = 0, ans = 1;
// add[i]: 뱀의 머리가 방향 i로 진행할 때의 위치 변화
coord add[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
// 뱀을 이루는 칸의 집합
deque<coord> snake;

coord operator+(coord a, coord b) { return { a._y + b._y, a._x + b._x }; }

// 좌표 c에 뱀의 머리를 위치시킨다
void push(coord c) {
    // board에 뱀의 머리를 표시한 뒤 snake의 front에 push
    board[c._y][c._x] = 1;
    snake.push_front(c);
}

bool game() {
    // 게임이 아직 유효하다면 true, 아니라면 false
    bool ret = true;
    // 다음에 머리가 위치할 지점
    coord c = snake.front() + add[dir];

    // 머리가 위치할 칸에 대해
    switch (board[c._y][c._x]) {
    // 해당 칸이 벽이거나 뱀의 몸통이라면
    case 1:
        // 게임이 더이상 유효하지 않으므로 이를 표시
        ret = false;
        break;
    // 해당 칸이 빈 칸이라면
    case 0:
        // 뱀의 꼬리를 한 칸 제거한다
        board[snake.back()._y][snake.back()._x] = 0;
        snake.pop_back();
    // 해당 칸이 빈 칸 혹은 사과가 존재하는 칸이라면
    case 2:
        // 뱀의 머리를 한 칸 늘린다
        push(c);
    default:
        // 방향과 게임 진행 시간을 갱신
        dir = (dir + cmd[ans++]) % 4;
        break;
    }

    // 게임이 유효한지 여부를 반환
    return ret;
}

int main() {
    // size: 보드의 크기, cnt: 사과의 개수와 방향 전환 횟수
    // buf: 사과 혹은 방향 전환을 입력받아 저장할 때 사용할 변수
    int size, cnt, buf[2];

    scanf("%d", &size);
    for (int i = 0; i <= size; i++)
        board[0][i] = board[i][0] = board[size + 1][i] = board[i][size + 1] = 1;

    // 뱀의 시작 상태를 push한다
    push({1, 1});

    // 사과의 수를 입력받은 뒤 입력받은 칸에 사과를 배치한다
    scanf("%d", &cnt);
    while (cnt--) {
        scanf("%d %d", &buf[0], &buf[1]);
        board[buf[0]][buf[1]] = 2;
    }

    // 방향 전환 횟수를 입력받은 뒤 입력받은 초에 방향을 전환한다
    scanf("%d", &cnt);
    while (cnt--) {
        scanf("%d %c", &buf[0], &buf[1]);
        cmd[buf[0]] = buf[1] == 'D' ? 1 : 3;
    }

    // 게임이 유효한 동안 게임을 진행
    while (game());

    // 게임을 플레이한 시간을 출력
    printf("%d\n", ans);

    return 0;
}
