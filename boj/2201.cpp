#include <cstdio>

typedef long long ll;

#define LEN 87
#define MAX_K 1000000000000000000

int main() {
    // out: 이친수를 저장할 공간, is_print: 출력 여부를 저장할 플래그
    bool out[LEN] = { false, }, is_print = false;
    // 반복문에서 사용할 인덱스
    int i = 2;
    // fib: 피보나치 수를 저장할 공간, K: 찾을 이친수의 순서
    ll fib[LEN] = { 1, 2 }, K;

    // 피보나치 수열을 완성
    do { fib[i] = fib[i - 1] + fib[i - 2]; } while (fib[i++] <= MAX_K);

    // 찾을 이친수의 순서를 입력받은 뒤
    scanf("%lld", &K);

    // 피보나치 수열을 이용해 K번째 이친수를 계산
    for (i = LEN - 1; i >= 0; i--) if (K >= fib[i]) {
        K -= fib[i];
        out[i] = true;
    }

    // 완성한 이친수를 출력
    for (i = LEN - 1; i >= 0; i--) {
        // 가장 큰 자리부터 한 자리씩 확인하며
        is_print |= out[i];
        // 처음으로 1이 나왔을 때부터 출력
        if (is_print) printf("%d", out[i]);
    }

    // 개행 문자를 출력해 출력을 종료
    printf("\n");

    return 0;
}
