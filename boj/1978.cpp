#include <cstdio>

#define MAX 1000

// prime[i]: i가 소수라면 false, 아니라면 true
bool prime[MAX + 1];

int main() {
    // N: 입력받을 수의 개수, buf: 각 수를 입력받을 버퍼
    // ans: 입력받은 수 중 소수의 개수
    int N, buf, ans = 0;

    // 0과 1은 소수가 아니다
    prime[0] = prime[1] = true;

    // 2부터 MAX까지 에라토스테네스의 체 실행
    for (int i = 2; i <= MAX; i++) if (!prime[i])
        for (int j = i << 1; j <= MAX; j += i) prime[j] = true;

    // 수의 개수를 입력받는다
    scanf("%d", &N);
    
    // 각 입력받는 수가 소수라면 ans에 1씩 더한다
    while (N--) {
        scanf("%d", &buf);
        ans += !prime[buf];
    }

    // 소수의 개수를 출력한다
    printf("%hd\n", ans);

    return 0;
}
