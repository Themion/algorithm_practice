#include <iostream>

using namespace std;

#define MAX_N 100
#define INF 0x3f3f3f3f

// a를 a와 b 중 더 작은 값으로 설정
void set_min(int &a, int b) { a = a < b ? a : b; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // n: 노드의 수, m: 에지의 수, graph[i][j]: i에서 j로 가는 경로의 최소 비용
    int n, m, graph[MAX_N][MAX_N];
    // i, j, k: 인덱스 및 버퍼
    register int i, j, k;

    // 노드와 에지의 수를 각각 입력받은 뒤 graph 초기화
    cin >> n >> m;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) graph[i][j] = i == j ? 0 : INF;

    // 그래프의 에지를 각각 입력받아 각 에지의 비용을 최솟값으로 설정
    while (m--) {
        cin >> i >> j >> k;
        set_min(graph[i - 1][j - 1], k);
    }

    // 플로이드-워셜 실행
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        set_min(graph[i][j], graph[i][k] + graph[k][j]);

    // 그래프 출력
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) 
        cout << (graph[i][j] < INF ? graph[i][j] : 0) << (j == n - 1 ? '\n' : ' ');

    return 0;
}
