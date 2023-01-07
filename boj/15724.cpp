#include <iostream>

using namespace std;

#define MAX_N 1024

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 영토의 세로 크기
    int N;
    // 영토의 가로 크기
    int M;
    // 특정 범위의 인구수를 구할 횟수
    int K;
    // 특정 지점으로부터 각 구역의 인구수의 합
    int sum[MAX_N + 1][MAX_N + 1];
    // 인구수를 구할 직사각형의 가로 변의 좌표
    int x[2];
    // 인구수를 구할 직사각형의 세로 변의 좌표
    int y[2];

    // 각 구역의 인구수를 입력받아 인구수의 합을 계산
    cin >> N >> M;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
        cin >> sum[i][j];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++)
        sum[i][j] += sum[i][j - 1];
    for (int j = 1; j <= M; j++) for (int i = 1; i <= N; i++)
        sum[i][j] += sum[i - 1][j];

    cin >> K;
    // 각 테스트 케이스에 대해 구역의 합을 빠르게
    while (K--) {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        cout << sum[x[1]][y[1]] - sum[x[0] - 1][y[1]] - sum[x[1]][y[0] - 1] + sum[x[0] - 1][y[0] - 1] << '\n';
    }

    return 0;
}
