#include <iostream>
#include <stack>

using namespace std;

#define MAX_LEN 36

// from에서 to로 인자 하나를 옮긴다
void move(stack<char> &from, stack<char> &to) {
    to.push(from.top());
    from.pop();
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // buf: 스택에 값을 넣기 위한 버퍼
    // str: 폭발 문자열
    char buf, str[MAX_LEN];
    // len: 폭발 문자열의 길이, i: 폭발 문자열에 접근하기 위한 인덱스
    int len = 0, i;
    // s: 폭발 문자열을 찾을 문자열을 저장한 스택
    // s_: s에서 출력할 값을 저장할 스택
    stack<char> s, s_;

    // 폭발 문자열을 찾을 문자열과 폭발 문자열을 입력받은 뒤
    while ((buf = cin.get()) != '\n') s.push(buf);
    for (; (str[len] = cin.get()) != '\n'; len++);
    // 폭발 문자열에 접근할 인덱스를 초기화
    i = len - 1;

    // 스택 안의 모든 문자에 대해
    while (!s.empty()) {
        // s에서 폭발 문자열의 i번째 글자를 찾았다면 i를 1 줄이고,
        // 그렇지 않다면 i를 len - 1로 맞춘 뒤 맨 마지막 글자만 비교
        i = (s.top() == str[i]) ? i - 1 : len - 1 - (s.top() == str[len - 1]);
        // s.top이 폭발 문자열의 문자든 아니든 우선 s_에 넣는다
        move(s, s_);

        // i가 음수라면, 즉 s에서 폭발 문자열을 모두 찾았다면
        if (i < 0) {
            // s_에서 폭발 문자열을 제거한 뒤
            for (; i < len - 1; i++) s_.pop();
            // s_에서 폭발 문자열의 마지막 글자까지, 혹은 s_ 전체를 원상복구해서
            // 처음부터 다시 모든 과정을 반복
            while (!s_.empty() && (!s.empty() && s.top() != str[len - 1]))
                move(s_, s);
        }
    }

    // s_가 비었다면 s는 폭발 문자열만으로 이루어져 있던 것이므로 "FRULA" 출력
    if (s_.empty()) cout << "FRULA";
    // 아니라면 s에서 폭발 문자열을 모두 제거한 결과를 출력
    else while (!s_.empty()) {
        cout << s_.top();
        s_.pop();
    }
    // 개행 문자를 출력해 출력을 종료
    cout << '\n';

    return 0;
}
