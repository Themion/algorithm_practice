#include <cstdio>

#define MAX_N 8
#define MAX_NUM 10000

// N: 사용할 자연수의 종류, M: 수열의 길이, arr: 만든 수열
int N, M, arr[MAX_N];
// item: 수열에 쓰일 각 수와 그 개수
struct pair { int num = 0, cnt = 0; } item[MAX_N];

void backtrack(int len) {
    // len이 M라면 수열을 모두 채운 것이므로 수열을 출력한 뒤 종료
    if (len == M) {
        for (int i = 0; i < M; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    // 사용 가능한 수가 있다면
    for (int i = 0; i < N; i++) if (item[i].cnt) {
        // 수열에 추가한 뒤
        arr[len] = item[i].num;
        item[i].cnt--;
        // 수열의 다음 수를 채우고
        backtrack(len + 1);
        // 수열에서 i를 제거
        item[i].cnt++;
    }
}

int main() {
    // buf: 입력을 cnt로 바꾸기 위한 버퍼
    // n: 입력되는 수의 개수, cnt[i]: i가 입력된 횟수
    int buf, n, cnt[MAX_NUM + 1] = { 0, };

    // n개의 수를 입력받아 각 수가 나온 횟수를 cnt에 저장
    for (scanf("%d %d", &n, &M); n--; ) {
        scanf("%d", &buf);
        cnt[buf]++;
    }
    // 나온 적이 있는 수와 그 횟수를 item에 저장
    for (int i = 0; i <= MAX_NUM; i++) if (cnt[i]) item[N++] = { i, cnt[i] };

    // 조건을 만족하는 수열을 모두 만들어 출력
    backtrack(0);

    return 0;
}
