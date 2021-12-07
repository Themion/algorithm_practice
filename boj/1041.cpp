#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
    // N : 만들 정육면체의 한 변의 길이, side: 각 면의 값
    int N, side[6];
    //정육면체를 만들었을 때 각 면의 가중치의 합
    ll ans = 0;

    // N과 기본 정육면체를 입력받는다
    scanf("%d", &N);
    for (int i = 0; i < 6; i++) scanf("%d", side + i);
    // N > 1이면 각 정육면체에서 사용되는 면은 최대 3개이다

    if (N > 1) {
        // 서로 마주한 면들 중 값이 더 작은 면만 사용
        for (int i = 0; i < 3; i++) side[i] = min(side[i], side[5 - i]);
        // 세 값을 오름차순으로 정렬
        sort(side, side + 3);

        // 여섯 면의 점수를 모두 더한 뒤
        ans += 6 * (ll)(N - 2) * (ll)(N - 2) * (ll)side[0];
        ans += 12 * (ll)(N - 2) * (ll)(side[0] + side[1]);
        ans += 8 * (ll)(side[0] + side[1] + side[2]);
        // 밑면의 점수를 뺀다
        ans -= (ll)(N - 2) * (ll)(N - 2) * (ll)side[0];
        ans -= 4 * (ll)(N - 2) * (ll)side[1];
        ans -= 4 * (ll)side[2];
    }

    // N == 1이면 가려지는 건 단 한 면 뿐
    else {
        // ans에 모든 면의 값을 더하면서 가장 큰 면의 값을 N에 저장
        for(int i = 0; i < 6; i++) {
            ans += side[i];
            N = max(N, side[i]);
        }
        // 모든 면의 값의 합에서 가장 큰 면의 값을 뺀다
        ans -= N;
    }

    // 가중치의 합을 출력한다
    printf("%lld\n", ans);

    return 0;
}
