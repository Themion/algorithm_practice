#include <iostream>

using namespace std;

#define MAX_N 1024

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 표의 행과 열의 수, M: 쿼리의 개수
    // sum[i][j]: 1행 1열부터 i행 j열까지 모두 더한 값
    // i, j: 인덱스
    int N, M, sum[MAX_N + 1][MAX_N + 1] = {{ 0, }}, x1, y1, x2, y2;

    // 수의 개수와 쿼리의 개수를 입력받은 뒤 각 수를 입력받아 합을 sum에 저장
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> x1;
            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + x1;
        }

    
    // 각 쿼리마다
    while (M--) {
        // 합을 구할 구간을 입력받은 뒤 구간에 맞는 합을 출력
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[--x1][y2] - sum[x2][--y1] + sum[x1][y1] << '\n';
    }

    return 0;
}
