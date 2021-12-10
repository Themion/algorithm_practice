#include <cstdio>

typedef long long ll;

// A와 B의 최대공약수를 반환한다
ll gcd(ll A, ll B) {
    if (B == 0) return A;
    else return (B > A) ? gcd(A, B % A) : gcd(B, A % B);
}

int main() {
    // A, B: 최대공약수를 구할 두 수, ans: A와 B의 최대공약수
    ll A, B, ans;
    scanf("%lld %lld", &A, &B);
    
    // A와 B의 최대공약수를 계산해 그만큼 1을 출력한다
    for (ans = gcd(A, B); ans; ans--) printf("1");
    printf("\n");

    return 0;
}
