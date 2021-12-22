#include <iostream>
#include <stack>

using namespace std;

// a와 b가 맞는 괄호 쌍인지 여부를 반환
bool match(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

bool test_case(char c) {
    bool ret = true;
    stack<char> s;

    // 문자열의 모든 문자에 대해
    do {
        // 현재 문자가 괄호를 여는 문자라면 s에 push
        if (c == '(' || c == '[') s.push(c);
        // s의 top과 맞는 꼴의 닫는 괄호라면 s에서 괄호를 하나 pop
        else if (!s.empty() && match(s.top(), c)) s.pop();
        // s의 top과 맞지 않는 닫는 괄호라면 정답은 false
        else if (c == ')' || c == ']') ret = false;
    } while ((c = cin.get()) != '\n');

    // 문자열의 모든 괄호가 전부 정상적으로 닫혔는지 여부를 반환
    return ret && s.empty();
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c;
    // 시작이 .이 아닌 모든 테스트 케이스가 균형잡힌 괄호인지 여부를 출력
    while ((c = cin.get()) != '.') cout << (test_case(c) ? "yes" : "no") << '\n';
    
    return 0;
}
