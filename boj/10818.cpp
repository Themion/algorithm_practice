#include <iostream>

using namespace std;

#define MAX 1000000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 입력받을 정수의 개수, i: 입력받을 각 정수, min, max: 입력의 최솟값 / 최댓값
    int N, i, min = MAX, max = -MAX;

    // 각 정수를 입력받은 뒤 최솟값 / 최댓값과 비교해 갱신
    for (cin >> N; N--; ) {
        cin >> i;
        if (min > i) min = i;
        if (max < i) max = i;
    }

    // 최솟값과 최댓값을 각각 출력
    cout << min << ' ' << max << '\n';

    return 0;
}
