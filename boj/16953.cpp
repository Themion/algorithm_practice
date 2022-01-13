#include <cstdio>

int main() {
    // A, B: A -> B에 쓰일 두 노드, ans: 최소 연산 횟수
    int A, B, ans = 1;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &A, &B);

    // B를 A로 바꾼다
    while (A < B) {
        // B가 어느 수의 오른쪽에 1을 붙인 값이라면 B를 10으로 나눈다
        if (B % 10 == 1) B /= 10;
        // B가 2의 배수라면 B를 2로 나눈다
        else if (!(B % 2)) B /= 2;
        // 이외의 경우는 정의되지 않았으므로 break
        else break;
        // 연산을 한 횟수를 1 증가
        ans++;
    }

    // A와 B가 같다면 연산을 한 횟수를, 그렇지 않다면 -1을 출력
    printf("%d\n", A == B ? ans : -1);

    return 0;
}
