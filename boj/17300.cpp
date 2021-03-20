#include <cstdio>

int abs(int i) { return i > 0 ? i : -i; }

int main()
{
	//input: 패턴을 순서대로 저장한다
	//cnt: 패턴에 쓰인 노드의 수를 입력받는다
	//diff[i]: 각 노드 간의 (i==0: 수직, 1:수평) 방향으로의 차
	int input[9], cnt, diff[2];
	//chk[i]: i번 노드가 이미 등장했다면 true, 아니라면 false
	//done[i]: i번 노드가 가능한 노드라면 true, 아니라면 false
	bool chk[9] = { false, }, done[9] = { false, };

	//패턴을 입력받는다
	//이 때 패턴 안에 중복된 수가 들어오면 해당 패턴은 잘못된 패턴
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++)
	{
		scanf("%d", &input[i]);
		input[i] -= 1;

		if (chk[input[i]])
		{
			printf("NO\n");
			return 0;
		}

		chk[input[i]] = true;
	}

	//패턴의 맨 첫번째 노드는 항상 가능하다
	done[input[0]] = true;

	//패턴의 두 번째 노드부터 모든 노드에 대해
	for (int i = 1; i < cnt; i++)
	{
		//직전 노드와의 차를 구한다
		diff[0] = abs((input[i] % 3) - (input[i - 1] % 3));
		diff[1] = abs((input[i] / 3) - (input[i - 1] / 3));

		//좌표차가 0이거나 2인 부분이 있다면
		if ((diff[0] % 2 == 0) && (diff[1] % 2 == 0))
		{
			//두 노드 사이에 끼인 노드가 아직 등장한 적 없다면
			//해당 패턴은 잘못된 패턴
			diff[0] = (input[i] + input[i - 1]) / 2;
			if (!done[diff[0]])
			{
				printf("NO\n");
				return 0;
			}
		}

		//현재 노드는 가능한 노드이므로 이를 표시한다
		done[input[i]] = true;
	}

	//모든 노드가 가능한 노드이므로 YES를 출력한다
	printf("YES\n");

    return 0;
}