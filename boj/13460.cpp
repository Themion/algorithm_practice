#include <cstdio>
#include <queue>

using namespace std;

//stase[abcd]: 한 자리 수 a, b, c, d에 대해
//             빨간 구슬의 좌표는 (a, b)이고 파란 구슬의 좌표는 (c, d)이다.
//             두 구슬의 좌표를 저장한 네 자리 수 abcd에 대해
//             state[abcd]의 값을 동적 활용법을 이용해 저장하면
//             해당 경우가 등장하지 않았다면 0,
//             등장하였다면 해당 경우를 만드는 데에 필요한 최소 기울임 횟수이다
int state[10000];

class coord
{
public:
    int x = 0, y = 0;
    coord() {};
    coord(int a, int b) { x = a; y = b; }
};

class marbleBoard
{
public:
    //보드의 넓이와 높이를 저장
    int width, height;
    //보드에 벽과 구슬, 구멍의 배치를 기록
    char board[10][11];
    //두 구슬과 구멍의 위치
    coord R, B, O;

    //두 구슬의 첫 위치와 보드를 입력받는다
    marbleBoard()
    {
        //보드의 가로세로 길이를 입력받는다
        scanf("%d %d\n", &height, &width);

        //각 보드의 위치에 대해
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j <= width; j++)
            {
                //해당 위치가 어떤 타입인지 판정한 뒤
                scanf("%c", &board[i][j]);

                //각 자리에 구슬이나 구멍이 있다면 해당 위치를 표시한다
                if (board[i][j] == 'R')
                    R = coord(i, j);
                else if (board[i][j] == 'B')
                    B = coord(i, j);
                else if (board[i][j] == 'O')
                    O = coord(i, j);
            }

