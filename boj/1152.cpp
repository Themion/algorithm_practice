#include <iostream>
#include <string>

using namespace std;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//문자열을 입력받을 string 변수
	string input;
	getline(cin, input);

	//단어가 공백만으로 이루어지지 않았다면 적어도 하나의 단어가 존재한다
	int count = 1;

	//문장 앞뒤로 존재하는 공백을 모두 제거
	while (!input.empty() && (input.at(0) == ' '))
		input.erase(0, 1);
	while (!input.empty() && (input.at(input.size() - 1) == ' '))
		input.erase(input.size() - 1, 1);

	//만약 input이 비었다면 단어가 존재하지 않으므로 count는 0이다
	if (input.empty()) count = 0;

	//문장에 존재하는 공백의 수 만큼 count를 더한다
	for (unsigned int i = 0; i < input.size(); i++) if (input.at(i) == ' ') count += 1;

	//count를 출력한다
	cout << count << '\n';

	return 0;
}