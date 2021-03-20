#include <cstdio>

int main()
{
    //input: 이동할 방의 번호, ret: 반지름을 통해 정답을 구함
	int input, ret = 1;
	scanf("%d", &input);
    
    //맨 처음 방은 이동할 필요가 없으므로 예외가 발생한다
    //이 예외를 잡기 위해 input에 1을 빼 준다
	input -= 1;

	//해당 벌집의 방을 묶어서 원의 집합으로 보자. 
	//방 1은 반지름이 0인 원, 방 2부터 방 7까지는 반지름이 1인 원, ...
	//모든 방을 이렇게 생각하면 반지름이 같은 방은 모두 같은 거리만큼 움직여 도달할 수 있다.
	//n > 0일 때 반지름이 n인 방의 개수는 6n이다.
	//따라서 n을 계속 증가시키며 (input - 1)에서 6n씩 뺄 때
	//input이 처음으로 음수가 될 때의 n이 방 input의 반지름이다.
	while (input > 0) input -= 6 * ret++;
	printf("%d\n", ret);

    return 0;
}