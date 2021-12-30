#include <iostream>

using namespace std;

#define MAX 10000000

// cnt[i + MAX]: 숫자카드 i의 개수
int cnt[2 * MAX + 1] = { 0, };

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 가진 숫자카드의 개수, M: 찾을 숫자카드의 개수
    // i: 찾을 각각의 숫자카드의 수
    int N, M, i;

    // 가진 숫자카드를 각각 입력받아 그 개수를 cnt에 저장
    for (cin >> N; N--; ) {
        cin >> i;
        cnt[i + MAX]++;
    }
    // 찾을 숫자카드를 각각 입력받아 그 개수를 출력
    for (cin >> M; M--; ) {
        cin >> i;
        cout << cnt[i + MAX] << ' ';
    }
    // 개행 문자를 출력해 출력을 종료
    cout << '\n';

    return 0;
}
