#include <cstdio>

int main() {
    // r, c: Z수의 좌표, quat: 가중치를 설정할 변수
    int r, c, quat;
    // N: Z수 배열의 크기, ans: 출력값
    unsigned long long N, ans = 1;

    // N, r, c를 입력받는다
    scanf("%lld %d %d", &N, &r, &c);

    // Z수 배열의 크기 N을 실제 배열의 크기로 바꾼 뒤 ans을 0으로 초기화한다
    while (N--) ans *= 2;
    N = ans; ans = 0;

    // 배열 N을 4등분 가능할 때
    while (N > 1) {
        // quat는 (r, c)가 N의 
        // 좌상단에 있으면 0, 우상단에 있으면 1
        // 좌하단에 있으면 2, 우하단에 있으면 3
        quat = 0;
        if (r >= N / 2) { quat += 2; r -= N / 2; }
        if (c >= N / 2) { quat += 1; c -= N / 2; }

        // (r, c)가 속한 사분면 내의 최솟값에 (quat * N * N / 4)만큼 더한다
        ans += quat * N * N / 4;
        // (r, c)가 속한 사분면에 대해 재귀적으로 반복한다
        N /= 2;
    }

    // 재귀가 끝나면 배열 N을 사등분하지 못한다. 즉 N의 크기가 1이 된다
    // 이 때 N의 최솟값은 (r, c)의 값이므로 이를 출력한다
    printf("%lld\n", ans);

    return 0;
}