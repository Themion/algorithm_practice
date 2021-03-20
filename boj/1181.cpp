#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//단어의 수
	int N;
	cin >> N;

	//각 단어를 저장할 컨테이너
	vector<string> words(N);
	for (int i = 0; i < N; i++)
		cin >> words[i];

	//단어를 글자 수 순으로, 글자 수가 같다면 알파벳 순으로 정렬
	sort(words.begin(), words.end(), [](string a, string b) 
	{
		if (a.size() == b.size())
			for (int i = 0; i < a.size(); i++) if (a[i] != b[i])  return a[i] < b[i];

		return a.size() < b.size();
	});

	//첫번째 단어는 항상 존재하므로 이를 출력
	cout << words[0] << '\n';

	//두번째 단어부터는 이전 단어와 다른 단어일 경우에만 출력
	for (int i = 1; i < N; i++) if (words[i] != words[i - 1]) cout << words[i] << '\n';

	return 0;
}