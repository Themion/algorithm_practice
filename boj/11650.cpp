#include <algorithm>
#include <cstdio>

//pair보다 저렴하다
class coord { public: int x = 0, y = 0; };

//입력받을 좌표를 저장할 공간
coord pnt[100000];

int main()
{
    //입력받을 좌표의 수
	int N;

	//좌표의 수와 좌표들을 입력받는다
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d %d", &pnt[i].x, &pnt[i].y);

	//좌표를 x가 작은 순으로, x값이 같다면 y가 작은 순으로 정렬한다
	std::sort(pnt, pnt + N,
		[](coord a, coord b)
		{
			if (a.x == b.x) return a.y < b.y;
			return a.x < b.x;
		}
	);

	//정렬된 점들을 출력한다
	for (int i = 0; i < N; i++) printf("%d %d\n", pnt[i].x, pnt[i].y);

    return 0;
}