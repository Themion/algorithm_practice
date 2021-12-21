#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 크로아티아 알파벳의 수
    int ans;
    // str: 크로아티아 알파벳의 수를 셀 문자열
    // pat: 두 글자 이상으로 표현되는 크로아티아 알파벳
    string str, pat[8] = {"dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="};

    // 아스키 코드로 표현되는 문자열을 입력받은 뒤 그 길이를 ans에 저장
    cin >> str;
    ans = str.size();

    // 문자열에서 두 글자 이상으로 표현되는 크로아티아 문자열을 찾을 경우
    // ans에 1을 뺀다
    for (int i = 0; i < str.size(); i++) for (auto p : pat)
        ans -= str.substr(i, p.size()) == p;

    // 문자열 안의 크로아티아 알파벳의 수를 출력한다
    cout << ans << '\n';

    return 0;
}
