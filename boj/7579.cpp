#include <cstdio>

#define MAX_N 100
#define MAX_COST 10000

// mem[i], cost[i]: i번째 앱이 사용하는 메모리와 비활성화 비용
int mem[MAX_N], cost[MAX_N];
// max_mem[cost]: 비용을 cost 만큼 지불하여 확보할 수 있는 최대 메모리
int max_mem[MAX_COST + 1];

void set_max(int &a, int b) { a = a > b ? a : b;  }

int main() {
    // N: 실행중인 앱의 수, M: 확보하고자 하는 메모리 용량
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", mem + i);
    for (int i = 0; i < N; i++) scanf("%d", cost + i);

    // 각 앱에 대해 하나씨 종료한다고 가정한 뒤
    for (int i = 0; i < N; i++)
        // 해당 앱을 종료할 수 있는 모든 비용에 대해
        for (int cost_ = MAX_COST; cost_ >= cost[i]; cost_--)
            // 알려진 최적의 경우에서 잉여 비용으로 현재 앱을 종료할 수 있다면 종료
            set_max(max_mem[cost_], max_mem[cost_ - cost[i]] + mem[i]);

    // N에 비용을 대입하여 확보 가능한 최대 메모리가 M 이상이 되는 최소 비용을 탐색
    for (N = 0; max_mem[N] < M; N++);

    // 최소 비용을 출력
    printf("%d\n", N);

    return 0;
}