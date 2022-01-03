#include <cstdio>

int main() {
    // T: 테스트 케이스의 수, A, B: 더할 두 수
    int T, A, B;

    // 테스트 케이스의 수를 입력받은 뒤 각 테스트 케이스에 대해
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        // 더할 두 수를 입력받고 형식에 맞춰 두 수의 합을 출력
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A + B);
    }

    return 0;
}
