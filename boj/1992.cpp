#include <cstdio>
#include <string>

using namespace std;

//공간을 절약하기 위해 주어진 영상을 bool타입의 이차원 배열로 저장한다
bool tree[64][64];

//왼쪽 꼭지점이 (s_x, s_y)이고 한 변의 길이가 len인 정사각형 꼴 영상을
//압축하여 string타입으로 출력한다
string QT(int s_y, int s_x, int len)
{
    //길이가 1인 정사각형은 압축할 필요 없이 본래의 값을 출력한다
    if(len == 1)
    {
        if (tree[s_y][s_x]) return "1";
        else                return "0";
    }

    //영상을 더 작은 사각형으로 사등분할 때
    //각 사각형의 왼쪽 위 꼭지점의 좌표를 계산할 때 쓸 변수
    long long xa, ya;
    //출력할 압축영상을 string 타입으로 저장할 변수
    string str = "(";

    //각 사등분된 사각형에 대해
    for(int i = 0; i < 4; i++)
    {
        //사각형의 왼쪽 위 꼭지점을 계산한 뒤
        ya = (i >= 2 ? len / 2 : 0);
        xa = (i % 2 ? len / 2 : 0);

        //각 사각형을 압축한 값을 str의 뒤에 붙인다
        str += QT(s_y + ya, s_x + xa, len / 2);
    }

    //맨 처음에 열어둔 괄호를 닫는다
    str += ")";

    //영상을 추가적으로 압축할 수 있다면 압축한다
    if(str == "(0000)") str = "0";
    if(str == "(1111)") str = "1";

    //압축영상을 반환한다
    return str;
}

int main()
{
    //입력에 사용할 버퍼
    char buf;
    //영상의 한 변의 길이
    int n;

    //영상의 크기를 입력받은 뒤
    scanf("%d\n", &n);
    //영상의 모든 좌표 (x, y)에 대해
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            //영상의 각 픽셀을 입력받은 뒤
            scanf("%c", &buf);
            //해당 픽셀의 값을 bool타입으로 변환해 저장한다
            tree[y][x] = buf == '1';
        }
        
        scanf("\n");
    }

    //영상을 분할 정복 기법을 이용해 압축한다
    string ret = QT(0, 0, n);
    //압축한 영상을 문자열로 바꿔 출력한다
    printf("%s\n", ret.c_str());

    return 0;
}