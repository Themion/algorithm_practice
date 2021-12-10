#include <iostream>

using namespace std;

#define MAX_N 100000

int min(int a, int b) { return a < b ? a : b; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 배열의 길이, S: 목표 연속합의 최소 크기
    // l, r: 투 포인터에 쓸 인덱스, sum: 투 포인터로 구한 연속합
    // ans: 크기가 S 이상인 연속합의 최소 길이
    int N, S, arr[MAX_N], l = 0, r = 1, sum, ans = MAX_N + 1;

    // 문제의 조건을 입력받은 뒤
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];
    // 연속합을 배열의 첫 성분으로 초기화
    sum = arr[0];

    // 투 포인터 실행
    while (l < N) {
        // 연속합이 S 미만이면서 더할 성분이 있다면 연속합 오른쪽의 성분을 더한다
        if (sum < S && r < N) sum += arr[r++];
        // 그렇지 않다면
        else {
            // 연속합이 S 이상일 때 연속합의 최소 길이를 갱신
            if (sum >= S) ans = min(ans, r - l);
            // 연속합의 맨 왼쪽 수를 제거
            sum -= arr[l++];
        }
    }
    
    // 조건을 만족하는 부분합을 찾았다면 그 길이를, 아니라면 0을 출력
    cout << (ans < MAX_N + 1 ? ans : 0) << '\n';

    return 0;
}
