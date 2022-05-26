#include <cstdio>

typedef unsigned int ui;

#define MAX_N 10
#define INF 0xffffffff

#define FOR(k, K) for(int k = 0; k < K; k++)
// 보드의 상태에 따라 visit을 조회
#define state(b) visit[b.R.y][b.R.x][b.B.y][b.B.x]

class board;
void tilt(board b, ui cnt);
void tilt(board b, ui cnt, int dir);

// N, M: 보드의 크기, add: 보드의 각 방향으로의 변위
int N, M, add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// visit[a][b][c][d]: 빨간 구슬이 좌표 (b, a), 파란 구슬이 좌표 (d, c)에 있을 때의 최소 기울임 횟수
// ans: 빨간 구슬만 구멍에 넣을 때의 최소 기울임 횟수
ui visit[MAX_N][MAX_N][MAX_N][MAX_N], ans = INF;

ui min(ui a, ui b) { return a < b ? a : b; }

// 보드의 각 칸을 pair형 클래스로 탐색
class crd {
public:
    // y, x: 보드의 좌표 (x, y)
    int y = 0, x = 0;
    crd() {}
    crd(int y_, int x_) { y = y_; x = x_; }

    // 현재 좌표가 유효하다면 true, 아니라면 false
    bool valid() { return y >= 0 && y < N && x >= 0 && x < M; }
    // 현재 좌표를 dir 방향으로 한 칸 이동한 좌표
    crd next(int dir) { return { this->y + add[dir][0], this->x + add[dir][1] }; }
};

class board {
public:
    // arr[y][x]: 보드의 칸 (x, y)
    char arr[MAX_N][MAX_N];
    // R: 빨간 구슬의 좌표, B: 파란 구슬의 좌표, O: 구멍의 좌표
    crd R, B, O;

    // arr을 간접적으로 호출
    char* operator[](int i) { return arr[i]; }
    char& operator[](crd c) { return arr[c.y][c.x]; }

    // 좌표 c가 유효하지 않다면 -2, 벽이라면 -1, 구슬이라면 0, 빈 칸 혹은 구멍이라면 1
    int valid(crd c) {
        if (!c.valid()) return -2;
        else switch(this->arr[c.y][c.x]) {
            case '#': return -1;
            case 'R':
            case 'B': return 0;
            default: return 1;            
        }
    }
};

// 보드 b를 cnt번째로 기울였을 때 가능한 경우를 모두 탐색
void tilt(board b, ui cnt) { FOR(d, 4) tilt(b, cnt, d); }
// 보드 b를 cnt번째로 기울이고 그 방향이 {위쪽, 아래쪽, 왼쪽, 오른쪽}[dir]일 때
void tilt(board b, ui cnt, int dir) {
    // 빨간 구슬이 구멍에 빠졌다면 true, 아니라면 false
    bool red_in = false;

    // 두 구슬 다 {위쪽, 아래쪽, 왼쪽, 오른쪽}[dir]으로 움직일 수 없다면 return
    if (b.valid(b.R.next(dir)) <= 0 && b.valid(b.B.next(dir)) <= 0) return;
    // 두 구슬 모두 움직일 수 있을 때
    while (b.valid(b.R.next(dir)) > -1 && b.valid(b.B.next(dir)) > -1 && !red_in) {
        // 두 구슬의 현재 위치를 비운 뒤
        b[b.R] = b[b.B] = '.';
        // 좌표를 1 이동시키고
        b.R = b.R.next(dir);
        b.B = b.B.next(dir);
        // 파란 구슬이 구멍에 빠졌다면 return
        if (b[b.B] == 'O') return;
        // 빨간 구슬이 구멍에 빠졌다면 red_in에 표시
        else if (b[b.R] == 'O') red_in = true;
        // 둘 다 구멍에 빠지지 않았다면 이동시킨 위치에 구슬을 다시 표시
        else {
            b[b.B] = 'B';
            b[b.R] = 'R';
        }
    }

    // 파란 구슬이 움직일 수 있을 때
    while (b.valid(b.B.next(dir)) == 1) {
        // 파란 구슬의 현재 위치를 비운 뒤
        b[b.B] = '.';
        // 좌표를 1 이동시키고
        b.B = b.B.next(dir);

        // 파란 구슬이 구멍에 빠졌다면 return
        if (b[b.B] == 'O') return;
        // 구멍에 빠지지 않았다면 이동시킨 위치에 구슬을 다시 표시
        else b[b.B] = 'B';
    }

    while (b.valid(b.R.next(dir)) == 1 && !red_in) {
        b[b.R] = '.';
        // 좌표를 1 이동시키고
        b.R = b.R.next(dir);

        // 빨간 구슬이 구멍에 빠졌다면 red_in에 표시
        if (b[b.R] == 'O') red_in = true;
        // 구멍에 빠지지 않았다면 이동시킨 위치에 구슬을 다시 표시
        else b[b.R] = 'R';
    }

    // 기울인 뒤의 상태를 더 적은 기울임 횟수로 만들 수 있다면 return
    if (state(b) < cnt) return;
    // 아니라면 최소 기울임 횟수를 갱신
    else state(b) = cnt;

    // 빨간 구슬이 구멍에 빠졌다면 보드를 기울이는 최소 횟수를 갱신
    if (red_in) ans = min(ans, cnt);
    // 그렇지 않다면 두 구슬 다 움직일 수 있으므로 보드를 다시 한 번 기울인다
    else tilt(b, cnt + 1);
}

int main() {
    board brd;

    // 문제의 조건을 입력받으며 두 구슬과 구멍의 위치를 저장
    scanf("%d %d", &N, &M);
    FOR(y, N) {
        scanf("%*c");
        FOR(x, M) {
            scanf("%c", &brd[y][x]);
            if      (brd[y][x] == 'B') brd.B = { y, x };
            else if (brd[y][x] == 'R') brd.R = { y, x };
            else if (brd[y][x] == 'O') brd.O = { y, x };
        }
    }

    // 모든 상태의 기울임 횟수를 INF로 지정
    FOR(a, MAX_N) FOR(b, MAX_N) FOR(c, MAX_N) FOR(d, MAX_N) visit[a][b][c][d] = INF;

    // 보드를 이리저리 기울이며 모든 경우를 시험해본 뒤
    tilt(brd, 1);
    // 빨간 구슬만 구멍에 넣을 수 있다면 기울이는 최소 횟수를 출력
    printf("%d\n", ans);

    return 0;
}
