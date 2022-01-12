#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // T: 테스트 케이스의 개수, A, B: 더할 두 수
    int T, A, B;

    // 테스트 케이스를 입력받아 각 테스트 케이스의 결과를 출력
    for (cin >> T; T--; ) {
        cin >> A >> B;
        cout << A + B << '\n';
    }

    return 0;
}
