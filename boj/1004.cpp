#include <cstdio>

int sq(int s) { return s * s; }

int test_case() {
    // ss: 각 행성계에 대해 시작점이 행성계 안에 있을 경우 true, 아니라면 false
    // ee: 각 행성계에 대해 끝점이　 행성계 안에 있을 경우 true, 아니라면 false
    bool ss, ee;
    // s: 시작점의 좌표, e: 도착점의 좌표
    // p: p[0], p[1]: 각 행성계의 중심의 좌표, p[2]: 행성계의 반지름
    // cnt: 주어진 행성계의 수, ret: 최소 행성계 통과 횟수
    int s[2], e[2], p[3], cnt, ret = 0;

    // 시작점과 끝점의 좌표, 그리고 행성계의 수를 입력받는다
    scanf("%d %d %d %d\n%d", &s[0], &s[1], &e[0], &e[1], &cnt);

    // 각 행성계에 대해
    while (cnt--) {
        // 행성계의 중심의 좌표와 반지름을 입력받은 뒤
        scanf("%d %d %d", &p[0], &p[1], &p[2]);

        // 시작점과 끝점이 행성계 안에 존재하는지 판정한다
        ss = sq(s[0] - p[0]) + sq(s[1] - p[1]) < sq(p[2]);
        ee = sq(e[0] - p[0]) + sq(e[1] - p[1]) < sq(p[2]);

        // 시작점과 끝점이 행성계의 경계에 대해 서로 반대편에 위치한다면
        // 시작점에서 끝점으로 가기 위해 행성계의 경계를 한번 통과해야 한다
        ret += ss != ee;
    }

    // 최소 행성계 통과 횟수를 반환한다
    return ret;
}

int main() {
    int T;

    // 테스트 케이스의 수를 입력받은 뒤
    scanf("%d", &T);
    // 각 테스트 케이스를 실행한다
    while (T--) printf("%d\n", test_case());

    return 0;
}