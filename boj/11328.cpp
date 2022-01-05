#include <iostream>

using namespace std;

#define LEN 1000

void count(int cnt[], int add) {
    // 문자열을 입력받을 공간
    char str[LEN + 1];
    // 문자열을 입력받은 뒤
    cin >> str;
    // 각 문자가 나온 만큼 str에 add를 더한다
    for (int i = 0; str[i]; i++) cnt[str[i] - 'a'] += add;
}

bool test_case() {
    // cnt[i]: 두 문자열에서 알파벳 i + 'a'가 나온 횟수의 차
    int cnt[26] = { 0, };
    
    // 첫 번째 문자열에 나온 각 문자의 개수를 세어 cnt에 더한 뒤
    count(cnt, 1);
    // 두 번째 문자열에 나온 각 문자의 개수를 세어 cnt에 빼 각 개수의 차를 계산
    count(cnt, -1);

    // 각 문자가 나온 횟수의 차가 0이 아닌 경우 false를 반환
    for (int i = 0; i < 26; i++) if (cnt[i]) return false;

    // 그렇지 않은 경우 두 번째 문자열을 strfry를 이용해 얻을 수 있으므로 true를 반환
    return true;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    // 테스트 케이스의 수를 입력받고 각 테스트 케이스를 실행
    for (cin >> N, cin.get(); N--; )
        cout << (test_case() ? "Possible" : "Impossible") << '\n';
    return 0;
}
