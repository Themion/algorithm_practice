#include <cstdio>

//col[i]: i열에 퀸이 있다면 true, 아니라면 false
//yx[i]: y = x꼴 대각선에 대해 판정
//       x축, y축 인덱스의 합이 i인 퀸이 있다면 true
//y_x[i]: y = -x꼴 대각선에 대해 판정
//       체스판을 y축에 대해 반전시킨 뒤
//       x축, y축 인덱스의 합이 i인 퀸이 있다면 true
bool col[15], yx[29], y_x[29];
//조건에 맞는 퀸 배치의 수
int ret = 0;
//체스판의 한 변의 길이
short n;

int abs(int a, int b) { return (a > b ? a - b : b - a); }

//인덱스가 (x, y)인 퀸을 배치할 수 있다면 true, 아니라면 false
bool check(int x, int y)
{
    if (col[y]) return false;
    if (yx[x + y]) return false;
    if (y_x[x + (n - 1 - y)]) return false;
    return true;
}

//퀸을 idx개 두었을 때 가능한 퀸의 배치를 계산한다
void set(int idx)
{
    //퀸을 n개 미만 두었을 때
    if(idx < n)
    {
        //퀸을 배치할 수 있는 모든 경우에 대해
        for (int i = 0; i < n; i++) if(check(idx, i))
        {
            //퀸을 배치한 뒤
            col[i] = true;
            yx[idx + i] = true; 
            y_x[idx + (n - 1 - i)] = true;

            //이 이후 배치할 수 있는 경우를 세고
            set(idx + 1);
            
            //마지막으로 배치한 퀸을 제거한다
            col[i] = false;
            yx[idx + i] = false; 
            y_x[idx + (n - 1 - i)] = false;
        }
    }

    //퀸을 n개 이상 배치했다면 가능한 경우의 수가 하나 는 것이다
    else ret++;
    return;
}

int main()
{
    //체스판의 크기를 입력받은 뒤
	scanf("%hd", &n);

    //배치 가능한 퀸의 수를 세어 출력한다
    set(0);
	printf("%d\n", ret);

	return 0;
}