#include <cstdio>

#define MAX_N 20
#define init(i, d) d < 2 ? crd((N - 1) * (d % 2), i) : crd(i, (N - 1) * (d % 2))

// N: 보드의 크기, add[i]: {위쪽, 아래쪽, 왼쪽, 오른쪽}[i]으로 블록을 탐색할 변위
// ans: 블록의 최대 크기
int N, add[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, ans = 0;

int max(int a, int b) { return a > b ? a : b; }

// 보드의 각 칸을 pair형 클래스로 탐색
class crd {
public:
    // y, x: 보드의 좌표 (x, y)
    int y = 0, x = 0;
    crd() {}
    crd(int y_, int x_) { y = y_; x = x_; }

    // 현재 좌표가 유효하다면 true, 아니라면 false
    bool valid() { return y >= 0 && y < N && x >= 0 && x < N; }
    // 현재 좌표를 dir 방향으로 한 칸 이동한 좌표
    crd next(int dir) { return { this->y + add[dir][0], this->x + add[dir][1] }; }
};

// 보드의 각 상태를 클래스로 저장
class board {
public:
    // arr[i][j]: 보드의 i행 j열의 블록의 크기
    int arr[MAX_N][MAX_N] = {{ 0, }};

    board() {}

    // arr을 간접적으로 호출
    int* operator[](int i) { return arr[i]; }
    int& operator[](crd c) { return arr[c.y][c.x]; }

    // cnt번 이동시켜서 얻을 수 있는 가장 큰 블록을 ans에 저장
    void backtrack(int cnt) { if (cnt) for (int d = 0; d < 4; d++) backtrack(cnt, d); }
    void backtrack(int cnt, int dir) {
        // 직전에 블록을 합쳤다면 true, 아니라면 false
        bool chk;
        // q: 보드를 dir 방향으로 이동시켰을 때 각 행 / 열의 상태, len: q의 길이
        int q[MAX_N], len;
        // 현재 상태를 보존하기 위해 만든 새 보드
        board b = *this;
        // 보드를 탐색하기 위한 인덱스
        crd c;

        // 보드의 각 행/ 열에 대해
        for (int i = 0; i < N; i++) {
            // 큐와 그 길이, 블록을 합쳤는지 여부를 초기화
            for (int j = len = chk = 0; j < N; j++) q[j] = 0;

            // 각 행 / 열의 이동 방향의 끝점부터 시작점까지의 모든 블록에 대해
            for (c = init(i, dir); c.valid(); c = c.next(dir)) if (b[c]) {
                // 현재 블록값이 직전에 q에 들어간 합쳐지지 않은 블록값과 같다면
                // q에 있는 블록값을 두배로 한 뒤 블록의 최댓값을 갱신하고
                // q에 있는 블록이 합쳐져서 만든 블록임을 표시
                if (len && q[len - 1] == b[c] && !chk)
                    chk = ans = max(ans, q[len - 1] *= 2);
                // 그렇지 않다면 q에 현재 블록을 push
                else chk = !(q[len++] = b[c]);
            }

            // 현재 행 / 열을 비운 뒤 q에 있는 각 블록을 차례로 배치
            c = init(i, dir);
            for (int j = 0; j < N; c = c.next(dir)) b[c] = q[j++];
        }

        // 가능한 이동 횟수를 1 줄인 뒤 최대 블록값 계산
        b.backtrack(cnt - 1);
    }
} brd;

int main() {
    // 문제의 조건을 입력받으며 초기 상태의 블록의 최댓값 계산
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        scanf("%d", &brd[i][j]);
        ans = max(ans, brd[i][j]);
    }

    // 최대 5회 이동했을 때의 블록의 최댓값을 계산해 출력
    brd.backtrack(5);
    printf("%d\n", ans);

    return 0;
}
