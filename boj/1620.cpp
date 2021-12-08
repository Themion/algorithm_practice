#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX_N 100000

// 도감번호를 이름으로 전환
string i2s[MAX_N];
// 이름을 도감번호로 전환
unordered_map<string, int> s2i;

int main() {
    // cin, cout 사용 시 필히 사용할 것
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    // 포켓몬 이름을 입력받을 공간
    string buf;

    // 포켓몬의 개수와 문제의 개수를 입력받고
    cin >> N >> M;
    // 각 포켓몬에 대해
    for (int i = 1; i <= N; i++) {
        cin >> buf;
        // 포켓몬에 번호를 할당
        i2s[i] = buf;
        s2i[buf] = i;
    }

    // 도감번호를 이름으로, 이름을 도감번호로 변환
    while (M--) {
        cin >> buf;
        if (buf[0] >= 'A' && buf[0] <= 'Z') cout << s2i[buf] << '\n';
        else cout << i2s[stoi(buf)] << '\n';
    }

    return 0;
}
