#include <cstdio>

#define LEN 3000
#define CASE 1 << 15

#define abs(n) (n < 0 ? -n : n)
// c가 대문자라면 true, 아니라면 false
#define is_upper(c) (c <= 'Z')
// c가 대문자라면 1, 소문자라면 -1
#define if_upper(c) (is_upper(c) ? 1 : -1)

// a와 b가 같은 대문자거나 같은 소문자라면 true, 아니라면 fasle
bool is_same_case(char a, char b) { return is_upper(a) == is_upper(b); }
// 두 수의 부호가 같다면 true, 아니라면 false
bool is_same_case(short a, short b) { return (a & CASE) == (b & CASE); }

int main() {
    // caps lock이 눌렸다면 true, 아니라면 false
    bool caps = false;
    // 입력할 문자열
    char str[LEN + 1];
    // streak[i]: str[i]가 대문자라면 양수, 소문자라면 음수
    //            str[i]가 속한 연속된 대문자/소문자 집합의 길이
    short streak[LEN] = { 0, };
    // i: 배열에 접근할 인덱스, ans: 키를 누르는 최소 횟수
    int i, ans = 0;

    // 문자를 입력받은 뒤
    scanf("%s", str);

    // 문자열의 첫 글자에 따라 streak의 첫 번째 값을 결정
    streak[0] = if_upper(str[0]);

    // 이후 str의 모든 값에 대해
    for (i = 1; str[i]; i++) {
        // 문자열의 i번째 글자의 대소문자에 따라 1 혹은 -1을 할당하고
        streak[i] = if_upper(str[i]);
        // 이전 값과 부호가 같다면 이전 값을 더해준다
        // 이렇게 하면 각 대/소문자 그룹의 streak값의 절댓값은
        // 1부터 해당 그룹의 길이까지 순차적으로 증가하는 꼴이 된다
        if (is_same_case(str[i], str[i - 1])) streak[i] += streak[i - 1];
    }

    // streak의 값을 각 문자가 속한 그룹의 길이로 변경
    for (--i; i > 0; i--) if (is_same_case(streak[i], streak[i - 1]))
        streak[i - 1] = streak[i];

    // 문자열의 첫 글자가 대문자라면 첫 글자를 입력했을 때의 입력 횟수는 반드시 2
    // 그렇지 않다면 입력 횟수는 반드시 1
    ans = is_upper(str[0]) ? 2 : 1;
    // streak이 1보다 크다는 것은
    // 첫 글자가 속한 그룹이 대문자 그룹이고 길이가 1 초과라는 것
    // 즉, 대문자가 두 글자 이상 연속한 그룹이므로
    // caps lock을 누르는 것이 더 효율적이다
    caps = streak[0] > 1;

    // 이후 두 번째 글짜부터 차례로
    for (i = 1; str[i]; i++) {
        // 현재 글자가 이전 글자와 같은 그룹에 속해 있거나
        // 이전 글자가 shift 키를 누른 결과 다른 그룹에 속하게 되었다면
        // 키를 한 번 누른 것이므로 ans를 1 증가
        if (is_same_case(str[i], str[i - 1]) || caps == is_upper(str[i])) ans++;
        // 그렇지 않은 경우 shift 혹은 caps lock 둘 중 하나는 반드시 누른 것이다
        else {
            // 키를 두 번 누른 것이므로 ans를 2 증가
            ans += 2;
            // 현재 글자의 streak의 절댓값이 1 초과라면
            // 그룹의 길이가 2 이상인 것이므로 caps lock을 누르는 것이 더 효율적이다
            if (abs(streak[i]) > 1) caps = !caps;
        }
    }

    // 키를 누른 최소 횟수를 출력
    printf("%d\n", ans);

    return 0;
}
