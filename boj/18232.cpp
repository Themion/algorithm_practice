#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 300000

// visit[n]: 노드 n에 방문했다면 true, 아니면 false
bool visit[MAX_N + 1];
// N: 노드의 수
int N;
// q: bfs를 위한 큐
queue<int> q;

// 큐에 n을 push
void push(int n) {
    // 노드 n이 valid한 노드이고 아직 방문한 적 없다면 q에 push한 다음 방문함을 표시
    if (n >= 1 && n <= N && !visit[n]) {
        q.push(n);
        visit[n] = true;
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // M: 텔레포트의 수, S: 시작 노드/현재 노드, E: 목표 노드, a, b: 입력을 위한 버퍼
    // len: 이중 for문을 회피하기 위해 만든 q의 초기 길이 변수
    // time: 시작 노드에서 현재 노드까지 이동하기 위해 걸리는 시간
    int M, S, E, a, b, len = 1, time = 0;
    // v[i]: 노드 i에서 텔레포트로 갈 수 있는 노드의 집합
    vector<int> v[MAX_N + 1];

    // 문제 조건 입력
    cin >> N >> M >> S >> E;
    while (M--) {
        cin >> a >> b;
        // 텔레포트는 양방향이므로 v에도 양방향으로 push
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // q에 시작 노드 S를 push
    push(S);

    // 방문 가능한 모든 노드에 대해
    while (!q.empty() && !visit[E]) {
        // 이전 스텝의 노드를 모두 방문했다면
        if (!--len) {
            // q의 알려진 길이를 갱신하고 시간을 1 늘린다
            len = q.size();
            time++;
        }

        // q에서 노드 하나를 꺼내와 S에 저장
        S = q.front();
        q.pop();

        // 인접한 노드와 텔레포트 가능한 노드를 q에 push
        push(S - 1); push(S + 1);
        for (auto i: v[S]) push(i);
    }

    // S -> E에 걸린 시간을 출력
    cout << time << '\n';

    return 0;
}
