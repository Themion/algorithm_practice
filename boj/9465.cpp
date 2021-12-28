#include <iostream>

using namespace std;

#define MAX_N 100000

int max(int a, int b) { return a > b ? a : b; }

int test_case() {
    // 각 스티커의 가중치를 저장할 공간
    char stkr[2][MAX_N];
    // n: 스티커의 열의 개수, buf: 정수를 입력받아 char형 변수에 저장하기 위한 버퍼
    // ans[i % 2][j]: i번째 열까지에 대해 j에 해당하는 점수의 최댓값
    //  j -> 0: i번째 열의 스티커를 사용하지 않음
    //       1: i번째 열의 위쪽 스티커를 사용함
    //       2: i번째 열의 아랫쪽 스티커를 사용함
    int n, buf, ans[2][3] = {{ 0, }};

    // 문제의 조건을 입력받는다
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> buf;
        stkr[i / n][i % n] = buf;
    }

    // 첫 번째 줄의 ans값을 저장한 뒤
    ans[0][1] = stkr[0][0]; ans[0][2] = stkr[1][0];

    // 두 번째 줄부터 모든 줄에 대해
    for(int i = 1; i < n; i++) {
        // 직전 값에서 현재 스티커를 사용 가능한 최댓값을 가져와 최댓값을 갱신
        ans[i % 2][0] = max(ans[!(i % 2)][1], ans[!(i % 2)][2]);
        ans[i % 2][1] = max(ans[!(i % 2)][0], ans[!(i % 2)][2]) + stkr[0][i];
        ans[i % 2][2] = max(ans[!(i % 2)][0], ans[!(i % 2)][1]) + stkr[1][i];
    }
    
    // 마지막 열의 스티커를 사용하지 않는 경우는 최댓값이 아니므로
    // 마지막 열의 스티커를 사용하는 두 경우 중 최댓값을 반환
    return max(ans[!(n % 2)][1], ans[!(n % 2)][2]);
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    // 테스트 케이스의 수를 입력받고 각 테스트 케이스를 실행
    for (cin >> T; T--; ) cout << test_case() << '\n';
    return 0;
}
