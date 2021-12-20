#include <algorithm>
#include <cstdio>

#define MAX_N 5000
#define INF 0x3f3f

using namespace std;

short min(short a, short b) { return a < b ? a : b; }

int main() {
    // 배달할 설탕의 무게
    int N;
    // val[i]: 설탕의 무게가 i일 때 설탕의 봉지 수
    short val[MAX_N + 1];

    // 배달할 설탕의 무게를 입력받은 뒤
    scanf("%d", &N);
    // 어떤 무게가 배달 가능한 무게인지 알 수 없으므로
    // 모든 값을 INF로 설정한 뒤 봉지의 단위 무게 3과 5의 봉지 수를 1로 설정
    fill_n(val, N + 1, INF);
    val[3] = val[5] = 1;

    // 무게 i에 대해 i - 3, 혹은 i - 5 만큼의 무게를 배달 가능할 때
    // 해당 무게를 배달할 때 봉지의 최솟값에 1을 더한 값으로 설정
    for (int i = 6; i <= N; i++) val[i] = min(val[i - 3], val[i - 5]) + 1;
    // 무게 N을 배달 가능하다면 봉투의 개수를, 배달이 불가능하다면 -1을 반환
    printf("%hd\n", val[N] < INF ? val[N] : -1);

    return 0;
}
