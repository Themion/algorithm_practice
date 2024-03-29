#include <iostream>
#include <string>
#include <set>

using namespace std;

// s: 듣도 못한 사람의 명단, prt: 듣도 못한 사람 중 보도 못한 사람
set <string> s, prt;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string buf;

    cin >> N >> M;

    //듣도 못한 사람을 입력받은 뒤
    while (N--) {
        cin >> buf;
        s.insert(buf);
    }

    // 보도 못한 사람 중 듣도 못한 사람이 있다면 s에서 제거
    while (M--) {
        cin >> buf;
        if (s.find(buf) != s.end()) prt.insert(buf);
    }

    // 듣도 보도 못한 사람의 명단을 출력
    cout << prt.size() << '\n';
    for (auto p : prt) cout << p << '\n';

    return 0;
}
