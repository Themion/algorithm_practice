#include <cstdio>

//pair 대신 쓸 클래스
class part { public: int val = 0, time = 0; };

int main()
{
	//n: 테스트 케이스의 수, base: 각 테스트 케이스에서 인수를 구할 수
	//cnt: base의 인수 후보, idx: 인덱싱에 쓸 변수
	int n, base, cnt, idx;
	//base의 인수와 그 계수를 저장한 컨테이너
	//가장 작은 일곱 개의 소수 2, 3, 5, 7, 11, 13, 17을 곱하면 100000보다 크므로
	//base가 가질 수 있는 서로 다른 인수의 수는 총 6개이다
	part cont[6];

	//테스트 케이스의 수를 입력받는다
	scanf("%d", &n);

	//각 테스트 케이스에 대해
	for (int i = 0; i < n; i++)
	{
		//소인수 분해를 할 수를 입력받는다
		scanf("%d", &base);
		//cont의 0번 공간부터 저장한다
		idx = 0;

		//2보다 크거나 같은 수에 대해
		for(cnt = 2; cnt <= base; cnt++)
		{
			//해당 수의 등장 횟수를 저장
			cont[idx].val = cnt;
			cont[idx].time = 0;

			//base가 cnt를 약수로 가지는 동안
			while (base % cnt == 0)
			{
				//base를 cnt로 나누고 그 횟수를 저장
				cont[idx].time++;
				base /= cnt;
			}

			//cnt가 base의 약수였다면 이 공간을 수정하지 않는다
			if (cont[idx].time != 0) idx++;
		}

		//base의 각 약수와 그 계수를 출력한다
		for (cnt = 0; cnt < idx; cnt++)
			printf("%d %d\n", cont[cnt].val, cont[cnt].time);
	}

	return 0;
}