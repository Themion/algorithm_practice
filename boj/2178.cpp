#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> coord;

#define MAX_N 100
#define _y first
#define _x second

// table[y][x]: 현재 노드가 탐색 가능하다면 true, 아니라면 false
bool table[MAX_N][MAX_N];
// N, M: 그래프의 너비/높이, add: 이웃한 좌표를 계산할 때 사용
int N, M, add[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// bfs에서 방문할 노드를 저장할 큐
queue<coord> q;

bool valid(coord c) {
    return (c._y >= 0) && (c._y < N) && (c._x >= 0) && (c._x < M) &&
        table[c._y][c._x];
}
coord operator+(coord c, int a[2]) { return { c._y + a[0], c._x + a[1] }; }
void push(coord c) {
    table[c._y][c._x] = false;
    q.push(c);
}

int bfs() {
    //y, x: 이웃한 좌표, cnt: 노드를 이동한 횟수, size: bfs 시 각 단계별 큐의 크기
    int y, x, cnt = 1, size = 1;
    // 방문할 노드의 좌표
    coord c;

    // 시작점을 먼저 push한다
    table[0][0] = false;
    q.push({0, 0});

    // 큐에 노드가 존재할 동안
    while (!q.empty() && table[N - 1][M - 1]) {
        // 현재 노드와 이웃한 노드에 대해
        for (auto a : add) {
            c = q.front() + a;
            // 이웃한 노드의 좌표를 계산한 뒤 그 좌표가 valid한지 판정
            if (valid(c)) push(c);
        }
        // 현재 노드에서 이동 가능한 노드를 모두 push했으므로 pop
        q.pop();

        // q의 cnt번째 원소를 모두 사용했다면 cnt를 1 늘리고 size를 갱신
        if (!--size) {
            cnt++;
            size = q.size();
        }
    }

    // 끝점까지 도달하는 데 필요한 최소 발판의 수를 출력
    return cnt + (size != q.size());
}

int main() {
    // 미로를 한 글자씩 입력받을 때 사용할 버퍼
    char buf;
    // 미로의 크기를 입력받고
    scanf("%d %d", &N, &M);
    // 미로의 '1'을 true, '0'을 false로 바꿔 저장
    for (int i = 0; i < N; i++) {
        scanf("\n");
        for (int j = 0; j < M; j++) {
            scanf("%c", &buf);
            table[i][j] = buf == '1';
        }
    }

    // bfs한 결과를 출력
    printf("%d\n", bfs());

    return 0;
}
