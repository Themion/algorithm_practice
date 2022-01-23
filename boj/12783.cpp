#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 1000000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N: 수열의 길이, A: 각 수열의 성분
    // lis: 가장 긴 증가하는 부분 수열, len: lis의 길이
    int N, A, lis[MAX_N] = { 0, }, len = 0;

    // 각 수열의 성분에 대해
    for (cin >> N; N--; ) {
        // 각 수열의 성분을 입력받고
        cin >> A;
        // 증가하는 부분 수열 lis이 비었거나 A가 lis의 마지막 값보다 크다면
        // lis의 맨 뒤에 A를 추가
        if (!len || lis[len - 1] < A) lis[len++] = A;
        // 그렇지 않다면 lis에서 A보다 작은 값 중 가장 큰 값을 A로 변경
        // 부분 수열의 순서에는 영향을 미치지만 부분 수열의 길이에는 영향을 주지 않음
        else *lower_bound(lis, lis + len, A) = A;
    }

    // 가장 긴 증가하는 부분 수열의 길이를 출력
    cout << len << '\n';

    return 0;
}
