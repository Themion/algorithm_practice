#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

#define MAX_N 500
#define INF 0x3f3f3f3f

#define _cost first
#define _node second

queue<int> q;
vector<edge> v[MAX_N];

int N, M, W, cost[MAX_N]; 
int graph[MAX_N][MAX_N];

void set_min(int &a, int b) { a = a < b ? a : b; }

// node에서 에지를 하나 사용해 그래프를 탐색
bool push(int node) {
    // 비용을 하나라도 단축시켰다면 true
    bool val_changed = false;
    // 시작 노드에서 node까지 이동한 뒤 에지를 하나 사용한 비용
    int cost_;

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
        // 비용의 변화가 발생했으므로 val_changed에 true를 저장
        val_changed = true;
    }

    // 값이 바뀌었는지 여부를 반환
    return val_changed;
}

// 그래프가 음의 가중치를 갖는다면 true
bool bellman_ford() {
    // 에지를 i개 사용할 때의 q의 크기
    int size = q.size();

    // 에지를 1개부터 N - 1개까지 사용할 때의 최소 비용을 계산
    for (int i = 1; i < N; i++) {
        // 에지를 i - 1개 사용했을 때 도달한 노드에서 에지를 하나 사용해 이동
        while (size--) push(q.front());
        // q의 크기를 재측정
        size = q.size();
    }

    // 에지를 총 N - 1개 사용한 이후에 갱신 가능한 거리가 있다면
    // 음의 가중치를 갖는 사이클이 존재하므로 true를 반환
    while (size--) if (push(q.front())) return true;
    // 거리를 갱신하지 못했다면 음의 가중치를 갖는 사이클이 존재하지 않는다
    return false;
}

bool test_case() {
    // S, E, T: 노드 S에서 노드 E로 향하며 가중치 T를 가진 에지
    int S, E, T;
    
    // 그래프의 크기와 도로, 웜홀의 수를 입력받은 뒤
    cin >> N >> M >> W;

    // 전역변수 초기화
    for (int i = 0; i < N; i++)  {
        fill_n(graph[i], N, INF);
        v[i] = vector<edge>();
    }
    fill_n(cost, N, INF);
    q = queue<int>();

    // 각 에지와 웜홀에 대해
    for (int i = 0; i < M + W; i++) {
        // 에지를 입력받은 뒤
        cin >> S >> E >> T;

        // 에지가 웜홀이라면 가중치를 음수로 변경
        if (i >= M) T = -T;
        // 에지의 최솟값을 설정한 뒤
        set_min(graph[--S][--E], T);
        // 에지가 도로라면 에지를 뒤집어서 최솟값을 설정
        if (i < M) set_min(graph[E][S], T);

        // 모든 에지의 시작점을 탐색의 시작점으로 설정
        q.push(S);
    }

    // 노드 i와 노드 j를 잇는 에지를 v에 push
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        if (graph[i][j] != INF) v[i].push_back({graph[i][j], j});
    
    // 벨만-포드 알고리즘으로 음의 가중치를 갖는 사이클을 탐색
    return bellman_ford();
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    // 테스트 케이스의 수만큼 반복
    while (TC--) cout << (test_case() ? "YES" : "NO") << '\n';

    return 0;
}
