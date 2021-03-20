#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // N: 비밀번호를 저장할 도메인의 수
    // M: 비밀번호를 가져올 도메인의 수
    int N, M;
    // domain: 도메인, pw: 패스워드
    string domain, pw;
    // 도메인과 비밀번호를 map에 저장
    // unordered_map을 사용하면 메모리와 시간을 절약할 수 있다
    unordered_map<string, string> m;

    cin >> N >> M;
    while(N--)
    {
        // 도메인과 비밀번호를 읽어와 m에 저장
        cin >> domain >> pw;
        m.insert({domain, pw});
    }

    while(M--)
    {
        // 도메인을 읽어와 해당 도메인의 비밀번호를 출력
        cin >> domain;
        cout << m.find(domain)->second << '\n';
    }

    return 0;
}