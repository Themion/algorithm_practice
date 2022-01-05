#include <iostream>

using namespace std;

typedef long long ll;

#define MAX_N 1000000

// 각 테스트 케이스를 입력받아 정답을 반환
ll test_case() {
    // 주가 배열의 길이
    int N;
    // val[i]: i번째 날의 주가, max: 팔았을 때 최대 이익을 볼 수 있는 주가
    short val[MAX_N] = { 0, }, max = 0;
    // ret: 실현손익
    ll ret = 0;

    // 주가 배열을 입력받은 뒤
    cin >> N;
    for (int i = 0; i < N; i++) cin >> val[i];
    // 마지막 날부터 역순으로
    for (int i = N - 1; i >= 0; i--) {
        // 주가의 최대치를 발견한다면 매도일을 i번째 날로 지정
        if (max < val[i]) max = val[i];
        // 그렇지 않다면 주식을 사 지정한 매도일에 주식을 매도
        else ret += max - val[i];
    }

    // 실현손익을 반환
    return ret;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    // 테스트 케이스의 수를 입력받고 각 테스트 케이스의 정답을 출력
    for (cin >> T; T--; ) cout << test_case() << '\n';
    return 0;
}
