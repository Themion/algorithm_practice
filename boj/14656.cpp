#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 학생의 수, num: 각 학생의 번호, ans: 맞을 학생의 수
    int N, num, ans = 0;
    // 학생의 수를 입력받은 뒤 각 학생에 대해
    cin >> N;
    for (int i = 1; i <= N; i++) {
        // 학생의 번호를 입력받고 번호와 순서가 다른 경우 ans에 1을 더한다
        cin >> num;
        ans += i != num;
    }
    // 빠따로 맞는 학생의 수를 출력
    cout << ans << '\n';

    return 0;
}
