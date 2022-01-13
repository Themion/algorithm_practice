#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 20
#define append(c) q.push(c); visit[c] = true;

// N: 공간의 크기, siz: 상어의 크기, cnt: 상어가 성장하기 위해 먹어야 하는 물고기
// add[dir]: {위쪽, 왼쪽, 오른쪽, 아래}[dir] 방향으로 한 칸 이동하는 변위
int N, siz = 2, cnt = 2, add[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

// 좌표를 클래스를 이용해 구현
class coord {
public:
    // 좌표 (x, y)
    int y = 0, x = 0;
    coord() {}
    coord(int y_, int x_) { y = y_; x = x_; }

    // 문제 해결을 위해서 >와 ==, dir 방향으로 한 칸 이동을 구현
    bool operator>(coord c) { return y == c.y ? x > c.x : y > c.y; }
    bool operator==(coord c) { return y == c.y && x == c.x; }
    coord operator+(int dir) { return { y + add[dir][0], x + add[dir][1] }; }

    // 해당 좌표가 공간 내에 존재하는지 여부를 반환
    bool valid() { return y >= 0 && y < N && x >= 0 && x < N; }
} s;

// N * N 크기 공간
class board {
public:
    int arr[MAX_N][MAX_N] = {{ 0, }};

    // operator[]를 이용해 2차원 배열에 간단한 접근을 지원한다
    int* operator[](int i) { return arr[i]; }
    int& operator[](coord c) { return arr[c.y][c.x]; }
} brd;

int find() {
    // 물고기를 찾는 데 걸린 시간
    int t = 0, len = 1;
    // visit[c]: 좌표 c를 방문한 적 있다면 true, 아니라면 fasle
    board visit;
    // c: q.front에서 상하좌우로 인접한 노드 dest: 잡아먹을 수 있는 물고기의 좌표
    coord c, dest = s;
    // bfs를 위한 큐
    queue<coord> q;

    // 큐에 시작 노드를 append한 뒤 방문한 적 있음을 표시
    append(s);

    // 같은 거리에 있는 모든 좌표를 한꺼번에 탐색
    for (t = 0; !q.empty() && dest == s; t++) for (int len = q.size(); len--; ) {
        // 현재 노드에서 인접한 노드를 탐색
        for (int d = 0; d < 4; d++) {
            c = q.front() + d;

            // 좌표가 valid하지 않거나, 방문한 적 있거나
            // 해당 좌표에 너무 큰 물고기가 있다면 continue
            if (!c.valid() || visit[c] || brd[c] > siz) continue;
            // 해당 좌표에 먹을 수 있는 조건에 부합하는 물고기가 있다면
            // 해당 좌표를 도착 노드로 설정
            else if (brd[c] && brd[c] < siz && (dest == s || dest > c)) dest = c;
            // bfs를 위해 q에 c를 append
            append(c);
        }

        q.pop();
    }

    // 도착 노드가 시작 노드와 같다면 먹을 수 있는 물고기가 없으므로 0을 반환
    if (dest == s) return 0;
    // 그렇지 않다면 먹을 수 있는 물고기를 찾았으므로
    else {
        // 해당 물고기를 먹은 뒤 상어의 위치를 도착 노드로 이동
        brd[dest] = 0;
        s = dest;
        // 물고기를 먹어서 사이즈를 늘릴 수 있다면 늘린다
        if (!--cnt) cnt = ++siz;
        // 이동하는 데 걸린 시간을 반환
        return t;
    }
}

int main() {
    // ans: 가능한 모든 물고기를 잡아먹는 시간, t: 물고기 하나를 잡아먹는 시간
    int ans = 0, t;

    // 문제의 조건을 입력받으며 상어가 있는 좌표를 저장
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        scanf("%d", &brd[i][j]);
        if (brd[i][j] == 9) brd[s = { i, j }] = 0;
    }

    // 물고기를 최대한 잡아먹은 뒤 걸린 총 시간을 출력
    while (t = find()) ans += t;
    printf("%d\n", ans);

    return 0;
}
