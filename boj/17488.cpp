#include <iostream>

using namespace std;

#define MAX_N 1000
#define MAX_M 1000

// reg[n][m]: 학생 n이 과목 m의 수강신청에 성공했다면 true, 아니라면 false
bool reg[MAX_N][MAX_M + 1];
// N: 학생의 수, M: 과목의 수, len[n]: 학생 n이 수강신청에 성공한 과목 수
int N, M, L[MAX_M + 1], len[MAX_N];

void test_case() {
    // bucket[n][m]: 학생 n이 과목 m을 수강바구니에 넣었다면 true, 아니라면 false
    bool bucket[MAX_N][MAX_M + 1] = {{ 0, }};
    // n, m: 학생과 과목을 가리킬 인덱스
    // cnt[m]: 과목 m이 수강바구니에 남긴 횟수
    int n, m, cnt[MAX_M + 1] = { 0, };

    // 각 학생의 수강바구니를 입력받아 bucket에 저장하고 cnt를 갱신
    for (n = 0; n < N; n++) while (cin >> m && m != -1) {
        bucket[n][m] = true;
        cnt[m] += 1;
    }
    
    // 각 학생의 수강바구니에 과목이 하나 이상 존재할 때
    for (m = 1; m <= M; m++) if (cnt[m]) {
        // 해당 과목이 수강신청에 성공한 과목이라면 각 학생에 대해
        if (cnt[m] <= L[m]) for (n = 0; n < N; n++) if (bucket[n][m]) {
            // 학생 n이 과목 m을 수강신청했음을 표시하고
            reg[n][m] = true;
            // 학생 n이 수강신청에 성공한 과목 수를 1 늘린다
            len[n]++;
        }
        // 수강신청 성공 여부와는 관계없이 수강제한인원을 cnt만큼 줄인다
        L[m] -= cnt[m];
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 문제의 조건을 입력받은 뒤
    cin >> N >> M;
    for (int m = 1; m <= M; m++) cin >> L[m];

    // 수강바구니를 두 번 실행
    for (int T = 0; T < 2; T++) test_case();

    // 각 학생마다
    for (int n = 0; n < N; n++) {
        // 수강신청에 성공한 과목이 없다면 "망했어요"를 출력
        if (!len[n]) cout << "망했어요";
        // 그렇지 않다면 수강신처엥 성공한 과목을 각각 출력
        else for (int m = 1; m <= M; m++) if (reg[n][m]) cout << m << ' ';
        // 개행 문자를 출력해 현재 학생에 대한 출력을 종료
        cout << '\n';
    }

    return 0;
}
