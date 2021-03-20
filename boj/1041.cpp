#include <algorithm>
#include <cstdio>

int main()
{
	//N : 만들 정육면체의 한 변의 길이
	//front, left, up : 서로 마주보고 있는 두 면. 이 두 면은 N != 1일 때 동시에 존재할 수 없다
	int N, front[2], left[2], up[2];

	//정육면체를 만들었을 때 각 면의 가중치의 합
	long long ret = 0, temp;

	//N과 기본 정육면체를 입력받는다
	scanf("%d", &N);
	scanf("%d %d %d %d %d %d", &front[0], &left[0], &up[0], &up[1], &left[1], &front[1]);

	//N > 1이면 각 정육면체에서 사용되는 면은 최대 3개이다
	if (N > 1)
	{
		std::sort(front, front + 2);
		std::sort(left, left + 2);
		std::sort(up, up + 2);

		//서로 마주한 면들 중 더 작은 면만 사용
		long long cube[3] = { front[0], left[0], up[0] };
		//세 면을 오름차순으로 정렬
		std::sort(cube, cube + 3);

		//엣지와 코너를 제외한 다섯 면의 코어
		temp = 5 * (long long)(N - 2) * (long long)(N - 2) * (long long)cube[0];
		ret += temp;
		//윗면과 옆면에 존재하는 여덟 엣지
		temp = 8 * (long long)(N - 2) * (long long)(cube[0] + cube[1]);
		ret += temp;
		//윗쪽 네 코너
		temp = 4 * (long long)(cube[0] + cube[1] + cube[2]);
		ret += temp;
		//밑면의 네 엣지
		temp = 4 * (long long)(N - 2) * (long long)cube[0];
		ret += temp;
		//아랫쪽 네 코너
		temp = 4 * (long long)(cube[0] + cube[1]);
		ret += temp;
	}

	//N == 1이면 가려지는 건 단 한 면 뿐
	else
	{
		//모든 면을 cube에 저장한 뒤 cube를 오름차순으로 정렬해 가장 큰 면을 cube[5]에 저장
		long long cube[6] = { front[0], left[0], up[0], front[1], left[1], up[1] };
		std::sort(cube, cube + 6);

		//cube[5]를 제외한 모든 면을 더해 ret에 저장
		for(int i = 0; i < 5; i++) ret += cube[i];
	}

	//가중치의 합을 출력한다
	printf("%lld\n", ret);

    return 0;
}