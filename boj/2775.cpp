#include <cstdio>

#define MAX_K 14

// apart[k][n]: k층 n호에 사는 거주민의 수
int apart[MAX_K + 1][MAX_K + 1];

int dp(int k, int n) {
    // 아직 해당 방의 거주민 수를 알아내지 못했다면
    if (!apart[k][n]) {
        // 0층인 경우에는 호 수만큼 사람이 살고 있고
        if (k == 0) apart[k][n] = n;
        // 그렇지 않은 경우는 아파트 규칙에 맞게 거주민 수를 유추한다
        else for (int i = 1; i <= n; i++) apart[k][n] += dp(k - 1, i);
    }

    // 거주민 수를 반환한다
    return apart[k][n];
}

int main() {
    // T: 테스트 케이스의 수, K, N: 아파트의 층과 호 수
    int T, K, N;
    scanf("%d", &T);

    // 주어지는 값이 층과 호 수 뿐이므로 테스트 케이스 이전에 계산해 계산량을 줄인다
    for (N = 1; N <= MAX_K; N++) dp(MAX_K, N);

    // 각 테스트 케이스에 대해
    while (T--) {
        // 거주민 수를 알고자 하는 방의 층과 호 수를 입력받은 뒤
        scanf("%d\n%d", &K, &N);
        // 동적 계획법을 이용해 이를 계산한다
        printf("%d\n", apart[K][N]);
    }

    return 0;
}
