#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

//만들고자 하는 수열
int ans[100000];

int main()
{
	//q와 s로 ret을 구현할 수 있다면 true
	//그렇지 않다면 false
	bool isCont = true;

	//size : 입력받을 수의 개수
	//buf : 수열을 입력받을 때는 ans에 각 수를 전달하기 위한 버퍼
	//		수열을 큐와 벡터로 구현할 때는 ans의 인덱스
	int size, buf;

	//s, q : 1~size가 저장된 큐 q에서 pop한 값을 스택 s에 push한다
	//		 s를 push하거나 pop하면서 ans를 구현할 수 있는지 확인
	//ret : s에 어떤 값을 push하면 '+'을, pop하면 -를 ret에 push
	stack<int> s;
	queue<int> q;
	queue<char> ret;

	scanf("%d", &size);

	//ans를 만들면서 q에 i + 1을 push
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &ans[i]);
		q.push(i + 1);
	}

	//ans의 인덱스는 0부터 시작
	buf = 0;

	//q와 s로 ans를 구현할 수 있을 때
	while(isCont)
	{
		//두 while문 안에 들어가지 못했다면 q와 s로 ans를 구현하지 못함
		isCont = false;

		//q에서 ans[buf]보다 큰 값을 발견할 때까지
		//q에서 pop한 값을 s에 넣는다
		while (!q.empty() && (q.front() <= ans[buf]))
		{
			isCont = true;

			s.push(q.front());
			q.pop();
			ret.push('+');
		}

		//s.top()과 ans[buf]가 같다면 계속해서 s를 pop하고 ans의 인덱스를 1 늘린다
		while (!s.empty() && (s.top() == ans[buf]))
		{
			isCont = true;

			s.pop();
			buf += 1;
			ret.push('-');
		}
	}

	//buf가 size보다 작다면 구현 도중 실패한 것
	if (buf < size) printf("NO\n");
	//구현에 성공했다면 ret을 출력한다
	else while(!ret.empty())
	{
		printf("%c\n", ret.front());
		ret.pop();
	}

    return 0;
}