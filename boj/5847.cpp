#include <cstdio>
#include <vector>

using namespace std;

#define MAX_N 10000

// visit[i]: dfs에서 노드 i를 방문했다면 true, 아니라면 false 
bool visit[MAX_N];
// T[i]: i번째 소의 우유를 짜는 데에 걸리는 시간
int T[MAX_N];
// rule[i]: i번째 소의 우유를 짜기 전에 우유를 짜야 할 소의 집합
vector<int> rule[MAX_N];

int max(int a, int b) { return a > b ? a : b; }

// node번째 소의 우유를 짜는 시간을 계산
int dfs(int node) {
    // 현재 소보다 보다 먼저 우유를 짜야 할 소들의 우유를 짜는 데에 걸리는 총 시간
    int before = 0;
    // 현재 소의 우유 짜는 시간을 아직 계산하지 않았다면
    if (!visit[node]) {
        // 현재 소보다 보다 먼저 우유를 짜야 하는 소들의 우유 짜는 시간을 계산해
        // 그 최댓값을 before에 저장
        for (auto n : rule[node]) before = max(before, dfs(n));
        // 현재 소의 우유 짜는 시간을 계산했음을 표시
        visit[node] = true;
    }
    // 현재 소의 우유를 짜는 시간과
    // 먼저 우유를 짜야 할 소들의 우유짜는 총 시간을 더한 값을 반환
    return T[node] += before;
}

int main() {
    // N: 소의 마리 수, M: 제약의 수, A, B: 제약 A -> B
    // ans: 모든 소의 우유를 짜는 데에 걸리는 총 시간
    int N, M, A, B, ans = 0;
    
    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%u", T + i);
    while (M--) {
        scanf("%d %d", &A, &B);
        rule[--B].push_back(--A);
    }

    // 각 소의 우유짜는 시간을 계산해 그 최댓값을 출력
    for (int i = 0; i < N; i++) ans = max(ans, dfs(i));
    printf("%u\n", ans);

    return 0;
}
