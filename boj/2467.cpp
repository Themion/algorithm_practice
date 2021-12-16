#include <iostream>

using namespace std;

#define MAX_N 100000

int liq[MAX_N + 1];

// 정수를 입력받아 그 절댓값을 반환
int abs(int n) { return n >= 0 ? n : -n; }

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // l, r: 배열을 탐색하기 위한 두 인덱스
    // a, b: 정답을 출력하기 위한 두 인덱스
    int l = 1, r, a = 0, b = 1;

    // 용액의 수와 각 용액의 특성값을 입력
    cin >> r;
    for (int i = l; i <= r; i++) cin >> liq[i];

    // 투 포인터 실행
    while (l < r) {
        // 두 용액을 합쳤을 때 특성값이 기존 특성값보다 작다면 그 포인터쌍을 저장
        if (abs(liq[l] + liq[r]) < abs(liq[a] + liq[b])) { a = l; b = r; }
        // 포인터를 합친 용액의 특성값에 따라 이동
        liq[l] + liq[r] > 0 ? r-- : l++;
    }

    // 합친 용액의 특성값이 0에 가장 가까운 두 용액의 특성값을 출력
    cout << liq[a] << ' ' << liq[b] << '\n';

    return 0;
}
