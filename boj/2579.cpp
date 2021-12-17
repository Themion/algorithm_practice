#include <cstdio>

#define MAX_N 300

// stair: 계단의 각 칸이 가진 가중치
// pt[i]: i == 0: 직전에 한 칸 뛰어 연속 두 칸을 밟았을 경우 최댓값
//        i == 1: 직전에 두 칸 뛰어 연속 한 칸을 밟았을 경우 최댓값
int stair[MAX_N], pt[2][MAX_N];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // 이동할 계단의 수
    int num;

    // 문제의 조건을 입력받는다
    scanf("%d", &num);
    for (int i = 0; i < num; i++) scanf("%d", &stair[i]);

    // 총 한 칸 올라간 경우 두 칸 뛸 수는 없다
    pt[0][0] = stair[0];
    pt[1][0] = 0;

    // 총 두 칸 올라간 경우 알고리즘과 다르게 두 번 연속으로 한 칸씩 뛸 수 있다
    pt[0][1] = stair[0] + stair[1];
    pt[1][1] = stair[1];

    // 마지막으로 한 칸을 뛰었을 경우 그 전에 한 칸을 뛰는 것은
    // 계단 세 개를 연속으로 밟은 것이므로 불가능
    for (int i = 2; i < num; i++) {
        pt[0][i] = stair[i] + pt[1][i - 1];
        pt[1][i] = stair[i] + max(pt[0][i - 2], pt[1][i - 2]);
    }

    //직전에 한 칸 뛴 경우와 두 칸 뛴 경우를 비교해 가중치가 큰 쪽을 출력한다
    printf("%d\n", max(pt[0][num - 1], pt[1][num - 1]));

    return 0;
}
