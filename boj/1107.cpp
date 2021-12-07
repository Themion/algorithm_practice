#include <cstdio>

#define MAX_CHN 500'000

int abs(int a) { return a >= 0 ? a : -a; }
int min(int a, int b) { return a < b ? a : b; }

// broken[i]: 버튼 i가 고장났다면 true
bool broken[10];
// N: 타겟 채널, ans: 채널 N으로 이동하는 최소 비용
int N, ans = MAX_CHN;

// 0번 채널로 이동한 것이 아닐 경우
// 버튼을 t번 눌러 현재 채널 K로 이동했을 때 최소 비용을 계산
void brute_force(int K, int t) {
    // 현재 채널에서 채널 N으로의 비용을 기존 최소 비용과 비교
    ans = min(abs(N - K) + t, ans);
    // 현재 채널이 목표 채널보다 크거나 같을 경우 더 버튼을 누를 필요 없다
    if (K >= N) return;
    // 현재 채널에서 숫자 버튼을 추가로 눌러
    // 다른 채널로 이동했을 때의 최소 비용을 기존 최소 비용과 비교
    for (int i = 0; i < 10; i++) if (!broken[i]) brute_force(K * 10 + i, t + 1);
}

int main() {
    // M: 고장난 버튼의 수, buf: 고장난 버튼을 입력받을 버튼
    int M, buf;
    // 문제 조건을 입력받는다
    scanf("%d %d", &N, &M);
    while (M--) {
        // 누를 수 없는 버튼을 broke에서 제거
        scanf("%d", &buf);
        broken[buf] = true;
    }

    // 0번 채널은 재귀로 돌리지 않고 따로 계산
    if (!broken[0]) ans = min(ans, N + 1);
    // 1번 채널부터 가능한 모든 채널에 대해 최소 비용을 계산
    for (int i = 1; i < 10; i++) if (!broken[i]) brute_force(i, 1);
    // 현재 채널에서 이전/다음 채널 버튼만 눌렀을 때의 최소 비용과
    // 브루트포스로 계산한 최소 비용을 비교해 더 작은 값을 출력
    printf("%d\n", min(ans, abs(N - 100)));

    return 0;
}
