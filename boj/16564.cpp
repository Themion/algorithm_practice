#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 1000000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 캐릭터의 수, K: 총 올릴 수 있는 레벨
    // X[i]: i번째 캐릭터의 현재 레벨
    int N, K, X[MAX_N + 1];

    // 문제의 조건을 입력받은 뒤
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> X[i];

    // 캐릭터의 레벨을 정렬하고
    sort(X, X + N);
    // 각 캐릭터에 대해
    for (int i = 1; i < N; i++) {
        // 레벨이 가장 낮은 캐릭터들을 다음 캐릭터까지 올릴 수 없다면
        if (K < (X[i] - X[i - 1]) * i) {
            // 레벨이 가장 낮은 캐릭터들의 레벨에
            // 올릴 수 있는 레벨을 최대한 고르게 분배한 값을 출력하고 종료
            cout << X[i - 1] + (K / i) << '\n';
            return 0;
        }
        // 그렇지 않다면 다음 레벨의 캐릭터의 레벨까지 레벨을 올린다
        else K -= (X[i] - X[i - 1]) * i;
    }

    // 모든 캐릭터의 레벨을 맞춘 뒤에도 K가 남는다면
    // 남은 레벨을 최대한 고르게 분배한 값을 출력하고 종료
    cout << X[N - 1] + (K / N) << '\n';
    return 0;
}
