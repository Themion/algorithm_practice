#include <algorithm>
#include <cstdio>

using namespace std;

#define SUM_LEN 500500

int A[SUM_LEN], B[SUM_LEN];

// 배열을 입력받아 모든 부분합을 v에 저장
void make_array(int a[SUM_LEN], int &len) {
    // arr: 배열의 각 성분, size: 배열의 길이
    int arr[1000] = { 0, }, size;

    // 배열을 입력받은 뒤
    scanf("%d", &size);
    for (int i = 0; i < size; i++) scanf("%d", arr + i);

    // 배열의 각 성분에서 시작하는 연속합을 a에 차례로 저장
    for (int i = 0; i < size; i++) {
        a[len++] = arr[i];
        for (int j = i + 1; j < size; j++) a[len++] = a[len - 1] + arr[j];
    }

    // 부분합을 정렬해 이분 탐색을 사용 가능하게 만든다
    sort(a, a + len);
}

int main() {
    int T, t, a_size = 0, b_size = 0;
    long long ans = 0;

    scanf("%d", &T);

    // A와 B를 각각 입력받아 부분합을 모두 저장
    make_array(A, a_size);
    make_array(B, b_size);

    // A의 각 부분합 a에 대해
    for (int i = 0; i < a_size; i++) {
        t = T - A[i];
        // 각 A[i]마다 B의 부분합 중 T - A[i]의 개수를 ans에 더함
        ans += upper_bound(B, B + b_size, t) - lower_bound(B, B + b_size, t);
    }
    
    // ans 출력
    printf("%lld\n", ans);

    return 0;
}
