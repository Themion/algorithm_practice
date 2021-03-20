#include <cstdio>

int abs(int a) { return a > 0 ? a : -a; }

//(인덱스)번 버튼이 고장났다면 true, 아니라면 false
bool broken[10];

int main()
{
	//m, p: target보다 (m: 작은, p: 높은) 수에서 target까지 도달할 수 있다면 true, 아니라면 false
	bool m = false, p = false;

	//target: 이동하고자 하는 채널 번호
	//cnt[i]: target보다 (i==false: 작은, true: 높은) 수와 target의 차
	//mns, pls: 입력할 숫자. 입력할 숫자 중 입력이 가능하고
	//			target과 가장 가까운 수를 찾는다
	//rank: mns, pls를 구할 때 사용할 변수
	int target, cnt[2] = { 0x3f3f3f3f, 0x3f3f3f3f }, mns, pls, rank;

	//이동할 채널과 고장난 버튼 수, 고장난 버튼을 입력받는다
	scanf("%d\n%d", &target, &rank);
	for (int i = 0; i < rank; i++)
	{
		scanf("%d", &mns);
		broken[mns] = true;
	}

	//m: 0번부터 9번까지 전부 입력할 수 없다면 false
	//p: 1번부터 9번까지 전부 입력할 수 없다면 false
	m = !broken[0];
	for (rank = 1; rank <= 9; rank++) if (!broken[rank]) { m = true; p = true; break; }

	//target부터 1씩 빼 가면서 mns가 입력 가능한 수인지 판단한다
	if (m)
	{
		//mns를 target부터 시작해서
		mns = target; rank = 1;

		//mns가 0 이상일 때 1의 자리 수부터 각 자리수에 대해
		while ((mns >= 0) && (mns / rank > 0))
		{
			//어느 자리의 수가 불가능한 수일 때
			if (broken[(mns / rank) % 10])
			{
				//mns를 1 뺀 뒤 1의 자리 수부터 다시 계산
				rank = 1;
				mns -= 1;
			}
			//어느 자리의 수가 가능한 수일 때 다음 자리 수를 확인한다
			else rank *= 10;
		}

		//mns 채널에서 target까지 이동할 때 +버튼을 (target - mns)번 눌러야 한다
		cnt[0] = target - mns;
		//mns가 0일 때 예외처리
		if (mns == 0)
		{
			//버튼은 항상 한 번 이상 눌린다
			cnt[0] += 1;
			//mns가 0일 때 0번 버튼을 누를 수 없다면 mns는 항상 불가능하다
			if (broken[0]) cnt[0] = 1000000;
		}

		//mns채널로 이동할 때 누르는 버튼 수를 계산
		while (mns > 0)
		{
			cnt[0] += 1;
			mns /= 10;
		}
	}

	//target부터 1씩 더해 가면서 pls가 입력 가능한 수인지 판단한다
	if (p)
	{
		//pls를 target부터 시작해서
		pls = target; rank = 1;

		//pls의 1의 자리 수부터 각 자리수에 대해
		while (pls / rank > 0)
		{
			//어느 자리의 수가 불가능한 수일 때
			if (broken[(pls / rank) % 10])
			{
				//pls를 1 더한 뒤 1의 자리 수부터 다시 계산
				rank = 1;
				pls += 1;
			}
			//어느 자리의 수가 가능한 수일 때 다음 자리 수를 확인한다
			else rank *= 10;
		}

		//pls 채널에서 target까지 이동할 때 -버튼을 (pls - target)번 눌러야 한다
		cnt[1] = pls - target;
		//pls는 항상 target보다 크거나 같으므로 pls가 0일 때 예외처리가 필요하다
		//0 이외의 버튼 중 유효한 버튼이 하나 이상 있으므로 해당 버튼 중 가장 작은 번호를 가진 버튼을 찾는다
		if (cnt[1] == 0) while (broken[cnt[1]++]);

		//pls 채널로 이동할 때 누르는 버튼 수를 계산
		while (pls > 0)
		{
			cnt[1] += 1;
			pls /= 10;
		}
	}

	//mns 채널에서 이동할 때와 pls 채널에서 이동할 때 누르는 횟수 중 작은 수를 택한다
	if (cnt[0] > cnt[1]) cnt[0] = cnt[1];
	//어느 채널로 이동한 뒤 한 채널씩 이동하는 방법과
	//100 채널에서 한 채널씩 이동하는 방법 중 버튼을 누르는 횟수가 적은 방법을 택한다
	if (cnt[0] > abs(target - 100)) cnt[0] = abs(target - 100);

	//버튼을 누르는 가장 적은 횟수를 출력한다
	printf("%d\n", cnt[0]);

    return 0;
}