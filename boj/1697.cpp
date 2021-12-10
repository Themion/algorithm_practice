#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 100000

// visit[i]: 노드 i를 방문했다면 true
bool visit[MAX_N + 1];
// bfs에 사용할 노드
queue<int> q;

// q에 node를 push하고 방문 여부를 표시
void push(int node) {
    // node가 범위를 벗어났거나 이미 방문한 노드라면 return
    if (node < 0 || node > MAX_N || visit[node]) return;
    q.push(node);
    visit[node] = true;
}

int main() {
    // N: 시작 노드, K: 도착 노드
    // time: 도착 노드까지 걸리는 시간, size: bfs에 사용되는 큐의 크기
    int N, K, time = 0, size = 1;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &K);

    // 시작 노드를 q에 push
    push(N);

    // 목표 노드를 찾을 때까지 탐색 가능한 모든 노드에 대해
    while (!visit[K]) {
        // 큐에서 노드 하나를 가져온 뒤
        int node = q.front();
        q.pop();

        // 현재 노드에서 1초만에 이동 가능한 모든 노드 n를 q에 push
        for (auto n : {node - 1, node + 1, node * 2}) push(n);

        // time 시간에 도착 가능한 모든 노드를 탐색했다면
        if (!--size) {
            // q의 크기를 갱신하고 시간을 1 늘린다
            size = q.size();
            time++;
        }
    }
    
    // N에서 K까지 이동하는 데에 걸리는 최소 시간을 출력
    // q의 모든 원소를 탐색하지 않았다면 time은 정답 - 1이기 때문에 에러 처리
    printf("%d\n", time + (size != q.size()));

    return 0;
}
