#include <iostream>
#include <string>

using namespace std;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//str:: 매 줄마다 입력받을 문자열을 공백 포함해서 저장한다
	string str;
	getline(cin, str);

	//str에 "END"가 들어오기 전까지는 문자열을 뒤집어서 출력한다
	//str에 "END"가 들어오면 프로그램 종료
	while (str != "END")
	{
		for (int i = str.size() - 1; i >= 0; i--) cout << str[i];
		cout << '\n';
		getline(cin, str);
	}

    return 0;
}