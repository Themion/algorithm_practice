#include <cstdio>

#define SIZE 10000

// prime[i]: i가 소수라면 false, 아니라면 true
bool prime[SIZE + 1] = { 1, 1, };

void test_case() {
    // n: 골드바흐 파티션을 찾을 수, ans: 골드바흐 파티션에서 값이 작은 소수
    int n, ans;

    // 문제의 조건을 입력받는다
    scanf("%d", &n);

    // n / 2부터 골드바흐 파티션을 만족하는 두 수 ans와 n - ans를 찾는다
    ans = n / 2;
    while (prime[ans] || prime[n - ans]) ans--;

    // 골드바흐 파티션을 오름차순으로 출력
    printf("%d %d\n", ans, n - ans);
}

int main() {
    // T: 테스트 케이스의 수
    int T;

    // 에라토스테네스의 체 실행
    for (int i = 2; i < SIZE; i++) if (!prime[i])
        for (int j = i + i; j <= SIZE; j += i) prime[j] = true;

    // 테스트 케이스의 수를 입력받고 각 테스트 케이스를 실행
    for (scanf("%d", &T); T--; ) test_case();

    return 0;
}
