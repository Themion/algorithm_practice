#include <cstdio>

int main() {
    int idx, max = -1, buf;
    for (int i = 1; i <= 9; i++) {
        // 수를 입력받고 최댓값과 그 인덱스를 갱신
        scanf("%d", &buf);
        if (max < buf) { max = buf; idx = i; }
    }

    //최댓값과 그 인덱스를 출력한다
    printf("%d\n%d", max, idx);

    return 0;
}
