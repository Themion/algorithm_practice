#include <cstdio>

#define MAX_N 10
#define MAX_TILT 10

int N, M, add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, ans = MAX_TILT + 1;

int min(int a, int b) { return a < b ? a : b; }

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
    
    board() {}

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

    // 보드를 cnt번째로 기울였을 때 가능한 경우를 모두 탐색
    void backtrack(int cnt) {
        if (cnt <= MAX_TILT) for (int d = 0; d < 4; d++) backtrack(cnt, d);
    }
    // 보드를 cnt번째로 기울이고 그 방향이 {위쪽, 아래쪽, 왼쪽, 오른쪽}[dir]일 때
    void backtrack(int cnt, int dir) {
        // 빨간 구슬이 구멍에 빠졌다면 true, 아니라면 false
        bool red_in = false;
        // 현재 상태를 보존하기 위해 만든 새 보드
        board b = *this;

        // 두 구슬 다 {위쪽, 아래쪽, 왼쪽, 오른쪽}[dir]으로 움직일 수 없다면 return
        while (b.valid(b.R.next(dir)) <= 0 && b.valid(b.B.next(dir)) <= 0)
            return;
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

        // 빨간 구슬이 구멍에 빠졌다면 보드를 기울이는 최소 횟수를 갱신
        if (red_in) ans = min(ans, cnt);
        // 그렇지 않다면 두 구슬 다 움직일 수 있으므로 보드를 다시 한 번 기울인다
        else b.backtrack(cnt + 1);
    }
} brd;

int main() {
    // 문제의 조건을 입력받으며 두 구슬과 구멍의 위치를 저장
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        scanf("%*c");
        for (int x = 0; x < M; x++) {
            scanf("%c", &brd[y][x]);
            if      (brd[y][x] == 'B') brd.B = { y, x };
            else if (brd[y][x] == 'R') brd.R = { y, x };
            else if (brd[y][x] == 'O') brd.O = { y, x };
        }
    }

    // 보드를 이리저리 기울이며 모든 경우를 시험해본 뒤
    brd.backtrack(1);
    // 빨간 구슬만 구멍에 넣을 수 있다면 기울이는 최소 횟수를, 그렇지 않다면 -1을 출력
    printf("%d\n", ans <= MAX_TILT ? ans : -1);

    return 0;
}
