#include <cstdio>
#include <queue>

using namespace std;

typedef pair<short, short> crd;

#define MAX_N 100
#define MAX_DIST 1000
#define _x first
#define _y second

int abs(short num) { return (int)(num >= 0 ? num : -num); }
// 두 좌표 a와 b의 맨하탄 거리
int dist(crd a, crd b) { return abs(a._x - b._x) + abs(a._y - b._y); }

bool test_case() {
    // visit[i]: i번 노드에 방문했다면 true, 아니라면 false
    bool visit[MAX_N + 2] = { true, };
    // 노드의 개수
    int N;
    // 각 노드의 좌표
    crd node[MAX_N + 2];
    // bfs에 사용할 큐
    queue<int> q({0});

    // 시작 노드와 도착 노드를 제외한 노드의 수를 입력받은 뒤
    scanf("%d", &N); N += 2;
    // 각 노드의 좌표를 입력받는다
    for (int i = 0; i < N; i++)
        scanf("%hd %hd", &(node[i]._x), &(node[i]._y));

    // 도착 노드에 도달할 때까지 bfs 실행
    while (!q.empty() && !visit[N + 1]) {
        // 모든 노드에 대해
        for (int i = 1; i < N; i++) {
            // 방문한 적 있는 노드거나
            // 현재 노드와의 거리가 MAX_DIST 이상이라면 continue
            if (visit[i] || dist(node[q.front()], node[i]) > MAX_DIST)
                continue;
            // 노드 i를 q에 push한 뒤 방문한 적 있음을 표시
            q.push(i);
            visit[i] = true;
        }
        // 불필요한 현재 노드를 pop
        q.pop();
    }

    // N - 1번 노드, 즉 도착 노드에 방문한 적 있는지 여부를 반환
    return visit[N - 1];
}

int main() {
    int T;
    // 테스트 케이스의 수를 입력받아 각 테스트 케이스를 실행
    for (scanf("%d", &T); T--; )
        printf("%s\n", test_case() ? "happy" : "sad");
    return 0;
}
