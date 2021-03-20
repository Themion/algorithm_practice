#include <cstdio>

//입력받은 종이
short paper[2187][2187];
//출력할 각 종이의 수
unsigned int list[3] = { 0, 0, 0 };

int check(int y, int x, int length)
{
    //확인하고자 하는게 1*1짜리 종이라면
    if (length == 0)
    {
        //종이를 사용했다고 치고 넘어간다
        list[paper[y][x] + 1]++;
        return paper[y][x];
    }

    //아홉 조각으로 나누었을 때 각 조각이 어떤 종이를 쓰는지 저장
    int chk[3][3] = { { 0, } };
    //모든 조각이 같은 종이를 쓰는지 확인
    bool is_same = true;

    //종이의 각 조각 종류를 알아낸 뒤 모든 조각이 같은 조각인지 계산
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    {
        chk[i][j] = check(y + length * i, x + length * j, length / 3);
        is_same = is_same && (chk[0][0] == chk[i][j]) && (chk[i][j] != 2);
    }

    //모든 조각이 같은 조각이라면 사용한 종이의 개수를 8 뺀다
    if (is_same)
    {
        list[chk[0][0] + 1] -= 8;
        return chk[0][0];
    }
    //아니라면 아무 연산도 하지 않고 이 조각이 누더기임을 알린다
    else return 2;
}

int main()
{
    //종이의 크기
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        scanf("%hd", &paper[i][j]);

    //종이에 쓰인 조각의 개수를 계산한다
    check(0, 0, n / 3);

    //종이 조각의 수를 출력한다
    for (auto i : list) printf("%d\n", i);

    return 0;
}
