#include <iostream>
#include <map>
#include <string>

using namespace std;

//도감번호, 포켓몬 이름을 모두 한 컨테이너에 저장
map<string, int> s2i;
map<int, string> i2s;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M;
    //포켓몬 이름을 입력받을 공간
    string buf;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> buf;
        i2s[i] = buf;
        s2i[buf] = i;
    }

    //도감번호를 이름으로, 이름을 도감번호로 바꿈
    while (M--)
    {
        cin >> buf;
        if (buf[0] >= 'A' && buf[0] <= 'Z')
            cout << s2i[buf] << '\n';
        else
            cout << i2s[stoi(buf)] << '\n';
    }

    return 0;
}