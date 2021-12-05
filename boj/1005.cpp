#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 1000 + 1
#define len(node) graph[node][0]

// graph[i][j]: j == 0: graph[i]를 짓기 위한 건물의 수 
//              j != 0: graph[i]를 짓기 위한 j번째 건물
short graph[MAX_N][MAX_N];
// N: 건물의 수, D[i]: i번째 건물의 건설 시간
int N, D[MAX_N];

int max(int a, int b) { return a > b ? a : b; }

// node번째 건물을 짓기 위해 걸리는 총 시간을 계산
int dfs(int node) {
    // node번째 건물을 짓기 위한 선행 건물이 남아있다면
    if (len(node)) {
        int pre = 0;
        // 모든 선행 건물을 짓기 위한 총 시간을 계산한 뒤
        while (len(node)) pre = max(pre, dfs(graph[node][len(node)--]));
        // 연산 시간을 최소화하기 위해 node번째 건물의 건설 시간을 배열에 저장
        D[node] += pre;
    }
    // node번째 건물을 짓기 위해 걸리는 총 시간을 반환
    return D[node];
}

int test_case() {
    // K: 건물의 선행 건설 관계의 수
    // X, Y: 건물 Y를 짓기 위해선 건물 X를 먼저 지어야 함
    // W: 건설하고자 하는 건물
    int K, X, Y, W;
    cin >> N >> K;

    // 각 건물의 건설 시간을 입력받으며 선행 건설 관계를 초기화
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
        graph[i][0] = 0;
    }
    // 선행 건설 관계를 입력받는다
    while (K--) {
        cin >> X >> Y;
        graph[Y][++graph[Y][0]] = X;
    }
    // 최종적으로 건설하고자 하는 건물을 입력받는다
    cin >> W;
    // 건물 W를 짓기 위해 걸리는 총 시간을 반환
    return dfs(W);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;
    // 각 테스트 케이스에 대해 정답을 출력한다
    while (T--) cout << test_case() << '\n';

    return 0;
}