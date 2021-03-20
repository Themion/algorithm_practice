#include <cstdio>

//need[i]: 숫자 i가 쓰이는 수, num: 입출력에 쓸 변수
int need[10], num;

int main()
{
    //방 번호를 입력받는다
	scanf("%d", &num);

	//방 번호가 0이라면 0이 필요한 개수는 1개
	if (num == 0) need[0] = 1;

	//방 번호의 각 자리 수가 얼마나 쓰이는지 계산
	while (num > 0)
	{
		need[num % 10]++;
		num /= 10;
	}

	//6과 9는 서로 호환되므로 한 세트에 6dl 2개, 9가 0개 들었다고 가정
	//need[6] + need[9]가 홀수라면 소수점이 버려지므로
	//need[6]에 1을 더해 이 문제를 해결
	if ((need[6] + need[9]) % 2 == 1) need[6]++;
	need[6] = (need[6] + need[9]) / 2;

	//각 수 중 가장 많이 쓰이는 수가 필요 세트 양과 같다
	num = need[0];
	for (int i = 1; i < 9; i++) if (num < need[i]) num = need[i];

    //필요 세트 양을 출력한다
	printf("%d\n", num);

    return 0;
}