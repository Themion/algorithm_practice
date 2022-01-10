#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 100000

int main() {
    // visit[i]: t초에 점 i로 이동 가능하다면 true, 아니라면 false
    bool visit[MAX_N + 1] = { 0, };
    // N, K: 시작점과 도착점, cnt[i]: 노드 i로 갈 수 있는 방법의 수
    // t: 도착 노드까지 걸리는 시간
    int N, K, cnt[MAX_N + 1] = { 0, }, t = 0;
    // q: bfs 탐색에서 방문할 노드를 저장한 큐, vis: 방문함을 표시할 노드의 큐
    queue<int> q, vis;

    // 시작점과 도착점을 입력받은 뒤
    scanf("%d %d", &N, &K);

    // 시작점이 도착점보다 크거나 같다면 후퇴만을 이용해 도착 가능하고
    // 이 때 걸리는 시간은 N - K, 가능한 방법의 수는 1이다
    if (N >= K) t = N - K, cnt[K] = 1;
    // 그렇지 않다면
    else {
        // 시작 노드 N을 q에 넣고
        q.push(N);
        // N에 도착하는 방법, 즉 초기 상태의 경우의 수인 1을 cnt[N]에 저장
        cnt[N] = 1;

        // K에 도착할 때까지 시간을 1씩 늘리며 탐색
        for (; !cnt[K]; t++) {
            // 현재 시간에 방문 가능한 모든 노드에 대해
            for (int len = q.size(); len--; ) {
                // 각 노드를 q에서 하나씩 가져온 뒤
                N = q.front();
                q.pop();

                // 해당 노드와 인접한 노드 n에 대해
                for (auto n : {N - 1, N + 1, N * 2})
                    // 노드 n이 범위 이내이고 방문한 적 없다면
                    if (n >= 0 && n <= MAX_N && !visit[n]) {
                        // 노드 n을 한 번만 탐색하고
                        if (!cnt[n]) {
                            q.push(n);
                            vis.push(n);
                        }
                        // 현재 노드로 이동 가능한 경우의 수만큼
                        // 노드 n으로 이동 가능한 경우의 수를 늘린다
                        cnt[n] += cnt[N];
                    }
            }
            // 경우의 수를 계산한 모든 노드에 대해 방문했음을 visit에 표시
            while (!vis.empty()) {
                visit[vis.front()] = true;
                vis.pop();
            }
        }
    }

    // 노드 K에 도착하는 데 걸리는 최소 시간과 그 방법의 수를 출력
    printf("%d\n%d\n", t, cnt[K]);

    return 0;
}
