#include <iostream>

using namespace std;

#define MAX_N 8

// str: 출력할 수열을 문자열 형태로 저장
char str[2 * MAX_N + 1];
// N: 사용할 자연수의 종류, M: 수열의 길이
int N, M;

void backtrack(int len) {
    // len이 M이라면 수열을 모두 채운 것이므로 수열을 출력한 뒤 종료
    if (len == M * 2) {
        cout << str << '\n';
        return;
    }

    // 1부터 N 중 사용 가능한 수가 있다면
    for (int i = 1; i <= N; i++) {
        // 수열에 추가한 뒤 수열의 다음 수를 채운다
        str[len] = i + '0';
        str[len + 1] = ' ';
        backtrack(len + 2);
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N과 M을 입력받은 뒤 조건을 만족하는 수열을 모두 출력
    cin >> N >> M;
    backtrack(0);
    return 0;
}
