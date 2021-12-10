#include <cstdio>

// A와 B의 최대공약수를 반환
int gcd(int A, int B) {
    if (!B) return A;
    return (A > B) ? gcd(B, A % B) : gcd(A, B % A);
}

// A와 B의 최소공배수는 A * B / (A와 B의 최대공약수)이다
int test_case() {
    // A, B: 최소공배수를 구할 두 수
    int A, B;
    // A와 B를 입력받은 뒤
    scanf("%d %d", &A, &B);
    // A와 B의 곱을 둘의 최대공약수로 나눈 값을 반환한다
    return A * B / gcd(A, B);
}

int main() {
    int T;
    scanf("%d", &T);
    // 각 테스트 케이스마다 정답을 출력한다
    while (T--) printf("%d\n", test_case());

    return 0;
}
