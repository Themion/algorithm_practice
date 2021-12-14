#include <iostream>

using namespace std;

#define INF 900000

// prev[i]: 처음부터 바로 직전의 i번째 칸까지 이동할 때 
//          얻을 수 있는 점수의 최대/최솟값
int max_[2][3], min_[2][3];

void set_max(int &a, int b) { a = a > b ? a : b; }
void set_min(int &a, int b) { a = a < b ? a : b; }

void dp(bool idx) {
    // 현재 줄의 세 칸
    int now[3];

    // 현재 층에서의 최댓값 / 최솟값을 초기화
    fill_n(max_[idx], 3, 0);
    fill_n(min_[idx], 3, INF);

    // 현재 층의 점수를 저장
    cin >> now[0] >> now[1] >> now[2];

    // 이전 칸에서 i번쨰 칸에 도착할 수 있는 세 칸에 대해
    for (int i = 0; i < 3; i++) for (int j = i - 1; j <= i + 1; j++) {
        // 칸의 인덱스가 범위를 벗어났다면 continue
        if (j < 0 || j > 2) continue;
        // i번째 칸에 도착할 수 있는 값의 최대/최소값을 저장
        max_[idx][i] = max(max_[idx][i], max_[!idx][j] + now[j]);
        min_[idx][i] = min(min_[idx][i], min_[!idx][j] + now[j]);
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    // 층 수를 입력받은 뒤 각 층마다 최댓값과 최솟값을 계산
    cin >> N;
    for (int i = 0; i < N; i++) dp(i % 2);

    // 모든 칸에서의 최대/최소값을 게산하여 출력
    for (int i = 1; i < 3; i++) {
        max_[!(N % 2)][0] = max(max_[!(N % 2)][0], max_[!(N % 2)][i]);
        min_[!(N % 2)][0] = min(min_[!(N % 2)][0], min_[!(N % 2)][i]);
    }
    cout << max_[!(N % 2)][0] << ' ' << min_[!(N % 2)][0] << '\n';

    return 0;
}
