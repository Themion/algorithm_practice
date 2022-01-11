#include <cstdio>

// a와 b의 최대공약수를 반환
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    // n, m: 약분할 두 숫자, k: n과 m의 최대공약수
    int n, m, k;
    // n과 m을 입력받은 뒤 k에 n과 m의 최대공약수를 저장
    scanf("%d:%d", &n, &m);
    k = gcd(n, m);
    // n과 m을 k로 나눠 최대한으로 약분한 꼴을 출력
    printf("%d:%d\n", n / k, m / k);
    return 0;
}
