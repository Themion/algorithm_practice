#include <iostream>

using namespace std;

typedef __int64_t ll;

#define LEN 1000000

// N: 배열의 크기, M: 배열 갱신 횟수, K: 배열 구간합 연산 횟수
int N, M, K;
// 입력받은 배열의 fenwick tree화
ll fenwick[LEN + 1] = { 0, };

// 배열의 idx번째 성분을 val만큼 증가
void set(int idx, ll val) {
    // fenwick 갱신
    while (idx < N) {
        fenwick[idx] += val;
        idx += idx & -idx;
    }
}

// array의 [1, idx] 구간의 부분합을 fenwick을 이용해 계산
ll get(int idx) {
    // 구간합을 저장할 변수
    ll ret = 0;
    
    // fenwick을 이용해 부분합 계산
    while (idx) {
        ret += fenwick[idx];
        idx -= idx & -idx;
    }

    return ret;
}

int main() {
    // 빠른 입출력을 위해 사용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c;
    cin >> N >> M >> K;
    
    // array에 값 a를 넣는 행위는 array의 값을 (a - 0)으로 갱신하는 것과 같다
    for (int i = 1; i <= N; i++) {
        cin >> a;
        set(i, a);
    }

    // 갱신과 부분합 연산을 섞어서 진행
    for (int i = 0; i < M + K; i++) {
        // 명령 입력
        cin >> a >> b >> c;
        // 명령이 갱신 명령이라면 배열의 b번째 성분을 c로 갱신
        if (a == 1) set(b, c - get(b) + get(b - 1));
        // 명령이 부분합 명령이라면 부분합 [b, c] = [1, c] - [1, b - 1]을 출력
        else cout << get(c) - get(b - 1) << '\n';
    }

    return 0;
}
