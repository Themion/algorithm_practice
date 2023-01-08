#include <cstdio>

#define MAX_LEN 100
#define MAX_N 26

int main() {
    // 변수의 개수
    int N;
    // 스택의 길이
    int len = 0;
    // 각 변수명에 대응되는 값
    int num[MAX_N] = { 0, };
    // 값을 저장할 스택
    double stack[MAX_N] = { 0, };
    // 후위 표기식을 저장할 공간
    char str[MAX_LEN + 1] = { 0, };

    scanf("%d\n%s", &N, str);
    for (int i = 0; i < N; i++) scanf("%d", num + i);

    // 후위 표기식을 계산
    for (int i = 0; str[i] != 0; i++) {
        switch(str[i]) {
            case '+': 
                stack[len - 2] += stack[len - 1];
                len -= 1;
                break;
            case '-': 
                stack[len - 2] -= stack[len - 1];
                len -= 1;
                break;
            case '*': 
                stack[len - 2] *= stack[len - 1];
                len -= 1;
                break;
            case '/': 
                stack[len - 2] /= stack[len - 1];
                len -= 1;
                break;
            default: stack[len++] = num[str[i] - 'A'];
        }
    }

    printf("%.2lf\n", stack[len - 1]);

    return 0;
}
