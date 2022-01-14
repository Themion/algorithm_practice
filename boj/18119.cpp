#include <iostream>
#include <string>

using namespace std;

#define INIT 0b11111111111111111111111111
#define MAX_N 10000
#define MAX_LEN 1000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 쿼리의 문자 부분
    char x;
    // N: 문자열의 개수, M: 쿼리의 개수, cnt: 각 쿼리 당 기억한 문자열의 수
    // bitmask: 현재 기억한 문자, item: 각 문자열이 가진 문자를 비트마스크 형태로 표시
    int N, M, cnt, bitmask = INIT, item[MAX_N] = { 0, };
    // 기억하고자 하는 각 문자열
    string str;

    // 문자열과 쿼리의 수를 입력받는다
    cin >> N >> M;
    
    // 각 문자열에 대해
    for (int i = 0; i < N; i++) {
        // 문자열을 입력받은 뒤
        cin >> str;
        // 문자열이 가진 모든 문자를 비트마스크 형태로 표기해 저장
        for (char c : str) item[i] |= 1 << (c - 'a');
    }

    // 각 쿼리에 대해
    while (M--) {
        // 쿼리를 입력받은 뒤 입력받은 쿼리의 실행 결과를 비트마스크 형태로 저장
        cin >> cnt >> x;
        bitmask ^= (1 << (x - 'a'));

        // 각 문자열에 대해 비트 연산으로 문자열의 모든 문자를 기억하는지 계산
        cnt = 0;
        for (int i = 0; i < N; i++)
            cnt += (bitmask & item[i]) == item[i];

        // 기억하는 문자열의 수를 출력
        cout << cnt << '\n';
    }

    return 0;
}
