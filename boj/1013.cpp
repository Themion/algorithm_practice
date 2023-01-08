#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 테스트할 문자열의 개수
    int N;
    // 문자열을 테스트할 정규 표현식
    regex r("^(100+1+|01)+$");
    // 테스트할 문자열을 저장할 공간
    string str;

    // 각 문자열에 대해
    for (cin >> N; N--;) {
        // 문자열을 입력받은 뒤
        cin >> str;
        // 문자열이 정규 표현식에 맞는다면 YES를, 아니라면 NO를 출력
        cout << (regex_match(str, r) ? "YES" : "NO") << '\n';
    }

    return 0;
}
