#include <cstdio>

int main() {
    // T: 테스트 케이스의 수, A, B: 더할 두 수
    int T, A, B;

    // 테스트 케이스의 수를 입력받은 뒤 각 테스트 케이스에 대해
    for (scanf("%d", &T); T--; ) {
        // 두 수 A와 B를 입력받아 그 합을 출력
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }

    return 0;
}
