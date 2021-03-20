#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

void UP(int idx);
void DOWN(int idx);
void LEFT(int idx);
void RIGHT(int idx);

//2048의 한 블럭
//좌표값과 블럭의 가중치 val을 인자로 가지고 있다
class cell
{
public:
    int x, y, val;
    cell() { x = 0; y = 0; val = 0; }
    cell(int xx, int yy, int V) { x = xx; y = yy; val = V; }
};

//ret: 역대 최고 가중치, len: 게임보드의 한 변의 길이
int ret = 0, len;
//게임보드를 2차원 배열이 아닌, cell들의 1차원 배열로 본다
//총 5번 스와이프하므로 보드의 수는 6개
vector<cell> board[6];

//보드를 idx번 스와이프한 다음 위로 스와이프 하는 경우
void UP(int idx)
{
    //스와이프 직후의 공간을 레퍼런스로 불러온다
    vector<cell> &lst = board[idx + 1];

    //기존 보드의 상태를 가져온다
    lst.resize((int)(board[idx].size()));
    copy(board[idx].begin(), board[idx].end(), lst.begin());

    //cell을 x값이 작은 순으로, x값이 같다면 y값이 작은 순으로 정렬한다
    sort(lst.begin(), lst.end(), [](cell &a, cell &b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    //자신 바로 다음에 위치한 블럭이 같은 열에 있고, 같은 가중치를 가지고 있다면 두 블럭을 합친다
    for (int i = 0; i < lst.size() - 1; i++)
    {
        if ((lst[i].x == lst[i + 1].x) && (lst[i].val == lst[i + 1].val))
        {
            lst[i].val *= 2;
            lst.erase(lst.begin() + i + 1);

            //블럭이 합쳐질 때마다 최고 가중치를 갱신한다
            if (ret < lst[i].val) ret = lst[i].val;
        }
    }

    //맨 첫 블록의 y좌표는 0임이 자명하다
    lst[0].y = 0;

    //각 cell의 y좌표를 이전 cell과 비교하여 결정한다
    //이전 cell이 자신과 같은 열에 있다면 y좌표는 이전 cell의 y좌표 + 1, 그렇지 않다면 0
    for (int i = 1; i < lst.size(); i++)
    {
        if (lst[i].x == lst[i - 1].x) lst[i].y = lst[i - 1].y + 1;
        else                          lst[i].y = 0;
    }

    //스와이프를 재귀적으로 실행한다
    if (idx < 4) { UP(idx + 1); DOWN(idx + 1); LEFT(idx + 1); RIGHT(idx + 1); }
}

void DOWN(int idx)
{
    //스와이프 직후의 공간을 레퍼런스로 불러온다
    vector<cell> &lst = board[idx + 1];

    //기존 보드의 상태를 가져온다
    lst.resize((int)(board[idx].size()));
    copy(board[idx].begin(), board[idx].end(), lst.begin());

    //cell을 x값이 작은 순으로, x값이 같다면 y값이 큰 순으로 정렬한다
    sort(lst.begin(), lst.end(), [](cell &a, cell &b) {
        if (a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });

    //자신 바로 다음에 위치한 블럭이 같은 열에 있고, 같은 가중치를 가지고 있다면 두 블럭을 합친다
    for (int i = 0; i < lst.size() - 1; i++)
    {
        if ((lst[i].x == lst[i + 1].x) && (lst[i].val == lst[i + 1].val))
        {
            lst[i].val *= 2;
            lst.erase(lst.begin() + i + 1);

            //블럭이 합쳐질 때마다 최고 가중치를 갱신한다
            if (ret < lst[i].val) ret = lst[i].val;
        }
    }

    //맨 첫 블록의 y좌표는 len - 1임이 자명하다
    lst[0].y = len - 1;

    //각 cell의 y좌표를 이전 cell과 비교하여 결정한다
    //이전 cell이 자신과 같은 열에 있다면 y좌표는 이전 cell의 y좌표 - 1, 그렇지 않다면 len - 1
    for (int i = 1; i < lst.size(); i++)
    {
        if (lst[i].x == lst[i - 1].x) lst[i].y = lst[i - 1].y - 1;
        else                          lst[i].y = len - 1;
    }

    //스와이프를 재귀적으로 실행한다
    if (idx < 4) { UP(idx + 1); DOWN(idx + 1); LEFT(idx + 1); RIGHT(idx + 1); }
}

void LEFT(int idx)
{
    //스와이프 직후의 공간을 레퍼런스로 불러온다
    vector<cell> &lst = board[idx + 1];

    //기존 보드의 상태를 가져온다
    lst.resize((int)(board[idx].size()));
    copy(board[idx].begin(), board[idx].end(), lst.begin());

    //cell을 y값이 작은 순으로, x값이 같다면 x값이 작은 순으로 정렬한다
    sort(lst.begin(), lst.end(), [](cell &a, cell &b) {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    //자신 바로 다음에 위치한 블럭이 같은 행에 있고, 같은 가중치를 가지고 있다면 두 블럭을 합친다
    for (int i = 0; i < lst.size() - 1; i++)
    {
        if ((lst[i].y == lst[i + 1].y) && (lst[i].val == lst[i + 1].val))
        {
            lst[i].val *= 2;
            lst.erase(lst.begin() + i + 1);

            //블럭이 합쳐질 때마다 최고 가중치를 갱신한다
            if (ret < lst[i].val) ret = lst[i].val;
        }
    }

    //맨 첫 블록의 x좌표는 0임이 자명하다
    lst[0].x = 0;

    //각 cell의 x좌표를 이전 cell과 비교하여 결정한다
    //이전 cell이 자신과 같은 행에 있다면 x좌표는 이전 cell의 x좌표 + 1, 그렇지 않다면 0
    for (int i = 1; i < lst.size(); i++)
    {
        if (lst[i].y == lst[i - 1].y) lst[i].x = lst[i - 1].x + 1;
        else                          lst[i].x = 0;
    }

    //스와이프를 재귀적으로 실행한다
    if (idx < 4) { UP(idx + 1); DOWN(idx + 1); LEFT(idx + 1); RIGHT(idx + 1); }
}

void RIGHT(int idx)
{
    //스와이프 직후의 공간을 레퍼런스로 불러온다
    vector<cell> &lst = board[idx + 1];

    //기존 보드의 상태를 가져온다
    lst.resize((int)(board[idx].size()));
    copy(board[idx].begin(), board[idx].end(), lst.begin());

    //cell을 y값이 작은 순으로, x값이 같다면 x값이 큰 순으로 정렬한다
    sort(lst.begin(), lst.end(), [](cell &a, cell &b) {
        if (a.y == b.y) return a.x > b.x;
        return a.y < b.y;
    });

    //자신 바로 다음에 위치한 블럭이 같은 행에 있고, 같은 가중치를 가지고 있다면 두 블럭을 합친다
    for (int i = 0; i < lst.size() - 1; i++)
    {
        if ((lst[i].y == lst[i + 1].y) && (lst[i].val == lst[i + 1].val))
        {
            lst[i].val *= 2;
            lst.erase(lst.begin() + i + 1);

            //블럭이 합쳐질 때마다 최고 가중치를 갱신한다
            if (ret < lst[i].val) ret = lst[i].val;
        }
    }

    //맨 첫 블록의 x좌표는 len - 1임이 자명하다
    lst[0].x = len - 1;

    //각 cell의 x좌표를 이전 cell과 비교하여 결정한다
    //이전 cell이 자신과 같은 행에 있다면 x좌표는 이전 cell의 x좌표 - 1, 그렇지 않다면 len - 1
    for (int i = 1; i < lst.size(); i++)
    {
        if (lst[i].y == lst[i - 1].y) lst[i].x = lst[i - 1].x - 1;
        else                          lst[i].x = len - 1;
    }

    //스와이프를 재귀적으로 실행한다
    if (idx < 4) { UP(idx + 1); DOWN(idx + 1); LEFT(idx + 1); RIGHT(idx + 1); }
}

int main()
{
    int val;
    scanf("%d", &len);

    for (int i = 0; i < len * len; i++)
    {
        scanf("%d", &val);
        if (ret < val) ret = val;
        if (val != 0) board[0].push_back(cell(i % len, i / len, val));
    }

    //모든 과정은 재귀적으로 실행되므로 시작 부분만 실행해주면 된다
    UP(0); DOWN(0); LEFT(0); RIGHT(0);

    //최고 가중치를 출력한다
    printf("%d\n", ret);

    return 0;
}