            //마지막에 오는 개행문자는 무시한다
            //백준 컴파일러에선 작동하지 않음
            scanf("%*c");
        }
    }

    //더미 생성자
    marbleBoard(int i) {}

    //세로 x, 가로 y 위치의 상태를 판정
    int valid(int x, int y)
    {
        //해당 위치가 보드의 범위를 벗어났다면 -2를 출력
        if (x < 0 || x >= height || y < 0 || y > width)
            return -2;

        //여러 번 board 변수를 호출하지 않는다
        char dbg = board[x][y];

        //해당 위치가 막혀있다면 -1을 출력
        if (dbg == '#')
            return -1;
        //해당 위치에 구슬이 놓여있다면 0을 출력
        else if ((dbg == 'R') || (dbg == 'B'))
            return 0;
        //그렇지 않은 경우, 즉 빈 공간이거나 구멍이 있다면 1을 출력
        else
            return 1;
    }

    //보드를 윗쪽으로 기울인다
    int UP()
    {
        //현실적으로 중력을 표현하기는 힘들다
        //우선 두 구슬이 모두 움직이는 경우를 따진다
        while ((valid(R.x - 1, R.y) > -1) && (valid(B.x - 1, B.y) > -1))
        {
            //현재 위치를 비운 뒤
            board[B.x][B.y] = '.';
            board[R.x][R.y] = '.';

            //두 구슬을 한 칸 위로 움직인다
            B.x -= 1;
            R.x -= 1;

            //파란 구슬이 구멍에 떨어졌을 때
            if (board[B.x][B.y] == 'O')
            {
                //빨간 구슬의 위치를 표시해준 뒤
                board[R.x][R.y] = 'R';
                //해당 움직임이 실패임을 반환함
                return -1;
            }
            //빨간 구슬이 구멍에 떨어졌을 때
            else if (board[R.x][R.y] == 'O')
            {
                //파란 구슬의 위치를 표시해준 뒤
                board[B.x][B.y] = 'B';
                //해당 움직임이 성공임을 반환함
                return 1;
            }
            //두 구슬 다 구멍에 들어가지 않았다면 두 구슬의 위치를 표시함
            else
            {
                board[B.x][B.y] = 'B';
                board[R.x][R.y] = 'R';
            }
        }

        //만일 빨간 구슬만 벽에 부딪혔다면
        while (valid(B.x - 1, B.y) == 1)
        {
            //파란 구슬의 현재 위치를 비운 뒤
            board[B.x][B.y] = '.';

            //파란 구슬을 한 칸 위로 움직인다
            B.x -= 1;
            //파란 구슬이 구멍에 떨어졌다면 해당 움직임은 실패
            if (board[B.x][B.y] == 'O')
                return -1;
            //그렇지 않다면 파란 구슬의 위치를 표시해줌
            else
                board[B.x][B.y] = 'B';
        }

        //만일 파란 구슬만 벽에 부딪혔다면
        while (valid(R.x - 1, R.y) == 1)
        {
            //빨간 구슬의 현재 위치를 비운 뒤
            board[R.x][R.y] = '.';
            //빨간 구슬을 한 칸 위로 움직인다
            R.x -= 1;
            //빨간 구슬이 구멍에 떨어졌다면 해당 움직임은 성공
            if (board[R.x][R.y] == 'O')
                return 1;
            //그렇지 않다면 빨간 구슬의 위치를 표시해줌
            else
                board[R.x][R.y] = 'R';
        }

        //두 구슬 다 벽에 막혔다면 0을 반환한다
        return 0;
    }
    //보드를 아랫쪽으로 기울인다
    int DOWN()
    {
        //현실적으로 중력을 표현하기는 힘들다
        //우선 두 구슬이 모두 움직이는 경우를 따진다
        while ((valid(R.x + 1, R.y) > -1) && (valid(B.x + 1, B.y)) > -1)
        {
            //현재 위치를 비운 뒤
            board[B.x][B.y] = '.';
            board[R.x][R.y] = '.';

            //두 구슬을 한 칸 아래로 움직인다
            B.x += 1;
            R.x += 1;

            //파란 구슬이 구멍에 떨어졌을 때
            if (board[B.x][B.y] == 'O')
            {
                //빨간 구슬의 위치를 표시해준 뒤
                board[R.x][R.y] = 'R';
                //해당 움직임이 실패임을 반환함
                return -1;
            }
            //빨간 구슬이 구멍에 떨어졌을 때
            else if (board[R.x][R.y] == 'O')
            {
                //파란 구슬의 위치를 표시해준 뒤
                board[B.x][B.y] = 'B';
                //해당 움직임이 성공임을 반환함
                return 1;
            }
            //두 구슬 다 구멍에 들어가지 않았다면 두 구슬의 위치를 표시함
            else
            {
                board[B.x][B.y] = 'B';
                board[R.x][R.y] = 'R';
            }
        }

        //만일 빨간 구슬만 벽에 부딪혔다면
        while (valid(B.x + 1, B.y) == 1)
        {
            //파란 구슬의 현재 위치를 비운 뒤
            board[B.x][B.y] = '.';
            //파란 구슬을 한 칸 아래로 움직인다
            B.x += 1;
            //파란 구슬이 구멍에 떨어졌다면 해당 움직임은 실패
            if (board[B.x][B.y] == 'O')
                return -1;
            //그렇지 않다면 파란 구슬의 위치를 표시해줌
            else
                board[B.x][B.y] = 'B';
        }

        //만일 파란 구슬만 벽에 부딪혔다면
        while (valid(R.x + 1, R.y) == 1)
        {
            //빨간 구슬의 현재 위치를 비운 뒤
            board[R.x][R.y] = '.';
            //빨간 구슬을 한 칸 아래로 움직인다
            R.x += 1;
            //빨간 구슬이 구멍에 떨어졌다면 해당 움직임은 성공
            if (board[R.x][R.y] == 'O')
                return 1;
            //그렇지 않다면 빨간 구슬의 위치를 표시해줌
            else
                board[R.x][R.y] = 'R';
        }

        //두 구슬 다 벽에 막혔다면 0을 반환한다
        return 0;
    }
    //보드를 왼쪽으로 기울인다
    int LEFT()
    {
        //현실적으로 중력을 표현하기는 힘들다
        //우선 두 구슬이 모두 움직이는 경우를 따진다
        while ((valid(R.x, R.y - 1) > -1) && (valid(B.x, B.y - 1)) > -1)
        {
            //현재 위치를 비운 뒤
            board[B.x][B.y] = '.';
            board[R.x][R.y] = '.';

            //두 구슬을 한 칸 왼쪽으로 움직인다
            B.y -= 1;
            R.y -= 1;

            //파란 구슬이 구멍에 떨어졌을 때
            if (board[B.x][B.y] == 'O')
            {
                //빨간 구슬의 위치를 표시해준 뒤
                board[R.x][R.y] = 'R';
                //해당 움직임이 실패임을 반환함
                return -1;
            }
            //빨간 구슬이 구멍에 떨어졌을 때
            else if (board[R.x][R.y] == 'O')
            {
                //파란 구슬의 위치를 표시해준 뒤
                board[B.x][B.y] = 'B';
                //해당 움직임이 성공임을 반환함
                return 1;
            }
            //두 구슬 다 구멍에 들어가지 않았다면 두 구슬의 위치를 표시함
            else
            {
                board[B.x][B.y] = 'B';
                board[R.x][R.y] = 'R';
            }
        }

        //만일 빨간 구슬만 벽에 부딪혔다면
        while (valid(B.x, B.y - 1) == 1)
        {
            //파란 구슬의 현재 위치를 비운 뒤
            board[B.x][B.y] = '.';
            //파란 구슬의 현재 위치를 한 칸 아래로 움직인다
            B.y -= 1;
            //파란 구슬이 구멍에 떨어졌다면 해당 움직임은 실패
            if (board[B.x][B.y] == 'O')
                return -1;
            //그렇지 않다면 파란 구슬의 위치를 표시해줌
            else
                board[B.x][B.y] = 'B';
        }

        //만일 파란 구슬만 벽에 부딪혔다면
        while (valid(R.x, R.y - 1) == 1)
        {
            //빨간 구슬의 현재 위치를 비운 뒤
            board[R.x][R.y] = '.';
            //빨간 구슬을 한 칸 왼쪽으로 움직인다
            R.y -= 1;
            //빨간 구슬이 구멍에 떨어졌다면 해당 움직임은 성공
            if (board[R.x][R.y] == 'O')
                return 1;
            //그렇지 않다면 빨간 구슬의 위치를 표시해줌
            else
                board[R.x][R.y] = 'R';
        }

        //두 구슬 다 벽에 막혔다면 0을 반환한다
        return 0;
    }
    //보드를 오른쪽으로 기울인다
    int RIGHT()
    {
        //현실적으로 중력을 표현하기는 힘들다
        //우선 두 구슬이 모두 움직이는 경우를 따진다
        while ((valid(R.x, R.y + 1) > -1) && (valid(B.x, B.y + 1) > -1))
        {
            //현재 위치를 비운 뒤
            board[B.x][B.y] = '.';
            board[R.x][R.y] = '.';

            //두 구슬을 한 칸 오른쪽으로 움직인다
            B.y += 1;
            R.y += 1;

            //파란 구슬이 구멍에 떨어졌을 때
            if (board[B.x][B.y] == 'O')
            {
                //빨간 구슬의 위치를 표시해준 뒤
                board[R.x][R.y] = 'R';
                //해당 움직임이 실패임을 반환함
                return -1;
            }
            //빨간 구슬이 구멍에 떨어졌을 때
            else if (board[R.x][R.y] == 'O')
            {
                //파란 구슬의 위치를 표시해준 뒤
                board[B.x][B.y] = 'B';
                //해당 움직임이 성공임을 반환함
                return 1;
            }
            //두 구슬 다 구멍에 들어가지 않았다면 두 구슬의 위치를 표시함
            else
            {
                board[B.x][B.y] = 'B';
                board[R.x][R.y] = 'R';
            }
        }

        //만일 빨간 구슬만 벽에 부딪혔다면
        while (valid(B.x, B.y + 1) == 1)
        {
            //파란 구슬의 현재 위치를 비운 뒤
            board[B.x][B.y] = '.';
            //파란 구슬의 현재 위치를 한 칸 왼쪽으로 움직인다
            B.y += 1;
            //파란 구슬이 구멍에 떨어졌다면 해당 움직임은 실패
            if (board[B.x][B.y] == 'O')
                return -1;
            //그렇지 않다면 파란 구슬의 위치를 표시해줌
            else
                board[B.x][B.y] = 'B';
        }

        //만일 파란 구슬만 벽에 부딪혔다면
        while (valid(R.x, R.y + 1) == 1)
        {
            //빨간 구슬의 현재 위치를 비운 뒤
            board[R.x][R.y] = '.';
            //빨간 구슬을 한 칸 오른쪽으로 움직인다
            R.y += 1;
            //빨간 구슬이 구멍에 떨어졌다면 해당 움직임은 성공
            if (board[R.x][R.y] == 'O')
                return 1;
            //그렇지 않다면 빨간 구슬의 위치를 표시해줌
            else
                board[R.x][R.y] = 'R';
        }

        //두 구슬 다 벽에 막혔다면 0을 반환한다
        return 0;
    }
    //반복문을 사용하여 간단히 기울일 수 있도록 만든 함수
    int tilt(int temp)
    {
        //0: 위, 1: 아래, 2: 왼쪽, 3:오른쪽
        //해당하는 방향으로 기울인 뒤 그 결과값을 그대로 출력한다
        switch (temp)
        {
        case 0:
            return this->UP();
            break;
        case 1:
            return this->DOWN();
            break;
        case 2:
            return this->LEFT();
            break;
        case 3:
            return this->RIGHT();
            break;
        }

        //0~3 이외의 입력값이 들어온 경우 -1을 반환
        return -1;
    }

    //파란 구슬이 움직일 수 있는 상황에서 빨간 구슬이 구멍에 들어간 경우
    bool fallTogether(int temp)
    {
        //빨간 구슬이 있던 위치를 비우지 않았으므로 비워준 뒤 구슬을 보드에서 제거한다
        int save = R.x;
        this->board[R.x][R.y] = '.';
        R.x = -1;

        //파란 구슬만 있는 상태에서 다시 보드를 기울인 다음
        int score = this->tilt(temp);

        //빨간 구슬을 원래 있던 위치에 다시 둔다
        R.x = save;
        this->board[R.x][R.y] = 'R';

        //파란 구슬이 구멍에 들어갔다면 true를, 아니라면 false를 반환
        if (score == -1)
            return true;
        else
            return false;
    }

    //현재 보드의 상태를 복사하여 반환하는 함수
    marbleBoard *makeNew()
    {
        //빈 보드 ret을 하나 만든 뒤
        marbleBoard *ret = new marbleBoard(3);

        //넓이와 높이를 복사한다
        ret->width = this->width;
        ret->height = this->height;

        //그 다음 장애물과 구슬, 구멍의 위치 등을 복사한다
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                ret->board[i][j] = this->board[i][j];

                //복사된 구슬과 구멍의 위치는 만일을 대비해 ret에 있는 걸 사용하게 한다
                if (board[i][j] == 'R')
                    ret->R = coord(i, j);
                else if (board[i][j] == 'B')
                    ret->B = coord(i, j);
                else if (board[i][j] == 'O')
                    ret->O = coord(i, j);
            }

        //ret이 완성되었으면 ret을 반환한다
        return ret;
    }
};

