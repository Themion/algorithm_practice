#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 50

int main() {
    // N: 배열의 길이, A, B: 입력받은 배열, S: 배열곱의 결과
    int N, A[MAX_N], B[MAX_N], S = 0;
    // 배열을 입력받은 뒤
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A + i);
    for (int i = 0; i < N; i++) scanf("%d", B + i);
    // 두 배열을 모두 정렬한 다음
    sort(A, A + N);
    sort(B, B + N);
    // A를 뒤집어서 B와 곱해 S에 저장한다
    for (int i = 0; i < N; i++) S += A[N - 1 - i] * B[i];
    // 배열곱을 최소화한 값을 출력
    printf("%d\n", S);

    return 0;
}
