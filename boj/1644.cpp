#include <cstdio>
#include <queue>

using namespace std;

#define MAX_N 4000000

// chk[i]: i가 소수라면 false, 아니라면 true
bool chk[MAX_N + 1] = { false, };
// 연속합의 범위를 이동시키기 위한 소수의 큐
queue<int> prime;

int main() {
    int N, sum = 0, ans = 0;
    scanf("%d", &N);

    // 소수를 구하면서 연속합을 N과 비교
    for (int i = 2; i < MAX_N; i++) if (!chk[i]) {
        // 에라토스테네스의 체
        for (int i_ = i; i_ < MAX_N; i_ += i) chk[i_] = true;

        // sum에 현재 소수 i를 더한 뒤 sum에서 뺄 소수 목록의 맨 뒤에 i를 추가
        sum += i;
        prime.push(i);

        // sum이 N보다 작아지도록 소수를 차례로 뺄셈
        while (sum > N)  {
            sum -= prime.front();
            prime.pop();
        }

        // 소수의 연속합으로 N을 만드는 데에 성공했다면 ans에 1을 더한다
        ans += (sum == N);
    }

    // 소수의 연속합이 N인 연속합의 개수를 출력
    printf("%d\n", ans);

    return 0;
}
