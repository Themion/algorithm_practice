#include <cstdio>

#define MOD 42

int main() {
    bool mod[MOD] = { false, };
    int buf, ans = 0;

    // 수를 열 번 입력받은 뒤
    for (int i = 0; i < 10; i++) {
        scanf("%d", &buf);
        // 해당 수를 42로 나눈 나머지가 나옴을 표시한다
        mod[buf % MOD] = true;
    }

    // 서로 다른 나머지가 나온 횟수를 출력
    for (int i = 0; i < MOD; i++) ans += mod[i];
    printf("%d\n", ans);
    
    return 0;
}
