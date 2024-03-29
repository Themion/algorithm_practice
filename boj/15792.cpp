#include <cstdio>

int main() {
    // A, B: 두 수 A와 B를 저장할 공간, i: 소수점 연산에 사용할 변수
    int A, B, i = 0;
    scanf("%d %d", &A, &B);

    // 소수점 앞의 정수 부분을 출력한다
    printf("%d", A / B);
    // A % B가 0이 아니라면, 즉 A / B의 결과가 정수가 아니라면
    if (A % B) {
        // A를 B로 나눈 나머지를 A에 저장한다
        A %= B;
        // 소숫점이 필요하므로 소숫점을 출력한다
        printf(".");
    }
    
    // 나눠야 할 부분이 아직 남아있고
    // 아직 소숫점 아래 1천자리까지 계산하지 않았다면
    while ((A % B) && (i++ < 1000)) {
        // 자릿수를 한 칸 올려주고
        A *= 10;
        // A를 B로 나눈 몪을 출력한 뒤
        printf("%d", A / B);
        // 나머지 계산을 이어가기 위해 A를 B로 나눈 나머지를 A에 저장한다
        if (A >= B) A %= B;
    }

    return 0;
}
