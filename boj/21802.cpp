#include <iostream>

using namespace std;

#define MAX_N 100000
#define MIN(a, b) (a < b ? a : b)

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 논문의 개수, L: 참조 가능한 논문의 수
    // c[i]: 참조된 횟수가 i 이하인 논문의 개수
    // buf: 임시로 값을 저장할 공간
    int N, L, c[MAX_N + 1] = { 0, }, buf;

    // 논문의 개수와 참조 가능한 논문의 수를 입력받은 뒤
    cin >> N >> L;
    // 각 논문에 대해
    for (int i = 0; i < N; i++) {
        // 논문이 참조된 횟수를 입력받은 뒤
        cin >> buf;
        // 해당 횟수만큼 참조된 논문의 수를 1 늘린다
        c[buf]++;
    }

    // c[i]에 i번 미만 참조된 논문의 개수를 더한 뒤
    for (int i = MAX_N; i > 0; i--) c[i - 1] += c[i];
    // 선형 탐색을 통해 h-인덱스를 계산
    for (buf = N; buf > 0; buf--) if (c[buf] >= buf) break;

    // 새로 작성하는 논문에서 buf개 참조된 논문을 가능한 한 많이 참조하여
    // h-인덱스를 늘릴 수 있다면 해당 논문들을 참조한다
    buf += (c[buf + 1] + MIN(c[buf] - c[buf + 1], L) >= buf + 1);

    // 논문을 작성한 뒤의 h-인덱스를 출력
    cout << buf << '\n';

    return 0;
}
