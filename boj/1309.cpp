#include <cstdio>

#define MAX_N 100'000
#define RMN 9901

// cage[i][j]: 우리가 2 * i 크기일 때, 맨 아래쪽 두 칸에 대해
//             j % 2 == 1이라면 왼쪽 칸에, j / 2 == 1이라면 오른쪽 칸에
//             사자가 있다고 생각하고 이 때의 경우의 수
short cage[MAX_N][3] = {1, 1, 1};

int main() {
    // 우리의 크기를 입력받는다
    int N;
    scanf("%d", &N);

    // 우리의 칸이 2 * 1일 때의 경우의 수는 자명하므로 
    // 칸이 두 칸일 때부터 계산한다
    for (int i = 1; i <= N; i++) {
        // 두 칸 모두 사자가 없는 경우의 수는
        // 이전 칸까지에서의 모든 경우의 수의 합과 같다
        cage[i][0] = (cage[i - 1][0] + cage[i - 1][1] + cage[i - 1][2]) % RMN;
        // 왼쪽 칸에 사자가 있는 경우는 
        // 이전 칸의 왼쪽에 사자가 없는 경우의 수와 같다
        cage[i][1] = (cage[i - 1][0] + cage[i - 1][2]) % RMN;
        // 오른쪽 칸에 사자가 있는 경우는 
        // 이전 칸의 오른쪽에 사자가 없는 경우의 수와 같다
        cage[i][2] = (cage[i - 1][0] + cage[i - 1][1]) % RMN;
    }

    // 구하고자 하는 경우의 수는 우리의 칸이 2 * (N + 1)일 때
    // 맨 마지막 칸의 양쪽에 사자가 없는 경우의 수와 같다
    printf("%d\n", cage[N][0]);

    return 0;
}
