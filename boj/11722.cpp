#include <algorithm>
#include <cstdio>

#define MAX_N 1000

using namespace std;

int main() {
    // 배열의 길이
    int N;
    // 배열의 각 성분
    int A;
    // 구하고자 하는 수열의 길이
    int ans = 0;
    // 구하고자 하는 수열
    int arr[MAX_N] = { 0, };
    // 이분 탐색으로 구한 값을 삽입할 위치
    int* address;
    
    // 배열의 각 성분에 대해
    for (int i = scanf("%d", &N); i <= N; i++) {
        // 성분값을 입력받은 뒤
        scanf("%d", &A);
        // 이분 탐색으로 성분값보다 작은 값 중 가장 큰 값을 탐색
        address = lower_bound(arr, arr + ans, A, [](int a, int b) { return a > b; });
        // 그러한 값이 없다면 성분값을 구하고자 하는 수열의 맨 뒤에 추가
        if (address - arr == ans) arr[ans++] = A;
        // 그러한 값이 있다면 해당 값을 성분값으로 대체
        else *address = A;
    }

    // 구하고자 하는 수열의 길이를 출력
    printf("%d\n", ans);

    return 0;
}
