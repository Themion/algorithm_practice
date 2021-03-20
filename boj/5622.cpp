#include <cstdio>

//입력받을 문자열을 저장
char cont[16];

int main()
{
	//ret : 전화를 거는 데에 걸리는 시간을 저장
	//count : 문자열의 실질적 길이를 저장
	int ret = 0, size = 0;

	//cont에 문자열을 입력받는다
	for (int i = 0; i < 16; i++)
	{
		scanf("%c", &cont[size]);
		if (cont[size] != '\n') size += 1;
		else break;
	}

	//cont의 각 글자를 확인하면서 ret에 값을 더해준다
	//이 때 다이얼 i에 대해 걸리는 시간은 i+1초이다
	for (int i = 0; i < size; i++)
	{
		if      (cont[i] >= 'W') ret += 10;
		else if (cont[i] >= 'T') ret += 9;
		else if (cont[i] >= 'P') ret += 8;
		else if (cont[i] >= 'M') ret += 7;
		else if (cont[i] >= 'J') ret += 6;
		else if (cont[i] >= 'G') ret += 5;
		else if (cont[i] >= 'D') ret += 4;
		else ret += 3;
	}

	//ret을 출력한다
	printf("%d\n", ret);

    return 0;
}