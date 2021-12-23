#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

#define MAX_P 100000

void test_case() {
    // 배열이 뒤집혔다면 true, 아니라면 false
    bool flip = false;
    char buf;
    int n, item = 0;
    // 배열의 값들을 deque 형태로 저장한다
    deque<int> d;
    // 실행할 함수의 집합
    string p;

    // 명령어와 배열의 크기를 입력받는다
    cin >> p >> n;
    cin.get();

    // 배열을 한 글자씩 입력받는다
    while ((buf = cin.get()) != '\n') {
        // 입력받은 글자가 숫자라면 push할 숫자의 뒤에 붙인다
        if (buf >= '0' && buf <= '9') item = 10 * item + buf - '0';
        // 입력받은 글자가 문자라면 0이 아닌 item을 push한 뒤 item을 초기화
        else if (item) {
            d.push_back(item);
            item = 0;
        }
    }

    // 명령어를 글자 단위로 실행한다
    for (char c : p) {
        // 해당 글자가 R이라면 배열을 뒤집는다
        if (c == 'R') flip = !flip;
        // 해당 글자가 D일 때
        else if (c == 'D') {
            // 배열 안에 원소가 없다면 error를 출력한 뒤 종료
            if (d.empty()) {
                cout << "error\n";
                return;
            }
            // 배열이 뒤집혀있다면 배열의 back을, 그렇지 않다면 front를 제거
            flip ? d.pop_back() : d.pop_front();
        }
    }

    // 명령어를 배열 꼴로 출력
    cout << '[';
    while (!d.empty()) {
        // 배열이 뒤집혀 있다면 d의 back을 순차적으로 출력
        if (flip) {
            cout << d.back();
            d.pop_back();
        }
        // 그렇지 않다면 d의 front를 순차적으로 출력
        else {
            cout << d.front();
            d.pop_front();
        }
        // 배열의 각 성분을 ','로 구분
        if (!d.empty()) cout << ',';
    }
    // 배열을 닫고 출력을 종료
    cout << "]\n";
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    for (cin >> T; T--; ) test_case();

    return 0;
}
