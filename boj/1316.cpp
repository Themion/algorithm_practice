#include <iostream>
#include <string>

using namespace std;

//각 알파벳이 등장했는지 체크
bool cont[26];

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//각 그룹 단어를 저장하는 컨테이너
	string str;
	//tc : 테스트 케이스의 개수
	//cont : 각 알파벳이 등장한 횟수를 저장
	//count : 그룹 단어의 개수를 저장
	int tc, temp, count = 0;
	//i를 이용해서 for문이 정상적으로 끝났는지 break문을 만났는지 판정
	unsigned int i;

	cin >> tc;

	//매 테스트 케이스마다
	for (int t = 0; t < tc; t++)
	{
		//cont와 str를 초기화시켜준다
		fill_n(cont, 26, false);
		cin >> str;

		//알고리즘의 편의를 위해 맨 앞 글자는 두 번 등장하게 만든다
		str = str[0] + str;

		//두 번 등장하는 맨 앞글자를 제외한 모든 글자에 대해
		for (i = 1; i < str.size(); i++)
		{
			//현재 알파벳을 인덱스에 맞게 변형시킨다
			temp = str[i] - 'a';
			//temp가 연속적이지 않은 형태로 한 번이라도 등장했다면 break
			//그렇지 않다면 temp를 등장한 적 있음으로 변경
			if (cont[temp] && (str[i] != str[i - 1])) break;
			else cont[temp] = true;
		}

		//for문이 정상적으로 끝났다면 이 단어를 그룹 단어로 간주, count를 1 올린다
		if (i == str.size()) count += 1;
	}

	//그룹 단어의 개수를 출력
	cout << count << '\n';

	return 0;
}