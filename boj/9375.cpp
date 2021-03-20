#include <iostream>
#include <string>
#include <map>

using namespace std;

int boj_9375()
{
    string item, kind;  // 의상의 이름과 종류
    map<string, int> m; // 같은 종류의 의상 수
    int N, ret = 1;     // N: 의상의 수, ret: 의상의 조합

    cin >> N;
    while (N--)
    {
        cin >> item >> kind;            // 의상의 이름과 종류를 입력받은 뒤
        m[kind] += (m[kind] == 0) + 1;  // 같은 종류의 의상 수를 업데이트
    }                                   // 벗은 것도 한 종류로 친다

    for (auto part: m) ret *= part.second;  // 의상의 조합을 계산

    return ret - 1; // 아무것도 입지 않은 종류는 세지 않으므로 ret - 1을 반환
}

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) cout << boj_9375() << '\n';

    return 0;
}