#include <cstdio>
#include <utility>

using namespace std;

typedef pair<int, int> coord;

#define _y first
#define _x second

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
// 두 좌표 a, b의 각 성분 중 큰 값만을 가지는 좌표를 계산
coord min(coord a, coord b) { return {min(a._y, b._y), min(a._x, b._x)}; }
coord max(coord a, coord b) { return {max(a._y, b._y), max(a._x, b._x)}; }
coord operator+(coord a, coord b) { return {a._y + b._y, a._x + b._x}; }
coord operator-(coord a) { return {-a._y, -a._x}; }

// add[i]: i번 방향으로 한 칸 이동할 때 사용할 변수
// min_coord, max_coord: 직사각형 범위를 저장할 때 사용할 변수
coord add[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}, min_coord, max_coord;

// 거북이를 add만큼 이동한 뒤 최대/최소 좌표 갱신
void move_turtle(coord& turtle, coord add_) {
    turtle = turtle + add_;
    min_coord = min(turtle, min_coord);
    max_coord = max(turtle, max_coord);
}

int test_case() {
    // 명령의 각 자리
    char buf;
    // 거북이의 머리가 향하는 방향
    int dir = 0;
    // 거북이의 현재 좌표
    coord turtle = {0, 0};

    // 최대/최소 좌표를 초기화
    max_coord = min_coord = {0, 0};

    // 명령의 각 자리에 대해
    while (scanf("%c", &buf) && buf != '\n') {
        // F라면 한칸 앞으로, B라면 뒤로 이동
        // L/R이라면 직각 좌/우회전
        if      (buf == 'F') move_turtle(turtle, add[dir]);
        else if (buf == 'B') move_turtle(turtle, -add[dir]);
        else if (buf == 'L') dir = (dir + 1) % 4;
        else if (buf == 'R') dir = (dir + 3) % 4;
    }

    // 거북이가 이동한 면의 직사각형 넓이를 계산
    return (max_coord._y - min_coord._y) * (max_coord._x - min_coord._x);
}

int main() {
    int T;
    // 테스트 케이스를 입력받아 각 테스트 케이스 실행
    for (scanf("%d\n", &T); T--; ) printf("%d\n", test_case());

    return 0;
}
