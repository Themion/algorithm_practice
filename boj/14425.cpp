#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N: S 안에 든 문자열의 개수, M: S에서 찾을 문자열의 개수
    // ans: S에서 찾은 문자열의 개수
    int N, M, ans = 0;
    // S에 넣거나 S에서 찾을 문자열을 입력받을 공간
    string str;
    // 문자열을 저장하고 검색할 공간
    unordered_set<string> S;

    // N과 M을 입력받은 뒤 중복되지 않는 N개의 문자열을 S에 저장
    for (cin >> N >> M; N--; ) {
        cin >> str;
        S.insert(str);
    }
    // M개의 문자열을 입력받아 각 문자열의 개수를 ans에 저장
    while (M--) {
        cin >> str;
        ans += S.count(str);
    }
    // S에서 찾은 문자열의 개수를 반환
    cout << ans << '\n';

    return 0;
}
