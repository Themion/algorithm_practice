#include <cstdio>

#define MAX_N 123456

int main() {
    // num[i]: i가 소수라면 false, 아니라면 true
    bool num[MAX_N * 2 + 1] = { true, true, };
    // 베르트랑 공준을 구할 자연수
    int n;
    // sum[i]: 1부터 i까지의 소수의 개수
    short sum[MAX_N * 2 + 1] = { 0, };

    // 2부터 MAX_N까지 모든 수에 대해 에라토스테네스의 체 실행
    for (n = 2; n <= MAX_N; n++) if (!num[n])
        for (int i = n + n; i <= MAX_N * 2; i += n) num[i] = true;

    // sum[n]에 범위 [1, n] 사이의 소수의 개수를 저장
    for (n = 1; n <= MAX_N * 2; n++) sum[n] = sum[n - 1] + !num[n];

    // n이 0이 아닐 때 sum[2 * n] - sum[n],
    // 즉 범위 (n, 2 * n] 사이의 소수의 개수를 출력한다
    while (scanf("%d", &n) && n) printf("%hd\n", sum[2 * n] - sum[n]);

    return 0;
}
