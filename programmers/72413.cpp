#include <string>
#include <vector>

using namespace std;

// 노드의 최대 개수가 200개이고 각 에지의 최대 비용은 100000이므로 
// 사용할 수 있는 무한의 최솟값은
// 200개의 에지 * 각 에지의 최대 비용 = 200 * 100000 + 1 = 20000001이다
#define INF 20000001

// a와 b를 비교해 더 작은 값을 a에 저장
void set_min(int &a, int b) { a = a < b ? a : b; }

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    // 최솟값을 구해야 하므로 정답의 초기값을 무한으로 지정
    int answer = INF;
    // m[i][j]: 노드 i에서 노드 j까지 이동할 때의 비용
    int m[201][201];
    
    // 노드 간 이동 비용을 무한으로 초기화
    for (int i = 0; i <= n; i++) fill_n(m[i], n + 1, INF);
    
    // 입력받은 에지의 비용을 m에 저장
    for (auto f : fares) {
        m[f[0]][f[1]] = f[2];
        m[f[1]][f[0]] = f[2];
    }
    
    // 자기 자신으로 이동할 때의 비용은 반드시 0
    for (int i = 1; i <= n; i++) m[i][i] = 0;
    
    // 플로이드-와셜 알고리즘을 이용해
    // 모든 노드에서 모든 노드로의 최소 비용을 계산
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) set_min(m[i][j], m[i][k] + m[k][j]);
    
    // (s -> i) + (i -> a) + (i + b)의 최솟값을 계산
    for (int i = 1; i <= n; i++) 
        set_min(answer, m[s][i] + m[i][a] + m[i][b]);
    
    return answer;
}