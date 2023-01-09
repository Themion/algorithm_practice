#include <cstdio>

int main() {
    // XOR을 당할 수
    int A;
    // A에 XOR할 수
    int B;
    // XOR 연산을 진행할 횟수
    int C;
    scanf("%d %d %d", &A, &B, &C);
    // 같은 수를 홀수번 XOR한다면 그 값은 XOR을 한 번 한 값과 같고
    // 같은 수를 짝수번 XOR한다면 그 값은 XOR하지 않은 값과 같다
    printf("%d\n", C % 2 ? A ^ B : A);
    return 0;
}
