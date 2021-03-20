#include <algorithm>
#include <cstdio>

using namespace std;

#define INF 0x3f3f3f3f

int N, M, W;
// 중복되는 에지 중 비용이 가장 적은 에지만 저장하여 사용
int map[500][500];

void set_min(int &a, int b) { a = a < b ? a : b; }

bool boj_1865()
{
    int a, b, c;
    scanf("%d %d %d", &N, &M, &W);

    // 각 노드 간의 거리를 무한으로 초기화
    for (int i = 0; i < N; i++) 
    {
        std::fill_n(map[i], N, INF);
        map[i][i] = 0;
    }

    // 각 에지를 입력받아 값이 가장 작은 것들만 사용
    for (int i = 0; i < M + W; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        // 도로를 모두 입력받은 뒤에는 웜홀을 입력받는다
        if (i >= M) c = -c;
        set_min(map[--a][--b], c);
        if (i < M) set_min(map[b][a], c);
    }

    // 플로이드-워셜 알고리즘으로 최소 비용 계산
    for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            set_min(map[i][j], map[i][k] + map[k][j]);

    // 비용이 감소하는 사이클의 존재 여부를 반환
    for (int i = 0; i < N; i++) if (map[i][i] < 0) return true;
    return false;
} 

int main()
{
    int TC;
    scanf("%d", &TC);

    // 사이클 탐색을 TC회만큼 반복
    while (TC--) printf("%s\n", boj_1865() ? "YES" : "NO");

    return 0;
} 