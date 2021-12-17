#include <cstdio>

// 유클리드 호제법을 이용해 a와 b의 최대공약수를 계산
int gcd(int a, int b) {
    if (!b) return a;
    return ((a > b) ? gcd(b, a % b) : gcd(a, b % a));
}

int main() {
    // a, b: 입력받을 두 수, c: a와 b의 최대공약수
    int a, b, c;

    // a와 b를 입력받은 뒤 최대공약수를 c에 저장
    scanf("%d %d", &a, &b);
    c = gcd(a, b);
    // 최소공배수는 두 수의 곱에 최대공약수를 나눈 값이므로
    // 최대공약수 c와 최소공배수 a * b / c를 출력
    printf("%d\n%d\n", c, a * b / c);

    return 0;
}
