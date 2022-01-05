#include <iostream>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 해독할 문자열
    string str;

    // 입력받은 문자열이 "END"가 아니라면
    while (getline(cin, str) && str != "END") {
        // 역순으로 출력한 뒤 개행 문자를 출력
        for (auto i = str.rbegin(); i != str.rend(); i++) cout << *i;
        cout << '\n';
    }

    return 0;
}
