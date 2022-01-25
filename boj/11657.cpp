#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;
typedef long long ll;

#define MAX_N 500
#define INF 0x3f3f3f3f3f3f3f3f

#define _node first
#define _cost second

// N: 노드의 수, M: 에지의 수
int N, M;
// cost[i]: 노드 i로 이동하는 데에 걸리는 최소 시간
ll cost[MAX_N + 1] = { 0, };
// 벨만 포드에서 각 step때 탐색을 시작할 노드의 집합
queue<int> q({1});
// v[i]: 노드 i에서 시작하는 에지의 집합
vector<edge> v[MAX_N + 1];

// node에서 에지를 하나 사용해 그래프를 탐색
bool push(short node) {
    // 비용을 하나라도 단축시켰다면 true
    bool ret = false;
    // 시작 노드에서 node까지 이동한 뒤 에지를 하나 사용한 비용
    ll cost_;

    // node가 q.front이므로 q에서 node를 pop한다
    q.pop();

    // node에서 시작하는 모든 에지에 대해
    for (edge e : v[node]) {
        // 현재 에지를 사용해 얻을 수 있는 비용을 계산
        cost_ = cost[node] + e._cost;
        // 비용 감소가 불가능하다면 현재 에지를 건너뛴다
        if (cost[e._node] <= cost_) continue;

        // 비용을 감소시킨 뒤 현재 에지를 사용해 도착한 노드를 q에 push
        cost[e._node] = cost_;
        q.push(e._node);
        // 비용의 변화가 발생했으므로 ret에 true를 저장
        ret = true;
    }

    // 값이 바뀌었는지 여부를 반환
    return ret;
}

// 그래프가 음의 가중치를 갖는다면 true
bool bellman_ford() {
    // 에지를 1개부터 N - 1개까지 사용할 때의 최소 비용을 계산
    for (int i = 1; i < N; i++)
        // 에지를 i - 1개 사용했을 때 도달한 노드에서 에지를 하나 사용해 이동
        for (int len = q.size(); len--; ) push(q.front());

    // 에지를 총 N - 1개 사용한 이후에 갱신 가능한 거리가 있다면
    // 음의 가중치를 갖는 사이클이 존재하므로 true를 반환
    for (int len = q.size(); len--; ) if (push(q.front())) return true;
    // 거리를 갱신하지 못했다면 음의 가중치를 갖는 사이클이 존재하지 않는다
    return false;
}

int main() {
    // A, B, C: 노드 A에서 B로 이동하며 비용이 C인 에지
    int A, B, C;

    // 문제의 조건을 입력받으며 v에 에지를 각각 push
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        v[A].push_back({B, C});
    }
    // 시작 노드를 제외한 모든 노드로 이동하는 비용을 INF로 초기화
    for (int i = 2; i <= N; i++) cost[i] = INF;

    // 벨만-포드를 이용해 가중치가 음인 사이클을 발견했다면 -1을 출력
    if (bellman_ford()) printf("-1\n");
    // 그렇지 않다면 각 노드로 이동할 수 있을 때 그 최소 비용을,
    // 이동할 수 없다면 -1을 출력
    else for (int i = 2; i <= N; i++)
        printf("%lld\n", cost[i] != INF ? cost[i] : -1);

    return 0;
}
