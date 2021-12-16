#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> coord;
typedef pair<int, bool> stat;
typedef pair<coord, stat> agent;

#define MAX_Y 1000
#define MAX_X 1000
#define INF 0x3f3f3f3f

#define __y first
#define __x second
#define _y first.first
#define _x first.second
#define _cost second.first
#define _broken second.second

int N, M;
// 입력값으로 주어지는 맵
bool graph[MAX_Y][MAX_X];
// visit[y][x][broken]: (x, y) 좌표 + 벽을 부쉈는지에 따라 방문 여부를 체크
bool visit[MAX_Y][MAX_X][2] = {{ {true, true}, }};

queue<agent> q;

bool valid(int y, int x) { return y >= 0 && y < N && x >= 0 && x < M; }
void set_min(int &a, int b) { a = a < b ? a : b; }
coord operator+(coord c, int a[2]) { return {c.__y + a[0], c.__x + a[1]}; }

// agent 하나를 push하면서 visit에 표시
void push(agent a) {
    visit[a._y][a._x][a._broken |= !graph[a._y][a._x]] = true;
    q.push(a);
}

int move_agent(agent a) {
    // a.coord에 add값을 더해 상하좌우 좌표를 구한다
    int add[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // q에서 가져온 값 a를 q에서 제거
    q.pop();

    // a의 상하좌우 좌표값에 대해
    for (int i = 0; i < 4; i++) {
        // a를 상하좌우로 옮긴 값
        agent a_ = {a.first + add[i], {a._cost + 1, a._broken}};
        // a_의 위치를 방문했는지 여부
        auto &v = visit[a_._y][a_._x];

        // 좌표가 잘못되었거나 이미 방문한 좌표인 경우 continue
        if (!valid(a_._y, a_._x) || v[a_._broken]) continue;
        // a_로 그냥 이동할 수 있거나 벽을 뚫어 이동할 수 있다면 이동
        else if (graph[a_._y][a_._x] || (!a_._broken && !v[true])) push(a_);
    }

    // 도착 지점에 도착했다면 cost를, 아니라면 INF를 출력
    return (a._y == N - 1 && a._x == M - 1) ? a._cost : INF;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 그래프를 입력받을 때 사용할 버퍼
    char buf;
    // 맵을 이동하는 최소 비용
    int ans = INF;

    // 그래프를 입력받는다
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> buf;
        graph[i][j] = buf == '0';
    }

    // 시작지점인 (0, 0)을 q에 push
    q.push({{0, 0}, {1, false}});
    // 그래프를 탐색하며 도착 지점까지의 최소 비용을 계산
    while(!q.empty()) set_min(ans, move_agent(q.front()));

    // 최소 비용이 존재한다면 최소 비용을, 존재하지 않는다면 -1을 출력
    cout << (ans ^ INF ? ans : -1) << '\n';

    return 0;
}
