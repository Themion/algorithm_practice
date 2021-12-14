#include <cstdio>
#include <string>

using namespace std;

#define MAX_N 64

// 공간을 절약하기 위해 주어진 영상을 bool타입의 이차원 배열로 저장한다
bool tree[MAX_N][MAX_N];

// 왼쪽 꼭지점이 (x, y)이고 한 변의 길이가 len인 정사각형 꼴 영상을
// 압축하여 string타입으로 출력한다
string dnc(int y, int x, int len) {
    // 길이가 1인 정사각형은 압축할 필요 없이 본래의 값을 출력한다
    if (!len) return (tree[y][x] ? "1" : "0");

    // 출력할 압축영상을 string 타입으로 저장할 변수
    string str = "(";

    // 각 사등분된 사각형에 대해
    for (int i = 0; i < 4; i++)
        str += dnc(y + len * (i / 2), x + len * (i % 2), len / 2);

    // 맨 처음에 열어둔 괄호를 닫는다
    str += ")";

    // 영상을 추가적으로 압축할 수 있다면 압축한다
    if (str == "(0000)") str = "0";
    if (str == "(1111)") str = "1";

    // 압축영상을 반환한다
    return str;
}

int main() {
    // 입력에 사용할 버퍼
    char buf;
    // 영상의 한 변의 길이
    int N;

    // 영상의 크기를 입력받은 뒤
    scanf("%d\n", &N);
    // 영상의 모든 픽셀에 대해
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            // 영상의 각 픽셀을 입력받은 뒤 bool 타입으로 저장
            scanf("%c", &buf);
            tree[y][x] = buf == '1';
        }

        // 공백문자 제거
        scanf("%*c");
    }

    // 압축한 영상을 문자열로 바꿔 출력한다
    printf("%s\n", dnc(0, 0, N / 2).c_str());

    return 0;
}
