#include <cstdio>
#include <map>

using namespace std;

#define MAX_D 2000

// 유클리드 호제법을 이용해 a와 b의 최대공약수를 계산
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    // down: 수직 아래에 있는 좌석을 사용한다면 true, 아니라면 false
    // visit[a][b]: 각도 a / b 지점에 있는 좌석을 사용했다면 true
    bool down, visit[MAX_D + 1][MAX_D + 1] = {{ 0, }};
    // d1, d2: 좌석을 놓을 두 원의 반지름, div: 최대공약수
    // ans: 무대에 사용할 좌석의 수
    int d1, d2, div, ans = 0;
    
    // 두 반지름을 입력받은 뒤
    scanf("%d %d", &d1, &d2);

    // d1과 d2가 다르거나 유일한 원의 반지름이 짝수라면
    // 무대에서 수직 아래에 있는 좌석을 사용하게 된다
    down = d2 > d1 || d2 % 2 == 0;

    // 무대의 한쪽 옆에 있는 좌석 중 사용 가능한 좌석의 수를 계산
    for (int p = d1; p <= d2; p++) for (int q = 1; q < p / 2 + p % 2; q++) {
        // 각 좌석과 중심을 잇는 선분이 수직선과 이루는 각도 p / q에 대해
        // 좌석의 각도가 p / q인 좌석이 이미 나왔는지 확인하기 위해
        // p과 q의 최대공약수를 구해 기약분수 꼴로 저장한다
        div = gcd(p, q);

        // 각도 p / q에 사용한 좌석이 없다면 현재 좌석을 사용
        ans += visit[p / div][q / div] == false;
        // 각도 p / q에 있는 좌석을 사용했음을 표시
        visit[p / div][q / div] = true;
    }

    // 구한 좌석의 수는 무대의 한쪽 옆에 있는 좌석뿐
    // 좌석의 배치는 선대칭이므로 구한 좌석의 수에 2를 곱한 뒤
    // 반드시 사용되는 수직 위 좌석, 경우에 따라 사용되는 수직 아래 좌석의
    // 사용 여부를 더한 값을 출력한다
    printf("%d\n", 2 * ans + down + 1);

    return 0;
}
