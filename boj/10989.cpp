#include <iostream>

using namespace std;

#define MAX 10000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 입력받을 수의 개수, i: 입력받을 각 수, cnt[i]: 수 i가 나온 개수
    int N, i, cnt[MAX + 1] = { 0, };

    // 수를 N번 입력받아 cnt에 나온 횟수를 저장
    for (cin >> N; N--; ) {
        cin >> i;
        cnt[i]++;
    }
    // 각 수를 나온 횟수만큼 출력
    for (N = 0; N <= MAX; N++) for (i = 0; i < cnt[N]; i++)
        cout << N << '\n';

    return 0;
}
