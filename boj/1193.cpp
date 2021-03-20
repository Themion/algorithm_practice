#include <cstdio>

int main()
{
	//num : 분수의 위치를 특정할 때 사용할 변수
	//fracSum : num이 계속 양수일 땐 분모와 분자의 합이 fracSum인 분수의 개수
	//			num이 음수로 변한 다음에는 up과 down에 더하고 뺄 가중치
	//up, down : 각각 분수의 분자와 분모
	int num, fracSum = 0, up, down;
	//num이 음수로 변한 대각선에서 
	//대각선이 오른쪽 위로 올라가는지 혹은 왼쪽 아래로 내려가는지 판정
	bool isDown = false;

	scanf("%d", &num);

	//num이 양수일 때, 즉 fracSum이 원하는 값보다 작을 때
	while (num > 0)
	{
		//fracSum의 초기값이 0이므로
		//num에 fracSum을 빼기 전에 먼저 1 더해준다
		fracSum += 1;
		//num을 fracSum만큼, 즉 분모와 분자의 합이 fracSum인 분수의 개수만큼 뺀다
		num -= fracSum;
		//다음 대각선은 지금 대각선과 분수의 진행 방향이 다르다
		isDown = !isDown;
	}

	//분수의 진행 방향이 왼쪽 아래라면 분수의 초기값은 down이 큰 형태이다
	//그렇지 않다면 분수의 초기값은 up이 큰 형태이다
	if (isDown)	{ up = 1 - num;			down = fracSum + num;  }
	else		{ up = fracSum + num;	down = 1 - num; }

	//분수를 출력한다
	printf("%d/%d\n", up, down);

    return 0;
}