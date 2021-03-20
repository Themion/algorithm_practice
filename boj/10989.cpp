#include <cstdio>

//str[0]은 배열의 크기, str[i]는 i가 등장한 횟수
int str[10001];

int main()
{
	//들어온 값을 저장할 임시 변수
	int temp;

	//배열의 크기를 입력받는다
	scanf("%d", &str[0]);

	//배열의 모든 수에 대해
	for (int i = 0; i < str[0]; i++)
	{
		//배열의 i번째 수를 입력받은 뒤
		scanf("%d", &temp);
		//해당 수가 등장한 횟수를 1 늘린다
		str[temp] += 1;
	}

	//1부터 10000까지의 모든 수에 대해 그 수를 등장한 횟수만큼 출력한다
	for (int i = 1; i <= 10000; i++) 
        for (int j = 0; j < str[i]; j++) printf("%d\n", i);

    return 0;
}