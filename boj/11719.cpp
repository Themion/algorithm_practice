#include <iostream>
#include <string>

using namespace std;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//버퍼로 사용할 string
	string buf;
	//입력을 받을 동안 그대로 출력
	while (getline(cin, buf)) cout << buf << '\n';

    return 0;
}