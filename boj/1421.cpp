#include <cstdio>

typedef long long ll;

int main()
{
    // N: 나무의 수, C: 한 번 자르는 비용, W: 단위 길이 당 비용
    // wood[i]: [0, 50] -> 각 나무토막의 길이, 51 -> 최장 나무토막의 길이
    int N, C, W, wood[51] = { 0, };
    ll ans = 0;

    scanf("%d %d %d", &N, &C, &W);
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", wood + i);
        if (wood[50] < wood[i]) wood[50] = wood[i];
    }

    // 팔 수 있는 모든 길이에 대해
    for (int len = 1; len <= wood[50]; len++) 
    {
        // sum: 팔 수 있는 나무토막의 값의 합
        // val: 한 나무토막을 가공하여 얻을 수 있는 값
        // cut: 한 나무토막을 자르는 횟수
        ll sum = 0, val, cut;

        // 모든 나무토막에 대해
        for (int i = 0; i < N; i++)
        {
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
            if (val > 0) sum += val;
        } 
        
        // 최대 이득 갱신
        if (ans < sum) ans = sum;
    }

    printf("%lld\n", ans);

    return 0;
}