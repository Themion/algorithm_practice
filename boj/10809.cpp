#include <iostream>
#include <string>

using namespace std;

//26개의 알파벳이 가장 먼저 나온 위치를 저장
int ret[26];

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력받은 문자열을 저장
	std::string str;
    
    //각 알파벳이 아직 등장하지 않았으므로 각 알파벳의 위치를 -1로 초기화한다
    fill_n(ret, 26, -1);

	//scanf로도 string을 입력받을 수 있지만, std::cin이 더 간편하다
	std::cin >> str;

	//string의 맨 마지막 문자를 pop해가며 인덱스의 값을 저장
	while (!str.empty())
	{
		//'a'의 값이 뭔지는 모르지만, 모든 알파벳 소문자는 'a'부터 차례대로 저장되어 있다
		ret[str[str.size() - 1] - 'a'] = str.size() - 1;
		//맨 마지막 문자을 pop하여 직전 문자열에 대해 같은 작업을 반복
		str.pop_back();
	}

	//각 알파벳에 대하여 가장 먼저 나온 인덱스를 저장
	for (auto i : ret)  std::cout << i << ' ';
	//줄을 바꾸어서 출력 종료를 알림
	std::cout << '\n';

    return 0;
}