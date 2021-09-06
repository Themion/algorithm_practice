#include <algorithm>
#include <cstdio>
#include <tuple>

using namespace std;

typedef long long ll;

int N;
ll liq[5000];
tuple<ll, ll, ll> t = {0, 1, 2};

// sum(): 인자로 세 인덱스를 주면 liq에서 각 인자를 참고, 주지 않는다면 t를 참조
//        liq에서 참조한 세 인덱스를 이용해 값을 찾아 모두 더해 반환
ll sum_(int a, int b, int c) { return liq[a] + liq[b] + liq[c]; }
ll sum_() { return sum_(get<0>(t), get<1>(t), get<2>(t)); }

// 배열에서 p 이후의 인덱스에 한해 투 포인터 실행
void two_pointer(int p)
{
    // l, r: 투 포인터에서 참조할 인덱스
    int l = p + 1, r = N - 1;
    while (l < r)
    {
        // 세 용액의 합이 기존 용액의 합보다 0에 가깝다면 갱신
        if (llabs(sum_(p, l, r)) < llabs(sum_())) t = {p, l, r};

        // 투 포인터 실행
        if (sum_(p, l, r) < 0) l++;
        else r--;
    }
}

int main()
{
    // 용액의 수와 각 용액의 특성값을 입력받은 뒤
    scanf("%d", &N);
    for (int i= 0; i < N; i++) scanf("%lld", liq + i);

    // 특성값을 오름차순으로 정렬
    sort(liq, liq + N);

    // 인덱스 하나를 잡고 투 포인터 실행
    for (int i = 0; i < N; i++) two_pointer(i);

    // 투 포인터 실행 결과를 반환
    printf("%lld %lld %lld\n", liq[get<0>(t)] , liq[get<1>(t)], liq[get<2>(t)]);

    return 0;
}