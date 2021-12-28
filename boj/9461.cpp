#include <cstdio>

#define MAX_N 100

int main() {
    // T: 테스트 케이스의 수, N: 테스트 케이스의 입력
    int T, N;
    // 파도반 수열을 저장할 공간
    long long arr[MAX_N] = {1, 1, 1, 2, 2};

    // 범위 내의 파도반 수열을 완성한 뒤
    for (int i = 5; i < MAX_N; i++) arr[i] = arr[i - 1] + arr[i - 5];

    // 테스트 케이스의 수를 입력받고 각 테스트 케이스마다
    for (scanf("%d", &T); T--; ){
        // 순서를 입력받고 해당 순서의 파도반 수열을 출력
        scanf("%d", &N);
        printf("%lld\n", arr[N - 1]);
    }

    return 0;
}
