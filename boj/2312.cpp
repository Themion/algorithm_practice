#include <cstdio>

void test_case() {
    // N: 인수를 계산할 수, cnt: 각 인수의 차수
    int N, cnt;

    // N을 입력받은 뒤
    scanf("%d", &N);

    // 2부터 차례로 인수를 계산
    for (int i = 2; N > 1; i++) {
        // 인수의 차수를 초기화한 뒤
        cnt = 0;
        // N이 i로 나누어 떨어질 때마다
        while (!(N % i)) {
            // N을 i로 나누고 cnt를 1 더함
            N /= i;
            cnt++;
        }
        // cnt가 0이 아니라면 N이 i로 나누어 떨어진다는 뜻이므로
        // 인수 i와 그 차수 cnt를 출력
        if (cnt) printf("%d %d\n", i, cnt);
    }
}

int main() {
    // T: 테스트 케이스의 수
    int T;
    // 테스트 케이스를 입력받은 뒤 각 테스트 케이스의 결과를 출력
    scanf("%d", &T);
    while (T--) test_case();

    return 0;
}
