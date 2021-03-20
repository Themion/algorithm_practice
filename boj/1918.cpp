#include <cstdio>

// 연산자의 우선순위가 두 종류 뿐이므로
// 스택의 최대 크기 역시 2
char s[2];

// 연산자 c의 우선순위를 계산하여 출력
int order(char c)
{
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

char input(int i)
{
    // 스택의 시작점을 입력받은 인덱스로 잡는다
    int idx = i;
    // 식의 문자를 한글자씩 차례대로 입력받는다
    char buf;

    while (true)
    {
        scanf("%c", &buf);

        // 괄호가 시작되면 괄호 안의 식을 후위식으로 변환
        if (buf == '(') input(idx);
        // 식이 끝나면 스택에 넣어둔 연산자를 전부 출력
        else if (buf == ')' || buf == '\n')
        {
            while (idx > i) printf("%c", s[--idx]);
            return buf;
        }
        // 상수를 입력받았다면 상수를 그대로 출력
        else if (buf >= 'A' && buf <= 'Z') printf("%c", buf);
        // 연산자를 입력받았다면
        else 
        {
            // 입력받은 연산자보다 우선순위가 높거나 같은 연산자를
            // 스택에서 차례로 출력
            while (idx > i && order(s[idx - 1]) >= order(buf))
                printf("%c", s[--idx]);
            // 그 후 입력받은 연산자를 스택에 push
            s[idx++] = buf;
        }
    }
}

int main()
{
    // 식을 input 함수 안에서 입력받은 뒤
    // 개행 문자를 입력받았을 떄 그 문자를 그대로 출력
    printf("%c", input(0));

    return 0;
}