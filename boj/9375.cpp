#include <iostream>
#include <map>
#include <string>

using namespace std;

int test_case() {
    // N: 의상의 수, ret: 의상의 조합
    int N, ret = 1;
    // m[kind]: kind 종류의 의상의 개수
    map<string, int> m;
    // 의상의 이름과 종류
    string name, kind;

    for (cin >> N; N--; ){
        // 의상의 이름과 종류를 입력받은 뒤
        cin >> name >> kind;
        // 입지 않은 것도 한 종류로 계산하여 같은 종류의 의상 수를 업데이트
        m[kind] += (m[kind] == 0) + 1;
    }

    // 각 종류의 의상의 개수를 모두 곱해 조합의 개수를 저장
    for (auto k: m) ret *= k.second;

    // 아무것도 입지 않은 종류는 세지 않으므로 ret - 1을 반환
    return ret - 1;
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
