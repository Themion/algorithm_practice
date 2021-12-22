#include <iostream>

using namespace std;

int cmp(int a, int b) { return a > b ? a : b; }

void test_case() {
    // len: 막대의 길이, n: 개미의 수, p: 각 개미의 위치
    // min, max: 개미가 전부 떨어지기까지의 최소/최대 시간
    int len, n, p, min = 0, max = 0;

    cin >> len >> n;
    
    while (n--) {
        // 각 개미의 위치를 p에 저장한 뒤
        cin >> p;
        // p에 양쪽 끝으로 이동하는 시간 중 짧은 쪽을 저장한 뒤
        // 모든 개미가 떨어져야 하므로 min과 비교해 더 큰 쪽을 min으로 지정한다
        p = p < len / 2 ? p : len - p;
        min = cmp(min, p);
        // p를 len - p로 바꾼 뒤 max와 비교해 더 큰 쪽을 max로 지정한다
        p = len - p;
        max = cmp(max, p);
    }
    // 개미가 떨어지기까지의 최소/최대 시간을 출력한다
    cout << min << ' ' << max << '\n';
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 테스트 케이스의 수
    int T;
    cin >> T;

    while(T--) test_case();

    return 0;
}
