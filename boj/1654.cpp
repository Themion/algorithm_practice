#include <cstdio>

typedef unsigned int ui;

#define MAX_K 10000

ui K, N, cable[MAX_K];

// 모든 랜선을 길이 mid로 잘랐을 때 랜선을 N개 이상 얻을 수 있다면 true
bool cable_cut(ui mid) {
    // 모든 랜선을 mid개로 잘라 얻은 개수를 sum에 저장
    ui sum = 0;
    for (int i = 0; i < K; i++) sum += cable[i] / mid;
    // 얻은 랜선 수가 N개 이상인지 여부를 반환
    return sum >= N;
}

int main() {
    // min, max, mid: 이분 탐색에 사용할 랜선을 자를 길이
    ui min = 1, max = __INT_MAX__, mid = (min + max) / 2;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) scanf("%d", cable + i);

    // 자를 랜선 길이에 대해 이분 탐색을 실행해 최적의 길이를 찾는다
    while (min <= max) {
        if (cable_cut(mid)) min = mid + 1;
        else                max = mid - 1;
        mid = (min + max) / 2;
    }

    // 랜선을 잘라 N개 이상 얻을 수 있는 최소의 길이를 출력
    printf("%d\n", mid);

    return 0;
}
