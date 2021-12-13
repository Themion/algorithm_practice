#include <cstdio>

#define MAX_N 100000

// score[i - 1]: 서류심사 순위가 i인 지원자의 면접심사 순위
int score[MAX_N];

int test_case() {
    // N: 각 테스트 케이스에서 지원자의 수
    // idx: score에 면접심사 순위를 저장할 때 사용할 인덱스
    // val: 면접심사 순위를 저장할 공간, ans: 채용할 사람의 수
    int N, idx, val, ans = 1;

    // 지원자의 수를 입력받고
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        // 각 지원자의 서류 / 면접심사 순위를 입력받아 score에 저장
        scanf("%d %d", &idx, &val);
        score[idx - 1] = val;
    }

    // 서류심사 1위인 지원자는 반드시 합격한다
    val = score[0];

    // 서류심사 2위부터 모든 지원자에 대해 서류심사 순서대로
    // 서류심사 순위는 직전 채용자보다 낮지만 면접심사 순위는 높을 때
    for (int i = 1; i < N; i++) if (val > score[i]) {
        // 채용한 사람의 수를 1 늘린 뒤
        ans++;
        // 현재 지원자를 채용하여 면접점수 결과를 저장
        val = score[i];
    }

    // 채용한 직원 수를 반환
    return ans;
}

int main() {
    int T;

    scanf("%d", &T);
    while (T--) printf("%d\n", test_case());

    return 0;
}
