#include <cstdio>

#define next_v (v * m) % 10

// 영재의 산책 속력을 각 초마다 나열해 보면
// 초기 속도를 제외한 속력의 주기는 4의 약수가 된다.
// 따라서 영재의 산책의 초기 속력을 제외하면 각 방향으로 이동하는 속력은 항상 같으므로
// 이를 이용해서 영재의 최종 위치를 상수 시간 안에 계산할 수 있다.

class coord {
public:
    // 현재 좌표의 y, x값
    int y, x;
    
    // 생성자
    coord() { this->y = this->x = 0; }
    coord(int y, int x) { this->y = y; this->x = x; }

    // 좌표의 덧셈 연산
    coord operator+=(coord other) {
        this->y += other.y;
        this->x += other.x;
        return *this;
    }
    // 좌표값을 num배한 좌표값
    coord operator*(int num) {
        return { this->y * num, this->x * num };
    }
};

int main() {
    // v: 영재의 속도, m: 속도 변위의 규칙, t: 총 산책 시간
    int v, m, t, i = 0;
    // ans: 영재의 최종 위치, add[i]: {북, 동, 남, 서}[i] 방향 변위값
    coord ans, add[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d %d", &v, &m, &t);

    // 영재의 산책의 첫 k(<=4) 초 부분은 brute force로 계산한 뒤
    while (!i || i % 4 != t % 4) {
        ans += add[i++] * v;
        v = next_v;
    }

    // 이후 각 방향으로의 산책 속도는 항상 일정하므로
    // 해당 방향으로의 이동 거리를 변위 * 속도 * 시간을 통해 계산
    for (int j = 0; j < 4; j++) {
        ans += add[(i + j) % 4] * v * ((t - i) / 4);
        v = next_v;
    }

    // 영재의 최종 위치를 형식에 맞게 출력
    printf("%d %d\n", ans.x, ans.y);

    return 0;
}
