#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 100

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // N: 카드의 수, M: 딜러가 부른 수, card: 각 카드에 적힌 수
    // ans: 세 카드의 합의 최대치, sum: 임의의 세 카드의 합
    // l, r: 투 포인터에 사용할 인덱스
    int N, M, card[MAX_N], ans = 0, sum, l, r;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", card + i);
    // 투 포인터를 위해 카드를 정렬
    sort(card, card + N);

    // 각 카드에 대해
    for (int i = 0; i < N - 2; i++) {
        // 해당 카드를 무조건 고른 뒤 이후 카드에 대해 투 포인터를 실행
        l = i + 1; r = N - 1;
        sum = card[i] + card[l] + card[r];

        // 투 포인터
        while (l < r) {
            // 합이 M 이하라면 합의 최대치를 갱신
            ans = max(ans, sum * (sum <= M));
            // 합이 M보다 작다면 l을 1 늘린 합을 계산하고
            if (sum < M) sum += card[l + 1] - card[l++];
            // 그렇지 않다면 r을 1 줄인 합을 계산
            else sum += card[r - 1] - card[r--];
        }
    }

    //  M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력
    printf("%d\n", ans);

    return 0;
}
