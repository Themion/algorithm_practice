#include <cstdio>

#define MAX_N 20

// N: 지도의 세로 크기, M: 지도의 가로 크기
int N, M;

// 좌표
class coord { 
public:
    // (x, y): (가로, 세로)
    int y = 0, x = 0;

    bool valid() { return y >= 0 && y < N && x >= 0 && x < M; }
    coord operator+(coord c) { return { y + c.y, x + c.x }; }
    coord& operator+=(coord c) { return *this = (*this + c); }
};

// 지도
class Map {
private:
    // 지도의 각 칸에 적힌 수
    int map[MAX_N][MAX_N] = {{ 0, }};
public:
    // 지도 인덱싱
    int* operator[](int idx) { return map[idx]; }
    int& operator[](coord c) { return map[c.y][c.x]; }
} map;

// 주사위의 각 면의 인덱스
enum Dir { FRONT, UP, RIGHT, LEFT, DOWN, BACK, LEN };

// 주사위
class Dice {
private:
    // 주사위의 각 면
    int side[Dir::LEN] = { 0, };

public:
    // 주사위의 dir번째 면을 val로 설정
    void set_side(int dir, int val) { this->side[dir] = val; }
    // 주사위의 dir번째 면을 반환
    int get_side(int dir) { return this->side[dir]; }

    // 주사위를 dir방향으로 회전
    void rotate(int dir) {
        // dir 방향으로 회전할 때 값을 바꿀 네 면
        int sides[4][4] = {
            {Dir::FRONT, Dir::LEFT, Dir::BACK, Dir::RIGHT},
            {Dir::FRONT, Dir::RIGHT, Dir::BACK, Dir::LEFT},
            {Dir::FRONT, Dir::DOWN, Dir::BACK, Dir::UP},
            {Dir::FRONT, Dir::UP, Dir::BACK, Dir::DOWN}
        };

        // 네 면을 차례로 swap한다
        int temp = get_side(sides[dir][0]);
        for (int i = 0; i < 3; i++)
            set_side(sides[dir][i], get_side(sides[dir][i + 1]));
        set_side(sides[dir][3], temp);
    }
} dice;

int main() {
    // K: 명령의 개수, k: 각 명령
    int K, k;
    // crd: 현재 주사위의 좌표, add: 주사위의 각 방향으로의 변위
    coord crd, add[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d %d %d %d", &N, &M, &(crd.y), &(crd.x), &K);
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) 
        scanf("%d", &map[i][j]);
    
    // 각 명령에 대해
    while (K--) {
        // 명령을 입력받은 뒤
        scanf("%d", &k);

        // 주사위가 지도 밖으로 나갈 것 같다면 continue
        if (!(crd + add[--k]).valid()) continue;

        // 명령을 실행한 뒤
        crd += add[k];
        dice.rotate(k);

        // 이동한 칸의 값이 0이 아니라면 해당 값을 주사위로 이동
        if (map[crd]) {
            dice.set_side(Dir::BACK, map[crd]);
            map[crd] = 0;
        }
        // 그렇지 않다면 주사위의 값을 지도로 복사
        else map[crd] = dice.get_side(Dir::BACK);

        // 주사위의 지도 반대편 쪽 면의 값을 출력
        printf("%d\n", dice.get_side(Dir::FRONT));
    }

    return 0;
}
