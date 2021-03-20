#include <cstdio>

int main()
{
    //tc: 테스트 케이스의 수를 저장
    //input: 각 테스트 케이스를 저장할 공간
    //res[i - 1]: i에 대한 경우의 수 저장
    int tc, input, res[10] = {1, 2, 4};
    scanf("%d", &tc);

    //나올 수 있는 가장 큰 수는 10이므로
    //4부터 10까지에 대해 경우의 수 계산
    for (int i = 3; i < 10; i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];

	//각 테스트 케이스마다
	for (int i = 0; i < tc; i++)
	{
		//테스트 케이스를 입력받은 뒤
	    scanf("%d", &input);
		//해당 케이스에 해당하는 경우의 수를 출력한다
		printf("%d\n", res[input - 1]);
	}

    return 0;
}