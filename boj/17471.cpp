#include <cstdio>

typedef unsigned int ui;

#define MAX_N 10
#define INF 0xffffffff

// N: 사람의 수, val: 각 지역의 인구수, graph: 각 지역과 인접한 지역을 bitmask꼴로 저장
int N, val[MAX_N], graph[MAX_N];

// num을 bitmask로 바꾸어 반환
int bit(int num) { return 1 << num; }
// num의 절댓값을 반환 
ui abs(int num) { return num < 0 ? -num : num; }
// a와 b중 최솟값을 반환
ui min(ui a, ui b) { return a < b ? a : b; }

// state에서 node를 제거한 뒤 node와 인접한 노드를 탐색
void dfs(int& state, int node) {
    // state에서 node를 제거한 뒤
    state &= ~bit(node);
    // state에서 node와 인접한 노드를 찾는다면 해당 노드에서 dfs 실행
    for (int i = 0; i < N; i++) if (state & bit(i) && graph[node] & bit(i))
        dfs(state, i);
}

// state가 인접한 구역만으로 이루어져 있는지 확인
bool valid(int state) {
    // dfs를 시작할 시작 노드
    int s = 0;
    // state에서 시작 노드를 탐색
    while (s < N && !(state & bit(s))) s++;
    // state에서 s를 시작으로 dfs를 진행
    dfs(state, s);
    // dfs 결과 모든 노드를 탐색했는지 여부를 반환
    return !state;
}

// 한 지역구의 그래프 state를 인자로 받아 두 지역구의 인구수 차를 반환
ui check(int state) {
    // 두 지역의 인구수의 차
    int diff = 0;
    // 두 지역구 중 인접한 구역만으로 이루어져 있지 않은 그룹이 있다면 INF를 반환
    if (!valid(state) || !valid(((1 << N) - 1) & ~state)) return INF;
    // 두 지역구의 인구수 차를 계산한 뒤
    for (int i = 0; i < N; i++) diff += (state & bit(i)) ? val[i] : -val[i];
    // 절댓값 형식으로 반환
    return abs(diff);
}

int main() {
    // len: 각 지역과 인접한 지역의 수, buf: 각 인접한 지역을 입력받을 공간
    int len, buf;
    // ans: 지역구 간의 인구수 차의 최솟값
    ui ans = INF;

    // 문제의 조건을 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", val + i);
    for (int i = 0; i < N; i++) {
        // 각 지역구에서 인접한 지역의 수를 입력받은 뒤
        scanf("%d", &len);
        while (len--) {
            // 각 인접한 지역에 대해
            scanf("%d", &buf);
            // graph에 bitmask 꼴로 저장
            graph[i] |= bit(--buf);
        }
    }

    // 지역구가 두 개로 나뉘는 모든 경우를 검토해 인구수 차의 최솟값을 계산
    for (int i = 1; i < (1 << N) - 1; i++) ans = min(ans, check(i));
    // ans의 기본값은 INF, 즉 0xffffffff이다.
    // 이는 int형으로 나타냈을 때 -1이 되므로 지역구를 둘로 나눌 수 없는 경우
    // int형으로 출력했을 때 -1이 된다.
    printf("%d\n", ans);

    return 0;
}
