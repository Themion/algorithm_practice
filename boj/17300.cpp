#include <cstdio>

#define MAX_L 9

int abs(int n) { return n < 0 ? -n : n; }
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    // visit[i]: 점 i를 방문했다면 true, 아니라면 false
    bool visit[MAX_L + 1] = { 1, };
    // mid[a][b]: 두 점 a, b 사이에 낀 점
    char mid[MAX_L + 1][MAX_L + 1] = {{ 0, }};
    // L: 패턴에서 남은 점의 개수, A: 현재 점, a: 이전 점
    int L, A, a = 0;

    // 애드혹 방식으로 mid를 초기화
    mid[1][3] = mid[3][1] = 2;
    mid[1][7] = mid[7][1] = 4;
    mid[4][6] = mid[6][4] = mid[2][8] = mid[8][2] = 
        mid[1][9] = mid[9][1] = mid[3][7] = mid[7][3] = 5;
    mid[3][9] = mid[9][3] = 6;
    mid[7][9] = mid[9][7] = 8;

    // 점의 개수를 입력받은 뒤 각 점에 대해
    for (scanf("%d", &L); L; L--) {
        // 현재 점을 입력받고
        scanf("%d", &A);
        // 현재 점이 이미 방문한 점이거나
        // 현재 점과 이전 점 사이에 방문하지 않은 점이 있다면 break
        if (visit[A] || !visit[mid[A][a]]) break;
        // 이전 점에 현재 점을 저장하고 현재 점을 방문했음을 표시
        visit[a = A] = true;
    }

    // L이 0이 아니라면 패턴이 중간에 멈춘 것이므로 NO를
    // 그렇지 않다면    패턴을 완성시킨 것이므로 YES를 출력
    printf("%s\n", L ? "NO" : "YES");

    return 0;
}
