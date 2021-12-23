#include <cstdio>

int main() {
    // 각 대문자를 저장해 출력
    char buf;
    // ans: 다이얼이 이동한 칸의 수
    int ans = 0;

    // 입력받는 각 대문자에 대해
    while (scanf("%c", &buf) && buf != '\n') {
        // 해당 대문자에 해당하는 거리만큼 다이얼을 이동
        if (buf >= 'W') ans++;
        if (buf >= 'T') ans++;
        if (buf >= 'P') ans++;
        if (buf >= 'M') ans++;
        if (buf >= 'J') ans++;
        if (buf >= 'G') ans++;
        if (buf >= 'D') ans++;
        ans += 3;
    }

    // 다이얼이 움직인 총 칸의 수를 출력
    printf("%d\n", ans);

    return 0;
}
