#include <cmath>
#include <cstdio>

#define MAX_IDX 1'000'000

// 해당 인덱스의 수가 제곱 ㄴㄴ 수라면 false, 아니라면 true
bool str[MAX_IDX + 1];

int main() {
    // ret: 입력받은 구간 안의 제곱 ㄴㄴ수의 개수
    int ret = 0;
    // min, max: 입력받을 구간
    // end: 입력받은 구간 안에서 가장 큰 제곱수를 만들 수 있는 수
    // bot: 어느 제곱수 n에 대해 k * n이 구간 안에 들어갈 최소 k값
    long long min, max, end, bot;

    // 구간을 입력받은 뒤 가장 큰 제곱수를 구한다
    scanf("%lld %lld", &min, &max);
    end = (long long)(sqrt(max));

    // 모든 제곱근에 대해
    for (long long i = 2; i <= end; i++) {
        // min값을 i^2로 나눈 값부터 시작해서
        bot = min / (i * i);
        // 해당 값에 i^2를 곱한 값이 min보다 작다면 값을 1 올린다
        while ((bot * i * i) < min) bot += 1;

        // 범위 [bot, top] 안의 모든 수 k에 대해 k*(i^2)는 제곱ㄴㄴ수에서 제외
        for (long long k = bot; k <= max / (i * i); k++) 
            str[k * (i * i) - min] = true;
    }

    // 각 수에 대해 해당 수가 제곱 ㄴㄴ수라면 ret에 1씩 더한다
    for (long long i = 0; i <= max - min; i++) if (!str[i]) ret += 1;
    printf("%d\n", ret);

    return 0;
}
