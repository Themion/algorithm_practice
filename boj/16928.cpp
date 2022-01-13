#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define END 100
#define append(i) q.push(i); visit[i] = true;

int main() {
    // visit[i]: 노드 i에 방문한 적이 있다면 true, 아니라면 false
    bool visit[END + 1] = { false, true, };
    // N: 사다리의 수, M: 뱀의 수, s, e: 각 사다리와 뱀의 시작점과 끝점
    // step: 주사위를 굴릴 횟수
    // arrive[i]: 노드 i에 도착했을 때 실제로 도달하게 될 노드
    int N, M, s, e, step = 0, len = 1, arrive[END + 1] = { 0, };
    // bfs에 사용할 큐
    queue<int> q;
    // v[i]: 노드 i에서 주사위를 굴려 갈 수 있는 노드
    vector<int> v[END + 1];

    // arrive[i]의 기본 값을 지정
    for (int i = 1; i <= END; i++) arrive[i] = i;

    // 각 뱀과 사다리의 시작점과 도착점을 입력받은 뒤 이동 관계를 arrive에 저장
    for (scanf("%d %d", &N, &M); N ? N-- : M--; ) {
        scanf("%d %d", &s, &e);
        arrive[s] = e;
    }

    // 각 노드에서 주사위를 굴려 이동 가능한 노드를 계산
    for (int i = 1; i < END; i++) for (int j = 1; j <= 6 && i + j <= END; j++)
        v[i].push_back(arrive[i + j]);

    // 게임은 반드시 1번 노드에서 시작하므로 q에 1을 push
    append(1);

    // 100번 노드에 도착할 때까지 bfs를 실행한 뒤 최소 step을 반환
    while (!visit[END]) {
        if (!--len) {
            len = q.size();
            step++;
        }

        // 도착 가능한 노드를 q에서 가져온 뒤
        s = q.front();
        q.pop();

        // s에서 이동 가능한 노드를 q에 push
        for (int i : v[s]) if (!visit[i]) { append(i); }
    }
    printf("%d\n", step);

    return 0;
}
