#include <cstdio>

//나올 수 있는 가장 큰 숫자
const int size = 10000;
//num[i]: i가 소수라면 false, 아니라면 true
bool num[size + 1];

int main()
{
	//n, cnt: 소수 계산에 쓸 공간
	//base: 골드바흐 추측을 할 때 입력을 받을 공간
	int n, base, cnt;
    
	//0과 1은 소수가 아님이 자명하다
	num[0] = true; num[1] = true;

	//2부터 size / 2까지 해당 숫자가 소수라면
	for (n = 2; n <= size / 2; n++) if (!num[n])
	{
		//해당 수의 배수는 소수가 아니다
		cnt = 2;
		while (n * cnt <= size) num[n * cnt++] = true;
	}

	//테스트 케이스의 수를 입력받는다
	scanf("%d", &n);

	//각 테스트 케이스마다
	for (int i = 0; i < n; i++)
	{
		//골드바흐 추측을 할 수를 입력받고
		scanf("%d", &base);
		//해당 수를 절반으로 나눈다
		base /= 2; cnt = 0;
		//base - cnt와 base + cnt가 범위를 벗어나지 않을 때 
		while ((base - cnt >= 0) && (base + cnt <= size))
		{
			//두 수 중 소수가 아닌 수가 존재한다면 cnt를 1 더한다
			if (num[base - cnt] || num[base + cnt]) cnt++;
			//두 수 모두 소수라면
			else
			{
				//두 수를 출력한 뒤 while문을 나간다
				printf("%d %d\n", base - cnt, base + cnt);
				break;
			}
		}
	}

    return 0;
}