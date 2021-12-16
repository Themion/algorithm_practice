#include <cstdio>

int main() {
    // input: 이동할 방의 번호, ans: 반지름을 통해 구할 정답
    int input, ans = 1;
    scanf("%d", &input);

    // 해당 벌집의 방을 묶어서 원의 집합으로 보자.
    // 방 1은 반지름이 0인 원, 방 2부터 방 7까지는 반지름이 1인 원, ...
    // 모든 방을 이렇게 생각하면 반지름이 같은 방은 같은 거리만큼 움직여 도달할 수 있다.
    // n > 0일 때 반지름이 n인 방의 개수는 6n이므로
    // n을 계속 증가시키며 (input - 1)에서 6n씩 뺄 때
    // input이 처음으로 음수가 될 때의 n이 방 input의 반지름이다.
    //  맨 처음 방의 숫자가 1이므로 input이 1보다 클 때동안 반지름을 1씩 늘린다
    while (input > 1) input -= 6 * ans++;
    printf("%d\n", ans);

    return 0;
}
