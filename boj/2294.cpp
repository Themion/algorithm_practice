#include <cstdio>

#define MAX_K 10000

int min(int a, int b) { return a < b ? a : b; }

int main() {
    // n: 동전의 수, k: 만들고자 하는 가치의 크기, coin: 각 동전의 가치
    // cnt[i]: 주어진 동전으로 i원을 만드는 최소의 동전 수
    int n, k, coin, cnt[MAX_K + 1] = { 0, };

    // 동전의 개수와 만들고자 하는 가치를 입력받은 뒤
    scanf("%d %d", &n, &k);

    // 각 동전에 대해
    while (n--) {
        // 동전의 가치를 입력받은 뒤
        scanf("%d", &coin);
        // 동전의 가치가 k보다 크다면 현재 동전으로는 절대 가치 k를 만들 수 없다
        if (coin > k) continue;
        // coin만큼의 가치를 만들 때 동전을 가장 적게 쓰는 방법은
        // 현재 동전 하나만 사용하는 것
        cnt[coin] = 1;
        // 현재 동전보다 더 큰 모든 가치 i에 대해 i - coin만큼의 가치를 만들 수 있다면
        for (int i = coin + 1; i <= k; i++) if (cnt[i - coin])
            // i - coin만큼의 가치에 현재 동전 하나를 더하면 i이므로 이 때의 동전 수를
            // 가치 i를 만들 수 있다면 i의 최솟값과
            // 가치 i를 만들 수 없다면 (i - coin의 최솟값) + 1과 비교해
            // 더 작은 값을 cnt[i]에 저장
            cnt[i] = min(cnt[i] ? cnt[i] : cnt[i - coin] + 1, cnt[i - coin] + 1);
    }

    // cnt[k]가 0이 아니라면 주어진 동전만으로 가치 k를 만들 수 있으므로 그 값을
    // cnt[k]가 0이라면 주어진 동전으로 k를 만드는 데에 실패했으므로 -1을 출력
    printf("%d\n", (cnt[k] ? cnt[k] : -1));

    return 0;
}
