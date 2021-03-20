#include <algorithm>
#include <cstdio>
#include <deque>

using namespace std;

//now_dir: 현재 뱀이 진행중인 방향
//sec: 게임을 시작한 뒤 경과한 초 수
//buf: 간접적으로 입력받기 위해 사용할 버퍼
int now_dir = 0, sec = 1, buf[2];

//보드 칸이 1이라면 벽/뱀, 2라면 사과, 그 이외는 빈 칸
//change[i]: i초에 왼쪽으로 방향 전환을 한다면 3, 오른쪽으로 한다면 1
//dir[now_dir]: 뱀의 방향이 now_dir일 때 뱀의 머리의 변위
int8_t board[102][102], change[10001],
    dir[4][2] =
    {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };

//게임이 유효하면 true, 아니라면 false
bool valid = true;

//뱀을 이루는 칸의 집합
deque<pair<int8_t, int8_t>> snake;

void game()
{
    //다음에 머리가 위치할 지점을 buf에 저장해준다
    buf[0] = snake.front().first + dir[now_dir][0];
    buf[1] = snake.front().second + dir[now_dir][1];

    //머리가 위치할 칸에 대해
    switch (board[buf[0]][buf[1]])
    {
    //해당 칸이 벽이거나 뱀의 몸통이라면
    case 1:
        //게임은 더이상 유효하지 않다
        valid = false;
        //게임이 진행된 초 수를 출력한다
        printf("%d\n", sec);
        //switch문을 나간다
        break;
    //해당 칸이 빈 칸이라면
    case 0:
        //뱀의 꼬리를 한 칸 제거한다
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
    //해당 칸이 빈 칸이거나 사과가 존재하는 칸이라면
    case 2:
        //뱀의 머리를 한 칸 늘린다
        board[buf[0]][buf[1]] = 1;
        snake.push_front(pair<int, int>(buf[0], buf[1]));
    default:
        //마지막으로 방향을 현재 초에 맞게 수정해준 다음 초를 갱신한다
        now_dir = (now_dir + change[sec++]) % 4;
        break;
    }
}

int main()
{
    //size: 보드의 크기
    //cnt: 사과의 개수와 방향 전환 수를 입력받음
    int size, cnt;

    scanf("%d", &size);
    for (int i = 0; i <= size; i++)
    {
        board[0][i] = 1;
        board[i][0] = 1;
        board[size + 1][i] = 1;
        board[i][size + 1] = 1;
    }

    //뱀은 처음에 맨 위 맨좌측에 위치하며 길이는 1이다
    board[1][1] = 1;
    snake.push_back(pair<int, int>(1, 1));

    //사과의 수를 입력받은 뒤 입력받은 칸에 사과를 배치한다
    scanf("%d", &cnt);
    while (cnt--) 
    {
        scanf("%d %d", &buf[0], &buf[1]);
        board[buf[0]][buf[1]] = 2;
    }

    //방향 전환 횟수를 입력받은 뒤 입력받은 초에 방향을 전환한다
    scanf("%d", &cnt);
    while (cnt--) 
    {
        scanf("%d %c", &buf[0], &buf[1]);
        if      (buf[1] == 'D') change[buf[0]] = 1;
        else if (buf[1] == 'L') change[buf[0]] = 3;
    }

    //게임이 유효한 동안 게임을 진행한다
    while (valid) game();

    return 0;
}