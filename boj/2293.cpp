#include <cstdio>

#define MAX_K 10000

int main() {
    // n: 동전의 수, k: 만들고자 하는 가치의 크기, coin: 각 동전의 가치
    // cnt[i]: 주어진 동전으로 i원을 만드는 경우의 수
    int n, k, coin, cnt[MAX_K + 1] = { 1, };

    // 동전의 개수와 만들고자 하는 가치를 입력받은 뒤
    scanf("%d %d", &n, &k);

    // 0번째부터 i번째 동전을 적절히 사용해 가치 0부터 k까지 만들었을 때
    // i + 1번째 가치 coin에 대해 이전에 만든 가치 0부터 k - coin에
    // 현재 동전을 적절히 섞어 가치 coin부터 k까지 만든 값을 더한다
    while (n--) {
        scanf("%d", &coin);
        // 가치가 작은 순서부터 차례로 순회해 이전 결과를 활용
        for (int i = coin; i <= k; i++) cnt[i] += cnt[i - coin];
    }

    // 가치 k를 만드는 경우의 수를 출력
    printf("%d\n", cnt[k]);

    return 0;
}
