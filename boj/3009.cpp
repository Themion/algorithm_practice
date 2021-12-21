#include <cstdio>

#define MAX 1000

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    // small, max, sum: 좌표의 최솟값/최댓값/합, buf: 각 좌표를 입력받기 위한 버퍼
    int small[2] = { MAX, MAX }, big[2] = { 0, 0 }, sum[2] = { 0, 0 }, buf;

    //세 점을 각각 입력받아 최솟값/최댓값/합을 계산한다
    for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) {
        scanf("%d", &buf);

        small[j] = min(buf, small[j]);
        big[j] = max(buf, big[j]);
        sum[j] += buf;
    }

    // 세 점은 축에 평행한 직사각형의 꼭지점이므로
    // 구하고자 하는 좌표는 (최솟값 + 최댓값) * 2에서 세 점의 합을 빼면 구할 수 있다
    for (int i = 0; i < 2; i++)
        printf("%d%c", 2 * (small[i] + big[i]) - sum[i], (i ? '\n' : ' '));

    return 0;
}
