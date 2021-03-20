#include <iostream>
#include <string>

using namespace std;

//na, nb : a와 b를 각 자리수별로 나누어 저장
//ret : 출력할 결과를 저장한다
int na[10001], nb[10001];

int main()
{
	//cin, cout 사용 시 필히 사용할 것
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//두 수 a, b를 차례로 입력받는다
    string a, b;
	cin >> a >> b;

	//a가 음수라면 이를 표시하고 a를 양수처럼 사용한다
	int index_a = 0, isMin_a = 1;
	if (a[0] == '-') isMin_a = -1;

	//양수 a를 각 자리수별로 나누어 na에 저장
	//a가 사실 음수라면 각 자리수에 -1을 곱해 음수임을 표시
	while (!(a.empty()) && !((a.size() == 1) && (a[0] == '-')))
	{
		na[index_a] = atoi(&a[a.size() - 1]) * isMin_a;
		a.pop_back();
		index_a += 1;
	}

	//b가 음수라면 이를 표시하고 b를 양수처럼 사용한다
	int index_b = 0, isMin_b = 1;
	if (b[0] == '-') isMin_b = -1;

	//양수 b를 각 자리수별로 나누어 nb에 저장
	//b가 사실 음수라면 각 자리수에 -1을 곱해 음수임을 표시
	while ((!b.empty()) && !((b.size() == 1) && (b[0] == '-')))
	{
		nb[index_b] = atoi(&b[b.size() - 1]) * isMin_b;
		b.pop_back();
		index_b += 1;
	}

	//a와 b중 자리수가 더 큰 수의 자리수를 저장
	int size = (index_a > index_b) ? index_a : index_b;

	//b의 자리수가 a보다 크다면
	if (index_b > index_a)
	{
		//a와 b를 스왑하여 a의 절댓값이 b의 절댓값보다 크게 한다
		swap(na, nb);
		swap(index_a, index_b);
		swap(isMin_a, isMin_b);
	}

	//a의 자리수가 b와 같다면
	else if (index_b == index_a)
	{
		//a와 b의 각 자리 수를 비교하여 a와 b의 대소 판단
		int cond;

		for (int i = size - 1; i >= 0; i--)
		{
			//na의 i자리 수가 nb의 i자리 수보다 작다면 음수, 크다면 양수
			cond = na[i] * isMin_a - nb[i] * isMin_b;

			if (na[i] * isMin_a < nb[i] * isMin_b)
			{
				//a와 b를 스왑하여 a의 절댓값이 b의 절댓값보다 크게 한다
				swap(na, nb);
				swap(index_a, index_b);
				swap(isMin_a, isMin_b);

				break;
			}

			else if (na[i] * isMin_a > nb[i] * isMin_b) break;
		}
	}

	//a가 음수라면 a와 b에 -1을 곱해 결과가 양수가 나오게 한다
	//a가 양수고 b가 음수라면 결과는 반드시 양수가 나온다

	if (isMin_a == -1)
	{
		for (int i = 0; i < index_a; i++) na[i] *= -1;
		for (int i = 0; i < index_b; i++) nb[i] *= -1;
	}

	//a와 b의 각 자리수를 더한다
	for (int i = 0; i < size; i++)
	{
		na[i] += nb[i];

		//자리수의 합이 음수라면 다음 자리수에서 값을 가져온다
		while (na[i] < 0)
		{
			na[i] += 10;
			na[i + 1] -= 1;
		}
		//자리수의 합이 10 이상이라면 다음 자리수에 값을 보낸다
		while (na[i] >= 10)
		{
			na[i] -= 10;
			na[i + 1] += 1;
		}
	}

	//덧셈 결과 자리수가 늘었다면 그만큼 size를 늘려준다
	while (size <= 10000)
	{
		if (na[size] != 0)
		{
			while (na[size] >= 10)
			{
				//늘어난 자리의 자리수가 10 이상이라면 다음 자리수에 값을 보낸다
				na[size] -= 10;
				na[size + 1] += 1;
			}

			size += 1;
		}
		else break;
	}

	//덧셈 결과 자리수가 줄었다면 그만큼 size를 줄여준다
	while (size > 1)
	{
		if (na[size - 1] == 0) size -= 1;
		else break;
	}

	//a가 음수였다면 a에 -1을 곱해 다시 음수로 만든다
	if (isMin_a == -1) na[size - 1] *= -1;

	//a 출력
	for (int i = size - 1; i >= 0; i--) cout << na[i];
	cout << '\n';

    return 0;
}