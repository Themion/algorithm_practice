#include <cstdio>

#define MAX_N 1000

int main() {
    // arr[i + MAX_N]: 입력으로 i가 주어졌다면 true, 아니라면 false
    bool arr[2 * MAX_N + 1] = { 0 };
    // N: 배열의 크기, buf: 각 수를 입력받을 공강
    int N, buf;

    // 배열의 크기를 입력받은 뒤
    scanf("%d", &N);
    while (N--) {
        // 각 수를 입력받아 인덱스로 바꾼 뒤 arr에 저장
        scanf("%d", &buf);
        arr[buf + MAX_N] = true;
    }

    // 배열을 정렬한 뒤 오름차순으로 출력
    for (int i = 0; i <= 2 * MAX_N; i++) if (arr[i])
        printf("%d\n", i - MAX_N);

    return 0;
}
