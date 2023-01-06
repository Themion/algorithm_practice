#include <cstdio>

#define MAX_N 100000

int main() {
    // 시간 여행이 가능한 길이
    int N;
    // 각 날짜의 주홍코인의 가격
    short prices[MAX_N];
    // 주홍코인으로 실현한 이익의 총합
    int ans = 0;
    // 판매 가능한 주홍코인의 최대 가격
    int max_idx = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%hd", prices + i);

    // 가장 마지막 날의 가격을 판매 가능한 최대 가격으로 설정한 뒤
    max_idx = N - 1;

    // 하루씩 거슬러 올라가며
    for (int i = N - 2; i >= 0; i--) {
        // 최대 가격이 갱신 가능하다면 최대 가격을 갱신
        if (prices[i] > prices[max_idx]) max_idx = i;
        // 그렇지 않다면 코인을 구매한 뒤
        // 가장 가까운 최대 가격 지점에서 주홍 코인을 판매
        else ans += prices[max_idx] - prices[i];
    }

    // 실현한 총 이익을 출력
    printf("%d\n", ans);

    return 0;
}
