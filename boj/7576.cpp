#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	//pair의 fist, second는 가끔 헷갈린다
	class coord
	{
	public:
		int x, y;
		coord() { x = 0; y = 0; }
		coord(int yy, int xx) { x = xx; y = yy; }
	};

	//w, h: 토마토를 넣은 상자의 넓이와 높이
	//size: 큐에 들어가 있는 원소의 수를 저장
	//time: 출력할 값, done[i]: (i==0:지금, 1:이전) 시간에 다 익은 토마토의 개수
	int w, h, buf, size, time = 0, done[2] = { 0 };
	//토마토 상자. 메모리 절약을 위해 short 타입을 사용
	short t[1000][1000] = { {0, } };
	//바로 직전에 다 익은 토마토가 들어있는 상자의 좌표
	queue<coord> togo;

	//토마토 상자의 사이즈를 입력받는다
	scanf("%d %d", &w, &h);

	//토마토 상자의 각 칸에 대해
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
	{
		//해당 칸의 토마토 상태를 입력받고
		scanf("%hd", &t[i][j]);
		//칸이 비어있거나 익은 토마토가 들어있다면
		if (t[i][j] != 0)
		{
			//익은 토마토의 경우 해당 좌표를 큐에 넣는다
			if (t[i][j] == 1) togo.push(coord(i, j));
			//비어있는 칸 역시 다 익은 토마토로 간주한다
			done[0]++;
		}
	}

	//익을 수 있는 토마토가 다 익기 전까지
	while ((done[0] != w * h) && (done[1] != done[0]))
	{
		//이전 상태에서 다 익은 토마토의 개수를 저장
		done[1] = done[0];
		//현재 큐의 사이즈를 저장한다
		size = togo.size();

		//이전에 다 익었던 토마토에 대해
		for (int i = 0; i < size; i++)
		{
			//해당 토마토의 각각 왼쪽, 위, 오른쪽, 아래 칸에 익지 않은 토마토가 들어있다면
			//해당 좌표를 큐에 넣은 뒤 토마토를 익힌다

			if ((togo.front().x > 0) && (t[togo.front().y][togo.front().x - 1] == 0))
			{
				done[0]++;
				t[togo.front().y][togo.front().x - 1] = 1;
				togo.push(coord(togo.front().y, togo.front().x - 1));
			}
			if ((togo.front().y > 0) && (t[togo.front().y - 1][togo.front().x] == 0))
			{
				done[0]++;
				t[togo.front().y - 1][togo.front().x] = 1;
				togo.push(coord(togo.front().y - 1, togo.front().x));
			}
			if ((togo.front().x < w - 1) && (t[togo.front().y][togo.front().x + 1] == 0))
			{
				done[0]++;
				t[togo.front().y][togo.front().x + 1] = 1;
				togo.push(coord(togo.front().y, togo.front().x + 1));
			}
			if ((togo.front().y < h - 1) && (t[togo.front().y + 1][togo.front().x] == 0))
			{
				done[0]++;
				t[togo.front().y + 1][togo.front().x] = 1;
				togo.push(coord(togo.front().y + 1, togo.front().x));
			}

			//이 토마토의 영향력이 다했으므로 큐에서 제거한다
			togo.pop();
		}

		//시간이 한 번 지났으므로 이를 저장
		time++;
	}

	//상자 안의 토마토가 전부 익었다면 걸린 시간을 출력
	//그렇지 않다면 -1을 출력
	if (done[0] == w * h) printf("%d\n", time);
	else printf("-1\n");

    return 0;
}