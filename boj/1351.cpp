#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

// A[i]: 수열 A를 저장할 공간
map<ll, ll> A;
// A[k]를 생성할 때 사용할 두 변수
int P, Q;

// A[idx]가 호출된 적이 없다면 해당 값을 채운 뒤 그 값을 반환한다
ll get(ll idx) {
    if (!A[idx]) A[idx] = get(idx / P) + get(idx / Q);
    return A[idx];
}

int main() {
    // 출력할 값의 인덱스
    ll N;
    // 수열의 시작은 1임이 주어져 있다
    A[0] = 1;
    // 문제의 조건에 따라 A[N}을 계산해 출력한다
    scanf("%lld %d %d", &N, &P, &Q);
    printf("%lld\n", get(N));

    return 0;
}
