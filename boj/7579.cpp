#include <cstdio>

#define MAX_N 100
#define MAX_COST 10000

int max(int a, int b) { return a > b ? a : b;  }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    // N: 실행중인 앱의 수, M: 확보하고자 하는 메모리 용량
    // mem[i]: i번째 앱이 사용하는 메모리
    // cost[i]: i만큼의 비용을 소모해 얻을 수 있는 최대 메모리
    // c: 각 앱의 종료 비용, ans: 메모리를 M 이상 얻기 위해 필요한 최소 비용
    int N, M, mem[MAX_N], cost[MAX_COST + 1] = { 0, }, c, ans = MAX_COST;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", mem + i);

    // 각 앱에 대해서
    for (int i = 0; i < N; i++) {
        // 앱의 종료 비용을 입력받은 뒤
        scanf("%d", &c);
        // c보다 크거나 같은 각 종료 비용 c_에 대해
        for (int c_ = MAX_COST; c_ >= c; c_--) {
            // c_ - c만큼의 종료 비용으로 얻을 수 있는 메모리에
            // 현재 엡을 종료해 얻을 수 있는 메모리를 더한 값을
            // 기존 c_만큼의 종료 비용과 비교해 갱신
            cost[c_] = max(cost[c_], cost[c_ - c] + mem[i]);
            // 갱신해 얻은 잉여 메모리가 M 이상이라면 ans를 갱신
            if (cost[c_] >= M) ans = min(ans, c_);
        }
    }

    // 최소 비용을 출력
    printf("%d\n", ans);

    return 0;
}
