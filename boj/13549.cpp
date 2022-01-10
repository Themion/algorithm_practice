#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 100000

bool visit[MAX_N]= { 0, };
queue<int> q;

// 노드 N에 도착했을 때 노드 N에서 텔레포트로 이동 가능한 노드를 모두 방문
void push(int N) {
    // 노드 N의 값이 MAX_N을 넘지 않을 동안 계속해서 텔레포트
    for (; N <= MAX_N && !visit[N]; N *= 2) {
        // N을 q에 넣고 visit에 표시
        q.push(N);
        visit[N] = true;
    }
}

int main() {
    // N: 시작 노드, K: 도착 노드, t: 노드 N에서 노드 K까지 이동하는 데에 걸리는 시간
    int N, K, t = 0, len = 1;

    // 시작 노드와 도착 노드를 입력받은 뒤
    scanf("%d %d", &N, &K);
    // N * 2 ^ k를 모두 q에 push
    push(N);

    // 도착 노드가 시작 노드보다 값이 작다면 걸어서 도착 노드로 이동해야 한다
    if (N >= K) t = N - K;
    // 텔레포트를 사용할 수 있다면 bfs를 이용해 탐색
    else while (!q.empty() && !visit[K]) {
        // t초에 탐색 가능한 노드를 모두 탐색했다면 len을 재설정한 뒤 t를 1 늘린다
        if (!--len) {
            len = q.size();
            t++;
        }

        // q에서 노드를 하나 가져온 뒤
        N = q.front();
        q.pop();

        // 1초만에 걸어서 이동 가능한 노드를 모두 push를 통해 방문
        for (auto n : {N - 1, N + 1}) if (n >= 0 && n <= MAX_N) push(n);
    }

    // 노드 K에 도착하는 데 걸리는 최소 시간을 출력
    printf("%d\n", t);

    return 0;
}
