#include <cstdio>
#include <cmath>

using namespace std;

// 다각형을 이루는 각 점의 좌표
long long N[10001][2];

int main()
{
    // 다각형을 이루는 점의 수
    int size;
    // 다각형의 면적을 저장할 변슈
    long double ans = 0;

    // 다각형의 점의 수와 각 점의 좌표를 입력
    scanf("%d", &size);
    for (int i = 0; i < size; i++) scanf("%lld %lld", &(N[i][0]), &(N[i][1]));
    // 신발끈 공식을 위해 첫번째 좌표를 마지막에 추가
    N[size][0] = N[0][0]; N[size][1] = N[0][1];
    
    // 신발끈 공식을 이용해 면적을 계산
    for (int i = 1; i <= size; i++)
        ans += (N[i - 1][0] * N[i][1]) - (N[i - 1][1] * N[i][0]);
    ans = (ans >= 0 ? ans : -ans) / 2;

    // 면적을 소수점 아래 둘째 자리에서 반올림하여 첫째 자리까지 출력
    printf("%.1Lf\n", round(ans * 10) / 10);

    return 0;
}