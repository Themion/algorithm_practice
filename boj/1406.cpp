#include <iostream>
#include <stack>

using namespace std;

// f, b: 커서를 기준으로 각각 문자열의 앞, 뒤를 저장할 스택
stack<char> f, b;

// 명령 c를 분석해 그에 맞는 작업을 실행
void command(char c) {
    switch (c) {
    // 명령이 L이라면 커서를 오른쪽으로 이동
    case ('L'):
        // f가 비어있지 않을 때 f의 top을 b로 옮긴다
        if (!f.empty()) {
            b.push(f.top());
            f.pop();
        }
        break;
    // 명령이 D라면 커서를 왼쪽으로 이동
    case ('D'):
        // b가 비어있지 않을 때 b의 top을 f로 옮긴다
        if (!b.empty()) {
            f.push(b.top());
            b.pop();
        }
        break;
    // 명령이 B라면 커서 앞의 글자를 제거
    case ('B'):
        // f에 값이 있는 경우 f의 back을 pop한다
        if (!f.empty()) f.pop();
        break;
    // 명령이 P라면
    case ('P'):
        // 문자열에 넣을 문자를 입력받아 f의 뒤에 push한다
        cin >> c;
        f.push(c);
        break;
    }
    // 개행 문자를 입력받아 버린다
    cin.get();
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력에 사용할 버퍼
    char buf;
    // 문자열에 가할 명령의 수
    int T;

    // 해당 문자열이 공백이 아니라면 f에 push한다
    // 이 과정을 buf에 \n이 들어올 때까지 반복한다
    while ((buf = cin.get()) != '\n') f.push(buf);
    // 문자열에 가할 명령의 수를 입력받는다
    cin >> T;
    cin.get();

    // 각 명령에 대해 명령에 맞는 작업을 실행
    while (T--) command(cin.get());

    // f를 b에 모두 저장한 뒤
    while (!f.empty()) {
        b.push(f.top());
        f.pop();
    }

    // b를 차례로 출력
    while (!b.empty()) {
        cout << b.top();
        b.pop();
    }

    // 모든 동작을 끝마쳤으므로 개행 문자를 출력해 출력을 마친다
    cout << '\n';

    return 0;
}
