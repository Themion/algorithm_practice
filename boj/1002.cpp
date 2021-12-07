#include <cmath>
#include <cstdio>

int test_case() {
    // x1, y1: 조규현의 좌표
    // x2, y2: 백승환의 좌표
    // r1, r2: 조규환과 백승환이 계산한 거리
    // plus: 두 거리의 합, minus: 두 거리의 차
    // ret: 조규환과 백승환을 중심으로 거리가 r1, r2인 두 원의 위치 관계
    int x1, y1, r1, x2, y2, r2, plus, minus, ret = 0;
    // 조규환과 백승환의 거리
    double d;
    
    // 문제의 조건을 입력받은 뒤
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    // 둘이 측정한 거리의 합과 차를 계산
    plus = r1 + r2; minus = abs(r1 - r2);
    // 둘의 거리를 계산
    d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    // 둘의 거리와 둘이 계산한 거리에 따라 원의 위치 관계를 측정한다
    if (x1 == x2 && y1 == y2 && r1 == r2) ret = -1;
    else if (d > plus || d < minus) ret = 0;
    else if (d == plus || d == minus) ret = 1;
    else if (d < plus && d > minus) ret = 2;

    // 측정한 위치 관계를 반환
    return ret;
}

int main() {
    int T;
    // 테스트 케이스의 수를 입력받는다
    scanf("%d", &T);
    // T만큼 테스트 케이스를 반복
    while (T--) printf("%d\n", test_case());

    return 0;
}
