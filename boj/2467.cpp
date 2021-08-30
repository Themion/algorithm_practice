#include <utility>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef pair<int, int> pair_;

#define MAX_N 100000
#define l first
#define r second

ll liq[MAX_N + 1];

// 정수를 입력받아 그 절댓값을 반환
ll abs(ll n) { return n >= 0 ? n : -n; }
// 합칠 용액의 인덱스를 pair 형태로 입력받아 두 용액을 합친 특성값을 반환
ll sum(pair_ ptr){ return liq[ptr.l] + liq[ptr.r]; }

int main()
{
    // ptr: 투 포인터에서 현재 포인터, ans: 정답 포인터
    pair_ ptr = {1, 1}, ans;

    // 용액의 수와 각 용액의 특성값을 입력
    scanf("%d", &ptr.r);
    for (int i = ptr.l; i <= ptr.r; i++) scanf("%lld", liq + i);

    // 투 포인터의 초기값을 양극단의 값으로 지정
    ans = ptr;
    // 투 포인터 실행
    while (ptr.l < ptr.r)
    {
        // 두 용액을 합쳤을 때 특성값이 기존 특성값보다 작다면 그 포인터쌍을 저장
        if (abs(sum(ptr)) < abs(sum(ans))) ans = ptr;
        // 포인터를 합친 용액의 특성값에 따라 이동
        sum(ptr) > 0 ? ptr.r-- : ptr.l++;
    }

    // 합친 용액의 특성값이 0에 가장 가까운 두 용액의 특성값을 출력
    printf("%lld %lld\n", liq[ans.l], liq[ans.r]);

    return 0;
}