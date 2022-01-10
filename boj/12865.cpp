#include <cstdio>

#define MAX_K 100000

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // N: 물건의 개수, K: 버틸 수 있는 무게, W, V: 각 물건의 무게와 가치
    // val[w]: 가방에 무게가 w만큼 차 있을 때 가질 수 있는 가장 큰 가치
    int N, K, W, V, val[MAX_K + 1] = { 0, };
    
    // 각 물건에 대해
    for (scanf("%d %d", &N, &K); N--; ) {
        // 물건의 무게와 가치를 입력받은 뒤
        scanf("%d %d", &W, &V);
        // 현재 물건을 사용했을 때 같은 무게를 사용해
        // 가치의 최댓값을 갱신 가능하다면 갱신
        for (int w = K; w >= W; w--)
            val[w] = max(val[w], val[w - W] + V);
    }

    printf("%d\n", val[K]);

    return 0;
}
