#include <iostream>

using namespace std;

#define MAX_K 500
#define INF 0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int test_case() {
    // K: 파일의 수, C[i][j]: i번 파일부터 j번 파일까지 합치는 최소 비용
    // sum[i]: 1번 파일부터 i번 파일까지의 용량의 합
    int K, C[MAX_K + 1][MAX_K + 1] = {{ 0, }}, sum[MAX_K + 1] = { 0, };

    // 문제의 조건을 입력받으며 sum을 갱신
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> C[i][i];
        sum[i] = sum[i - 1] + C[i][i];
    }

    // 각 위치에서 파일을 하나씩 합치면서 최솟값을 계산
    for (int len = 1; len < K; len++) for (int i = 1; i + len <= K; i++) {
        // 아직 합치지 않은 파일의 비용을 INF로 설정
        C[i][i + len] = INF;

        // i와 i + len 사이의 모든 지점에 대해
        // 두 합친 파일 C[i][j]와 C[j][i + len]을 만드는 비용의 최솟값을 저장한 뒤
        for (int j = i; j < i + len; j++)
            C[i][i + len] = min(C[i][i + len], C[i][j] + C[j + 1][i + len]);

        // 두 파일을 합친 파일 C[i][i + len]을 만드는 비용을 더해 비용을 완성시킨다
        C[i][i + len] += sum[i + len] - sum[i - 1];
    }

    // 모든 파일을 합치는 비용의 최솟값을 반환
    // 이 때 원래 0이어야 할 각 C[i][i]를 i번째 파일의 크기로 설정했으므로
    // 오차를 바로잡기 위해 모든 파일의 크기의 합을 뺀 값을 반환한다
    return C[1][K] - sum[K];
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    // 테스트 케이스의 수를 입력받고 각 테스트 케이스를 실행
    for (cin >> T; T--; ) cout << test_case() << '\n';
    return 0;
}
