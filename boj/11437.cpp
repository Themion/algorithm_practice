#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned short us;

#define MAX_N 50000

// N: 노드의 개수, parent[i]: i번 노드의 부모 노드, depth[i]: i번 노드의 깊이
us N, parent[MAX_N + 1] = { 0, 1, }, depth[MAX_N + 1];
// v[i]: i번 노드와 연결된 노드
vector<us> v[MAX_N + 1];

void swap(int &a, int &b) { int t = a; a = b; b = t; }

// 노드 p를 부모 노드로 삼는 노드의 부모 노드와 깊이를 설정
void dfs(int p) {
    // p에 연결된 노드 중 아직 부모 노드가 없는 노드에 대해
    for (auto i : v[p]) if (!parent[i]) {
        // 부모 노드를 p로, 깊이를 노드 p의 깊이 + 1로 설정한 뒤
        parent[i] = p;
        depth[i] = depth[p] + 1;
        // 노드 i에 연결된 노드가 두 개 이상이라면 dfs 실행
        if (v[i].size() > 1) dfs(i);
    }
}

// 두 노드 a, b를 입력받아 두 노드의 LCS를 출력
us test_case() {
    // LCS를 찾을 두 노드
    us a, b;

    // 노드 a, b를 입력받은 뒤
    scanf("%hu %hu", &a, &b);

    // a와 b의 깊이를 맞춰주고
    while (depth[a] < depth[b]) b = parent[b];   
    while (depth[a] > depth[b]) a = parent[a];
    // 부모가 같을 때까지 a와 b를 각각의 부모로 설정
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    
    //  입력받은 두 노드의 LCS를 반환
    return a;
}

int main() {
    // M: LCS를 찾을 쿼리의 수, a, b: 그래프를 입력받을 때 사용할 변수
    us M, a, b;

    // 문제의 조건을 입력받아 그래프로 변환
    scanf("%hu", &N);
    for (int i = 1; i < N; i++) {
        scanf("%hu %hu", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 각 노드의 부모 노드와 깊이를 설정한 뒤
    dfs(1);

    // 쿼리의 개수를 입력받고 각 쿼리의 결과를 출력
    for (scanf("%hu", &M); M--; ) printf("%d\n", test_case());

    return 0;
}

/* #include <cstdio>
#include <vector>

using namespace std;

#define MAX_N 50000
#define LOG_N 16

int N, parent[MAX_N + 1][16] = { { 0 }, { 1 }, }, depth[MAX_N + 1];
vector<int> v[MAX_N + 1];

void swap(int &a, int &b) { int t = a; a = b; b = t; }

void dfs(int p, int d) {
    depth[p] = d;
    for (auto i : v[p]) if (!parent[i][0]) {
        parent[i][0] = p;
        dfs(i, d + 1);
    }
}

void set_parent() {
    for (int d = 1; d < LOG_N; d++) for (int n = 1; n <= MAX_N; n++) 
        parent[n][d] = parent[parent[n][d - 1]][d - 1];
}

int test_case() {
    int a, b, jump = LOG_N - 1;

    scanf("%hu %hu", &a, &b);

    if (depth[a] < depth[b]) swap(a, b);
    for (int i = LOG_N - 1; i >= 0; i--) if (depth[a] - depth[b] >= (1 << i))
        a = parent[a][i];

    if (a == b) return a;

    for (int i = LOG_N - 1; i >= 0; i--) if (parent[a][i] != parent[b][i]) {
        a = parent[a][i];
        b = parent[b][i];
    }
    
    return parent[a][0];
}

int main() {
    int M, a, b;

    scanf("%hu", &N);
    for (int i = 1; i < N; i++) {
        scanf("%hu %hu", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, depth[1] + 1);
    set_parent();

    for (scanf("%hu", &M); M--; ) printf("%d\n", test_case());

    return 0;
} */