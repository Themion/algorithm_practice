#include <cstdio>

typedef unsigned long long ull;

#define MAX_N 10000
#define MAX_SUM 20000

int main() {
    // N: 학생의 수, A[i]: i번째 학생의 코딩 실력
    int N, A[MAX_N];
    // ans: 합이 0이 되는 3인조의 수, dp[MAX_SUM - k]: 합이 k가 되는 2인조의 수
    ull ans = 0, dp[MAX_SUM * 2 + 1] = { 0, };
    
    // 학생의 수를 입력받은 뒤 각 학생에 대해
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        // 현재 학생의 코딩 실력을 입력받고
        scanf("%d", A + i);
        // 코딩 실력의 합이 현재 학생의 실력의 -1배가 되는 2인조의 수를 ans에 더한 뒤
        ans += dp[MAX_SUM - A[i]];
        // 현재 학생을 포함하는 2인조를 dp에 저장
        for (int j = 0; j < i; j++) dp[MAX_SUM + A[i] + A[j]]++;
    }

    // 코딩 실력의 합이 0이 되는 3인조의 수를 출력
    printf("%lld\n", ans);

    return 0;
}
