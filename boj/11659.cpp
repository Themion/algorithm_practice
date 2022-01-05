#include <iostream>

using namespace std;

#define MAX_N 100000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 수의 개수, M: 쿼리의 개수, sum[i]: 1번째 수부터 i번째 수까지의 합
    // i, j: 인덱스
    int N, M, sum[MAX_N + 1] = { 0, }, i, j;

    // 수의 개수와 쿼리의 개수를 입력받은 뒤 각 수를 입력받아 합을 sum에 저장
    cin >> N >> M;
    for (i = 1; i <= N; i++) {
        cin >> j;
        sum[i] = sum[i - 1] + j;
    }

    // 각 쿼리마다
    while (M--) {
        // 합을 구할 구간을 입력받은 뒤
        cin >> i >> j;
        // (1부터 j까지의 합) - (1부터 i - 1까지의 합)을 출력
        cout << sum[j] - sum[i - 1] << '\n';;
    }

    return 0;
}
