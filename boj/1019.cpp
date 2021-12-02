#include <cstdio>

#define FOR(a, b) for (int i = a; i < b; i++)

int main() {
    // arr[digit]: [1, N] 안의 각 수에서 각 digit이 나오는 횟수
    // log: 수 N의 각 자리 digit을 뽑아내기 위한 10^n승 변수
    // left, right: k번째 digit의 왼쪽/오른쪽에 있는 수
    // mid: k번째 digit
    int N, arr[10] = { 0, }, log = 1, left, right, mid;
    // 주어진 경우에 대해
    scanf("%d", &N);
    
    // N 각 자리에 대해
    while (N >= log) {
        // left, right, mid 초기화
        left = N / (log * 10);
        right = N % log;
        mid = (N / log) % 10;

        // 자세한 설명은 5696번을 참조
        FOR(0, mid) arr[i] += (left + 1 - (i == 0)) * log;
        arr[mid] += (left - (mid == 0)) * log + (right + 1);
        FOR(mid + 1, 10) arr[i] += left * log;

        // k번째 자리일 때의 계산이 끝났으므로 k + 1번째 자리에 대해 계산
        log *= 10;
    }

    FOR(0, 10) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}