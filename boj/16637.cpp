#include <cstdio>

char method[9];
int len, val[10];

int max(int a, int b) { return a > b ? a : b; }

// a와 b를 method에 맞는 사칙연산으로 계산
int calc(int a, int b, char method) {
    if (method == '+') return a + b;
    else if (method == '-') return a - b;
    return a * b;
}

// i번째 연산 이전의 연산을 모두 마친 뒤(이 때의 결과값을 pre라 가정) 
// 이후 연산을 계산
int brute_force(int i, int pre) {    
    // i가 len / 2라면, 즉 모든 연산을 마쳤다면 pre를 반환
    if (i == len / 2) return pre; 
    // i가 len / 2보다 크다면 에러 처리를 위해 int의 최솟값을 반환
    else if (i > len / 2) return __INT_MAX__ + 1;

    // no_brac: i번째 연산에서 괄호를 사용하지 않을 경우
    // brac:                         사용할 경우
    // 전체 식을 계산하기 전에 각 변수에
    // pre에 i번째 식(혹은 괄호식)을 계산한 값을 저장
    int no_brac = calc(pre, val[i + 1], method[i]),
        brac = calc(pre, calc(val[i + 1], val[i + 2], method[i + 1]), method[i]);

    // i번째 식, 혹은 괄호식까지 계산한 뒤 재귀를 통해 최댓값을 반환
    return max(brute_force(i + 1, no_brac), brute_force(i + 2, brac));
}

int main() {
    // 식을 한 글자씩 입력받아 저장
    char buf;

    // 식의 길이를 입력받은 뒤
    scanf("%d%*c", &len);
    for (int i = 0; i < len; i++) {
        // 식의 각 글자에 대해
        scanf("%c", &buf);
        // 해당 글자가 홀수번째 글자라면 연산자임이 자명함으로
        // method에 해당 연산자를 저장
        if (i % 2) method[i / 2] = buf;
        // 해당 글자가 짝수번째 글자라면 한 글자 숫자임이 자명함으로
        // val에 해당 글자를 저장
        else val[i / 2] = buf - '0';
    }

    // 재귀를 이용해 가능한 모든 경우를 탐색한 뒤 최댓값을 출력
    printf("%d\n", brute_force(0, val[0]));

    return 0;
}