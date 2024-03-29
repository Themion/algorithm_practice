#include <cstdio>

// e[a][b]: a^(b % 4)의 1의 자리 수
int e[10][4] = {{10, 10, 10, 10},
                { 1,  1,  1,  1},
                { 6,  2,  4,  8},
                { 1,  3,  9,  7},
                { 6,  4,  6,  4},
                { 5,  5,  5,  5},
                { 6,  6,  6,  6},
                { 1,  7,  9,  3},
                { 6,  8,  4,  2},
                { 1,  9,  1,  9}};
 
int main() {
    // T: 테스트 케이스의 수
    // a, b: a^b의 1의 자리 수를 구할 때 필요한 데이터
    int T, a, b;

    // 테스트 케이스를 입력받아 각 테스트 케이스마다
    scanf("%d", &T);
    while (T--) {
        // a와 b를 입력받는다
        scanf("%d %d", &a, &b);
        // a^b의 1의 자리 수는 (a % 10)^(b % 4)의 1의 자리 수와 같다
        printf("%d\n", e[a % 10][b % 4]);
    }

    return 0;
}
