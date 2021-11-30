#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // dp[l]: S.substr(0, l)을 A의 집합만으로 완성시킬 수 있다면 true
    //          이 때 S.substr(0, 0)은 어떤 경우에서도 만들 수 있다고 가정
    bool dp[101] = { true, };
    // N: A의 원소 개수
    // s_size: S의 길이 (S.size()의 호출 최소화)
    // idx: dp의 이전 값을 확인할 때 사용할 인덱스
    int N, s_size, idx;
    // S: A의 부분집합으로 완성시킬 문자열
    // A: S를 완성시키기 위해 주어진 문자열의 집합
    string S, A[100];

    // 주어진 조건을 입력받은 뒤
    cin >> S >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    // S의 크기를 변수에 별도로 저장
    s_size = S.size();

    // dp를 활용해 S를 만들 수 있는지 검토
    for (int l = 1; l <= s_size; l++) for (int i = 0; i < N; i++) {
        // A[i]보다 작은 S의 부분 문자열은 검토하지 않는다
        if (l < A[i].size()) continue;

        // 부분 문자열에서 A[i]를 제거한 만큼의 길이
        idx = l - A[i].size();
        // 부분 문자열의 마지막에 A[i]가 존재하고,
        // 또 마지막의 A[i]를 제거한 부분 문자열을 만들 수 있다면
        // 길이가 l 부분 문자열을 만들 수 있다고 간주
        if (dp[idx] && S.substr(idx, A[i].size()) == A[i]) dp[l] = true;
    }

    // 길이가 s_size인 부분 문자열, 즉 전체 문자열을 만들 수 있는지 여부를 출력
    cout << (int)dp[s_size] << '\n';

    return 0;
}