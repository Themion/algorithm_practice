#include <iostream>
#include <string>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // str 안의 단어의 개수
    int ans = 1;
    // 문장을 저장할 변수
    string str;

    // getline을 통해 문장을 통째로 입력받은 뒤
    getline(cin, str);
    // 공백의 개수를 세어 ans에 저장
    for (auto c : str) ans += (c == ' ');

    // 시작 혹은 끝이 공백이라면 그만큼을 차감하고 출력
    cout << ans - (str.front() == ' ') - (str.back() == ' ') << '\n';

    return 0;
}
