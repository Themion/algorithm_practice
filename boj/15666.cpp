#include <cstdio>

#define MAX_N 8
#define MAX_NUM 10000

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
    // visit[i]: i가 입력된 횟수
    bool visit[MAX_NUM + 1] = { 0, };
    // buf: 입력을 visit로 바꾸기 위한 버퍼, n: 입력되는 수의 개수
    int buf, n;

    // n개의 수를 입력받아 각 수가 나왔는지 여부를 visit에 저장
    for (scanf("%d %d", &n, &M); n--; ) {
        scanf("%d", &buf);
        visit[buf] = true;
    }
    // 나온 적이 있는 수와 그 횟수를 item에 저장
    for (int i = 0; i <= MAX_NUM; i++) if (visit[i]) item[N++] = i;

    // 조건을 만족하는 수열을 모두 만들어 출력
    backtrack(0, 0);

    return 0;
}
