#include <cstdio>

typedef long long ll;

#define MAX_N 50

template<typename T>
T max(T a, T b) { return a > b ? a : b;}

int main() {
    // N: 나무의 수, C: 한 번 자르는 비용, W: 단위 길이 당 비용
    // wood[i]: 각 나무토막의 길이, len: 팔 수 있는 나무토막의 길이
    int N, C, W, wood[MAX_N] = { 0, }, len = 0;
    // val: 한 나무토막을 가공하여 얻을 수 있는 값
    // cut: 한 나무토막을 자르는 횟수, sum: 팔 수 있는 나무토막의 값의 합
    // ans: 나무토막을 팔아 얻을 수 있는 최대 이익
    ll val, cut, sum, ans = 0;

    // 문제 조건을 입력받는다
    scanf("%d %d %d", &N, &C, &W);
    for (int i = 0; i < N; i++)  {
        scanf("%d", wood + i);
        // 팔 수 있는 나무토막의 최장 길이는 가장 긴 나무토막의 길이와 같다
        len = max(wood[i], len);
    }

    // 팔 수 있는 모든 길이에 대해
    while (len--) {
        sum = 0;
        // 모든 나무토막에 대해
        for (int i = 0; i < N; i++) {
            // 나무토막을 길이 len짜리 나무토막으로 자르려면
            // (wood[i] / len) 번 잘라야 한다
            // 이 때 wood[i]가 len의 배수라면 자르는 횟수를 1 줄일 수 있다
            cut = (wood[i] / len) - !(wood[i] % len);
            // 가공된 나무토막의 총 길이는 wood[i]에서 
            // 자투리 길이 (wood[i] % len)을 뺀 값이다
            // i번째 나무토막을 가공하여 얻을 수 있는 값은
            // (가공된 나무토막의 길이 * 각 토막의 값) - (자른 횟수 * 자르는 값)이다
            val = (wood[i] - (wood[i] % len)) * W - cut * C;
            // 나무토막을 가공하여 이득을 볼 수 있다면 이를 sum에 더한다
            sum += max(val, (ll)0);
        } 
        
        // 최대 이득 갱신
        ans = max(sum, ans);
    }

    // 나무토막으로 얻는 최대 이익을 출력
    printf("%lld\n", ans);

    return 0;
}
