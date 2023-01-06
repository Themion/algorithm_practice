#include <iostream>

using namespace std;

#define MAX_N 999
#define DIR 4

// 표의 좌표
class coord {
public:
    // 표에서의 세로 좌표
    int x;
    // 표에서의 가로 좌표
    int y;
    // 좌표의 이동 방향
    int dir;
    void print() { cout << x + 1 << ' ' << y + 1 << '\n'; }
};
// 두 좌표의 덧셈 연산을 오버로딩
coord operator+(coord a, coord b) { return { a.x + b.x, a.y + b.y, a.dir }; }

// 달팽이 모양 표
class board {
public:
    // 표의 한 변의 길이
    int N;
    // 표를 저장할 공간
    int table[MAX_N][MAX_N] = {{ 0, }};
    // 좌표의 각 방향으로의 변위
    coord delta[DIR] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    /// @brief 임의의 좌표 c를 인자로 받아 c가 표 안에 포함되는지 여부를 반환 
    /// @param c 표 안에 포함되는지 검토할 좌표
    /// @return c가 표 안에 포함된다면 true, 아니라면 false
    bool is_coord_valid(coord c) { return (c.x >= 0 && c.x < N && c.y >= 0 && c.y < N); }

    /// @brief 표 안의 특정 좌표를 탐색하기 위한 operator
    /// @param i 표의 가로열 번호
    /// @return 표의 가로열 포인터
    int *operator[](int i) { return table[i]; }

    /// @brief 표 안의 특정 좌표를 탐색하기 위한 operator
    /// @param c 표의 좌표
    /// @return 표의 특정 좌표의 레퍼런스
    int &operator[](coord c) { return table[c.x][c.y]; }

    /// @brief 임의의 좌표 c를 인자로 받아 해당 좌표의 다음 좌표를 계산
    /// @param c 다음 좌표를 계산할 좌표
    /// @return 인자로 받은 좌표 c의 다음 좌표
    coord next(coord c) {
        // c의 다음 좌표를 저장할 공간
        coord c_;
        
        // 좌표 c를 dir 방향으로 한 칸 이동
        c_ = c + delta[c.dir];
        // 만일 c_가 표를 벗어나거나, c_ 위치가 이미 값이 있는 경우
        if (!is_coord_valid(c_) || (*this)[c_] != 0)
            // 방향을 바꿔서 한 칸 이동
            c_ = c + delta[c.dir = (c.dir + 1) % DIR];

        // c_를 반환
        return c_;
    }

    /// @brief 현재 표를 출력
    void print() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (*this)[i][j] << ' ';
            cout << '\n';
        }
    }
};

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 표에서 찾고자 하는 수
    int num;
    // 표 b를 순회하기 위한 인덱스
    coord c = {0, 0, 0};
    // num_idx: 표에서 찾은 수 num의 인덱스
    coord num_idx;
    // 달팽이 모양 표를 저장할 공간
    board b;

    // 표의 크기와 찾고자 하는 수를 입력받은 뒤
    cin >> b.N >> num;

    // 표를 가장 큰 수부터 차례로 채움
    for (int k = b.N * b.N; k >= 1; k--) {
        // 찾고자 하는 수를 채우기 직전에 해당 수의 좌표를 저장
        if (k == num) num_idx = c;

        b[c] = k;
        c = b.next(c);
    }

    // 표와 찾고자 하는 수의 좌표를 각각 출력
    b.print();
    num_idx.print();

    return 0;
}
