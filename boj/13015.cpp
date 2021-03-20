#include <cstdio>

int main()
{
	//input은 입력받을 수, space는 x자에서 각 대각선 사이의 거리
	int input, space;
	scanf("%d", &input);

	//사용의 편의를 위해 input에 1을 빼준다
	input -= 1;
	//space의 초기값을 설정해준다
	space = 2 * input - 1;

	//int j를 쓰는 for문이 많기 때문에 int j를 정의해줌
	int j;

	for (int i = 0; i < input; i++)
	{
		//x의 왼쪽 위 부분
		//왼쪽 선을 i칸 띄운 뒤 그리고, input - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
		//이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
		for (j = 0; j < i; j++) printf(" ");
		printf("*");
		if (i != 0) for (j = 1; j < input; j++) printf(" ");
		else		for (j = 1; j < input; j++) printf("*");
		printf("*");

		//x의 위쪽 공백 부분
		//space만큼 띄워준다
		for (j = 0; j < space; j++) printf(" ");

		//x의 오른쪽 위 부분
		//왼쪽 선을 그리고, input - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
		//이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
		printf("*");
		if (i != 0) for (j = 1; j < input; j++) printf(" ");
		else		for (j = 1; j < input; j++) printf("*");
		printf("*\n");

		//x의 위쪽 공백이 점점 줄어드므로 space를 줄어든 만큼 빼준다
		space -= 2;
	}

	//x의 한가운데 부분
	//우선 input만큼 공백을 준다
	for (j = 0; j < input; j++) printf(" ");

	//왼쪽 꼭지점을 그린 뒤 input - 1칸만큼 띄우고
	//한가운데 있는 점을 찍어준다
	//그 후 input - 1칸만큼 띄우고 오른쪽 꼭지점을 그린다
	printf("*");
	for (j = 1; j < input; j++) printf(" ");
	printf("*");
	for (j = 1; j < input; j++) printf(" ");
	printf("*\n");

	for (int i = input - 1; i >= 0; i--)
	{
		//x의 위쪽 공백이 점점 늘어나므로 space를 늘어난 만큼 더해준다
		space += 2;

		//x의 왼쪽 아래 부분
		//왼쪽 선을 i칸 띄운 뒤 그리고, input - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
		//이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
		for (j = 0; j < i; j++) printf(" ");
		printf("*");
		if (i != 0) for (j = 1; j < input; j++) printf(" ");
		else		for (j = 1; j < input; j++) printf("*");
		printf("*");


		//x의 아래쪽 공백 부분
		//space만큼 띄워준다
		for (j = 0; j < space; j++) printf(" ");

		//x의 오른쪽 아래 부분
		//왼쪽 선을 그리고, input - 1칸만큼 띄운 뒤 오른쪽 선을 그린다
		//이 때 i가 0인 경우 왼쪽 선과 오른쪽 선을 서로 이어준다
		printf("*");
		if (i != 0) for (j = 1; j < input; j++) printf(" ");
		else		for (j = 1; j < input; j++) printf("*");
		printf("*\n");
	}

    return 0;
}