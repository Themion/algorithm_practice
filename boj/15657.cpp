#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_N 8

// N: 사용할 자연수의 종류, M: 수열의 길이, item: 수열에 쓰일 각 수, arr: 만든 수열
int N, M, item[MAX_N], arr[MAX_N];

void backtrack(int len, int idx) {
    // len이 M라면 수열을 모두 채운 것이므로 수열을 출력한 뒤 종료
    if (len == M) {
        for (int i = 0; i < M; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    // idx부터 N까지 중 사용 가능한 수가 있다면
    for (int i = idx; i < N; i++) {
        // 수열에 추가한 뒤 수열의 다음 수를 채운다
        arr[len] = item[i];
        backtrack(len + 1, i);
    }
}

int main() {
    // N과 M을, 수열을 만들 수를 입력받은 뒤 정렬하고
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &item[i]);
    sort(item, item + N);
    // 조건을 만족하는 수열을 모두 출력
    backtrack(0, 0);

    return 0;
}
