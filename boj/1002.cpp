#include <cmath>
#include <cstdio>

//좌표 x, y를 저장할 클래스
class coord { public: int x, y; };

int main()
{
	//times : 테스트 케이스의 수, ret : 답을 반환할 때 쓸 변수
	//jr : 조규현이 구한 류재명의 좌표, br: 백승환이 구한 좌표
	int times, ret, jr, br;
	//조규현, 백승환, 류재명(추정) 셋이 이루는 삼각형의 세 변에 대해
	//각 변의 길이에서 나머지 두 변의 길이의 합을 뺀 값
	//삼각형이 성립하는지 확인하기 위해 사용함
	double tri[3];
	//jo, baek : 조규현과 백승환의 좌표
	coord jo, baek;

	//테스트 케이스의 수를 입력받는다
	scanf("%d", &times);

	//테스트 케이스만큼 반복
	for (int i = 0; i < times; i++)
	{
		//조규현의 좌표, 조규현이 구한 거리, 백승환의 좌표, 백승환이 구한 거리를 차례로 입력받는다
		scanf("%d %d %d %d %d %d", &jo.x, &jo.y, &jr, &baek.x, &baek.y, &br);

		//조규현과 백승환의 거리
		double dist = sqrt((jo.x - baek.x) * (jo.x - baek.x) + (jo.y - baek.y) * (jo.y - baek.y));
		
		//이 거리가 0이라면
		if (dist == 0)
		{
			//둘이 구한 거리가 다르다면 ret는 0, 같다면 -1
			if (jr != br)	ret = 0;
			else			ret = -1;
		}

		//이 거리가 0이 아니라면
		else
		{
			//tri의 값을 채워넣는다
			tri[0] = dist - (jr + br);
			tri[1] = jr - (br + dist);
			tri[2] = br - (dist + jr);

			//tri의 세 값 중 하나라도 0 이상이 나오면 삼각형은 성립하지 않는다 -> 류재명의 위치를 특정하지 못함
			//tri의 세 값 중 하나라도 0이 나오면 류재명은 조규현과 백승환이 이루는 직선 위에 있다
			//tri이 세 값 모두 음수라면 조규현, 백승환, 류재명(추정)은 삼각형을 이룬다
			if (tri[0] > 0 || tri[1] > 0 || tri[2] > 0) ret = 0;
			else if (tri[0] == 0 || tri[1] == 0 || tri[2] == 0) ret = 1;
			else ret = 2;
		}

		//ret을 반환한다
		printf("%d\n", ret);
	}

    return 0;
}