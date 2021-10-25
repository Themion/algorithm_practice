#include <cstdio>
#include <deque>

using namespace std;

typedef deque<char> deq;

// 괄호 문자 c가 각각 여는 괄호라면, 혹은 대괄호라면 true
bool is_opening_brac(char c) { return c == '(' || c == '['; }
bool is_big_brac(char c) { return c == '[' || c == ']'; }
// 두 문자 l, r이 연속해서 올 수 있는 경우에만 true
bool is_valid(char l, char r) 
{ return !(l == '(' && r == ']') && !(l == '[' && r == ')'); }

int peel_brac(deq q);
int split_brac(deq q);

// 괄호 문자열 q의 시작과 끝 두 문자를 제거한 뒤
// 두 괄호 문자가 연속해서 올 수 있다면 q에 대해 split_brac, 아니라면 -1을 반환
int peel_brac(deq q)
{
    if (q.empty()) return 0;

    char left = q.front(), right = q.back();
    q.pop_front();
    q.pop_back();

    if (left == '(' && right == ')') return 2 * split_brac(q);
    if (left == '[' && right == ']') return 3 * split_brac(q);

    return -1;
}

// 여러 괄호 문자열을 붙인 괄호 문자열 q를 각각의 괄호 문자열로 떼어낸 뒤
// 각 괄호 문자열이 옳은 문자열이라면 그 점수를, 아니라면 -1을 반환
int split_brac(deq q)
{
    // 빈 문자열을 옳은 괄호 문자열로 간주하고 그 점수를 1로 설정
    if (q.empty()) return 1;

    // ret: q의 총 점수
    // small, big: 소괄호, 대괄호의 깊이
    int ret = 0, small, big;
    // valid: 괄호 문자열이 옳은 문자열이라면 true, 아니라면 false
    bool valid = true;
    // q의 시작점에서 시작하는 부분 문자열을 저장하는 공간
    deq s;

    // q가 옳은 문자열인 동안 q를 탐색
    while (!q.empty() && valid)
    {
        // 부분 문자열 s와 s의 깊이를 초기화
        small = big = 0;
        s = deq();

        // q의 시작점에서 시작하는 옳은 부분 문자열을 탐색
        do {
            // q의 앞에서부터 차례로 s에 옮김
            char c = q.front();
            s.push_back(c);
            q.pop_front();

            // s의 깊이를 갱신
            (is_big_brac(c) ? big : small) += (is_opening_brac(c) ? 1 : -1);

            // 연속해서 올 수 없는 문자가 발견된다면 valid를 false로 갱신
            valid = valid && is_valid(s.back(), q.front());
        } while (!q.empty() && valid && (small > 0 || big > 0));


        // 옳은 부분 문자열 s가 발견된다면 s에 대해 peel_brac을 실행
        int res = peel_brac(s);
        // s가 옳은 부분 문자열이었다면 ret에 s의 점수를 더한다
        if (res >= 0) ret += res;
        // s가 틀린 부분 문자열이었다면 -1을 반환
        else return -1;
    }

    // 문자열의 점수에 valid, 부분 문자열의 깊이를 곱해 최종 점수를 반환
    return ret * valid * !(small || big);
}

int main()
{
    char buf;
    int ans;
    deq input;
    
    // 문자를 하나씩 입력받아 deque에 저장
    do {
        scanf("%c", &buf);
        input.push_back(buf);
    } while (buf != '\n');

    // 맨 마지막에 줄바꿈 문자가 들어갔으므로 이를 pop
    input.pop_back();

    // 문자열의 점수를 계산
    ans = split_brac(input);

    // 문자열의 점수가 양수라면 점수를, 그렇지 않다면 0을 출력
    printf("%d\n", ans > 0 ? ans : 0);

    return 0;
}