int main()
{
    //보드를 총 기울인 횟수
	int ret = 0;
	//보드를 기울인 결과값 혹은 동적 계획법에 쓰일 키값
	int result = 0;
	//넓이 우선 탐색에서 깊이에 해당하는 변수
	int count;

	//만일 깊이가 10을 넘기 전에 방법을 찾았다면 true, 아니라면 false
	bool isDone = false;
	//보드를 여러 번 회전하기 위해 사용할 임시 변수
	marbleBoard* temp;

	//큐를 이용한 넓이 우선 탐색을 사용한다
	queue<marbleBoard*> Q;

	//큐에 초기 상태의 보드를 push한다
	Q.push(new marbleBoard());

	//방법을 찾거나 깊이가 10을 넘지 않을 때
	while ((!isDone) && (ret <= 10))
	{
		//큐에 들어간 상태의 수를 계산한 뒤
		count = Q.size();

		//모든 상태에 대해
		for (int j = 0; j < count; j++)
		{
			//네 방향으로 모두 기울여본다
			for (int i = 0; i < 4; i++)
			{
				//temp에 현재 상태를 복사한다
				temp = Q.front()->makeNew();
				//0: 위, 1: 아래, 2: 왼쪽, 3:오른쪽
				//해당하는 방향으로 기울인 결과값을 저장한다
				result = temp->tilt(i);

				//결과값이 0인 경우(=두 구슬이 벽에 막힌 경우)
				if (result == 0)
				{
					//두 구슬의 x좌표 및 y좌표는 문제의 정의에 의해 절대 0 이하 10 이상이 될 수 없다
					//두 구슬의 좌표를 이용해 유일한 키를 만든다
					result = (temp->R.x) * 1000 + (temp->R.y) * 100 + (temp->B.x) * 10 + (temp->B.y);

					//해당 키를 가진 상태가 이미 등장하지 않았다면
					if (state[result] == 0)
					{
						//해당 상태를 맵에 저장한 뒤
						state[result] = ret;
						//큐에 넣는다
						Q.push(temp);
					}
				}
				//결과값이 1인 경우(=빨간 구슬이 구멍에 들어간 경우)
				else if (result == 1)
				{
					//임시로 만든 변수 checkFall에 기울이기 직전 상태를 복사한다
					marbleBoard* checkFall = Q.front()->makeNew();
					//해당 상태에서 빨간 구슬을 뺀 경우 파란 구슬이 들어가는지 확인
					bool checking = checkFall->fallTogether(i);
					//파란 구슬이 들어가지 않았다면
					if (!checking)
					{
						//현재 상태가 정답이다
						//isDone을 true로 맞춰 루프문을 빠져나간다
						isDone = true;
						//break로 for문을 빠져나간다
						break;
					}
				}

				//정답을 찾았다면 루프문을 빠져나간다
				if (isDone) break;
			}

			//한 상태에 대해 네 방향으로 모두 기울여봤다면 해당 상태를 큐에서 제거한다
			Q.pop();
		}

		//기존 상태에서 한 번 더 기울였으므로 기울인 횟수를 1 추가
		ret++;
	}

	//10번 이상 기울여서 루프문을 빠져나갔다면 -1 출력
	if (ret > 10) printf("%d\n", -1);
	//정답을 찾아 루프문을 빠져나갔다면 기울인 횟수 출력
	else printf("%d\n", ret);

    return 0;
}