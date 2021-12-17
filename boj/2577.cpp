#include <cstdio>

int main() {
    // A, B, C: 입력받을 세 수, mul: 세 수의 곱
    // ans[i] : mul의 각 자리에 i가 등장한 횟수
    int A, B, C, mul, ans[10] = { 0, };
    scanf("%d %d %d", &A, &B, &C);
    mul = A * B * C;

    // mul의 1의 자리 수를 판별하여 해당 수가 나온 횟수를 1 늘린 뒤
    // mul을 10으로 나누어 다시 mul의 1의 자리 수를 판별한다
    while (mul) {
        ans[mul % 10] += 1;
        mul /= 10;
    }

    // A, B, C 세 수의 곱에 0부터 9까지의 숫자가 얼마나 쓰였는지 출력
    for (int i = 0; i < 10; i++) printf("%d\n", ans[i]);

    return 0;
}
