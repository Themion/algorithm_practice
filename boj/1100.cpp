#include <cstdio>

int main() {
    // buf: 체스판의 각 칸의 정보를 입력받을 버퍼
    // ans: 말이 있는 흰 칸의 수
    char buf, ans = 0;

    // 체스판의 각 칸에 대해
    for (int i = 0; i < 8; i++)  {
        for (int j = 0; j < 8; j++) {
            // 칸 상태는 항상 입력받는다
            scanf("%c", &buf);
            // 현재 칸이 말이 있는 흰색 칸인지 여부를 ans에 더한다
            ans += (buf == 'F') * !((i + j) % 2);
        }

        // 개행 문자 패싱
        scanf("%*c");
    }

    // 흰 칸 위의 말의 수를 출력한다
    printf("%d\n", ans);

    return 0;
}