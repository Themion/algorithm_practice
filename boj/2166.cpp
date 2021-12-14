#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define MAX_N 10000

// 다각형을 이루는 각 점의 좌표
int point[MAX_N + 1][2];

int main() {
    // 다각형을 이루는 점의 수
    int N;
    // 다각형의 면적을 저장할 변tn
    long double ans = 0;

    // 다각형의 점의 수와 각 점의 좌표를 입력
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d %d", &(point[i][0]), &(point[i][1]));
    // 신발끈 공식을 위해 첫번째 좌표를 마지막에 추가
    point[N][0] = point[0][0]; point[N][1] = point[0][1];
    
    // 신발끈 공식을 이용해 면적을 계산
    for (int i = 1; i <= N; i++) {
        ans += (ll)point[i - 1][0] * (ll)point[i][1];
        ans -= (ll)point[i - 1][1] * (ll)point[i][0];
    }
    ans = (ans >= 0 ? ans : -ans) / 2;

    // 면적을 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력
    printf("%.1Lf\n", round(ans * 10) / 10);

    return 0;
}
