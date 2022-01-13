#include <cstdio>

#define MAX_N 1000
#define MAX_M 100
#define INF 0x3f3f3f3f
#define curr(i) ord[i][idx[i]]
#define next(i) ord[i][idx[i] + 1]

int max(int a, int b) { return a > b ? a : b; }

int main() {
    // clr: 각 주문의 포장지 색, m: 각 주문의 개수
    char clr, m;
    // N: 주문의 수, t: 각 주문이 들어온 시간
    // ans[i]: { 파란색, 빨간색 }[i] 포장지로 포장된 선물들의 번호
    int N, t, ans[2][MAX_N * MAX_M + 1] = {{ 0, }};
    // time[i]: { 파란색, 빨간색 }[i] 포장지로 포장하는 시간
    // len[i]: { 파란색, 빨간색 }[i] 포장지를 사용한 주문의 수
    // idx[i]: ord[i]에 접근하기 위한 인덱스
    short time[2], len[2] = { 0, }, idx[2] = { 0, };
    // ord[i]: len[i]: { 파란색, 빨간색 }[i] 포장지를 사용한 주문
    struct order { int t = 0; char m = 0; } ord[2][MAX_N];

    // 문제의 조건을 입력받으며 각 주문을 포장지 색으로 분류해 저장
    for (scanf("%hd %hd %d", time, time + 1, &N); N; N--) {
        scanf("%d %c %hhd", &t, &clr, &m);
        ord[clr != 'B'][len[clr != 'B']++] = {t, m};
    }

    // 모든 포장의 순서를 알아낸다
    while (idx[0] < len[0] || idx[1] < len[1]) {
        // 포장할 포장지의 색을 clr에 저장한 뒤
        clr = curr(0).t > curr(1).t;

        // ans에 현재 선물의 포장지 색과 선물 번호를 저장
        ans[clr][++ans[clr][0]] = ++N;
        // time[clr]만큼의 시간을 들여 선물을 포장
        curr(clr).t += time[clr];

        // 현재 주문을 모두 포장했다면
        if (!--curr(clr).m) {
            // 다음 주문의 시작 시간을 주문이 모두 끝났다면 INF
            // 그렇지 않다면 현재 주문의 포장이 끝난 시간과 비교해 더 큰 값으로 설정
            next(clr).t = next(clr).m ? max(curr(clr).t, next(clr).t) : INF;
            // 다음 주문을 가져오기 위해 idx를 1 늘린다
            idx[clr]++;
        }
    }

    // 각 포장의 개수와 해당 포장으로 된 선물 번호를 각각 출력
    for (clr = 0; clr < 2; clr++) {
        printf("%d\n", ans[clr][0]);
        for (int i = 1; i <= ans[clr][0]; i++) printf("%d ", ans[clr][i]);
        printf("\n");
    }

    return 0;
}
