#include <cstdio>
#include <map>

using namespace std;

// m[a][b]: 각 a / b 지점에 있는 좌석을 사용했다면 true
bool m[2001][2001];

// a와 b의 최소공배수 출력
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// num번쨰 원에서 사용 가능한 좌석 수 계산
int calc(int num)
{
    int ret = 0;
    // 각 0에 있는 좌석은 사용할 수 없다고 가정
    // 각 0의 좌석과 무대를 잇는 직선의 왼쪽에 있는 좌석 수만 계산
    for (int i = 1; i < (num - 1) / 2; i++)
    {
        // 각 좌석은 구좌표계에서 (num, num / i)에 위치해있다
        // 좌석의 각이 num / i인 좌석이 이미 나왔는지 확인하기 위해
        // 각 num / i를 기약분수 up / down으로 만들어 저장한다
        int div = gcd(num, i), up = num / div, down = i / div;

        // 각 up / down에 사용한 좌석이 없다면 현재 좌석을 사용
        ret += m[up][down] == false;
        // 이제 각 up / down에 있는 좌석은 사용 불가능
        m[up][down] = true;
    }

    // num번째 원에서 사용한 좌석의 수를 반환
    return ret;
}

int main()
{
    int d1, d2, ans = 0;
    scanf("%d %d", &d1, &d2);
    // d1과 d2가 다르거나 유일한 원의 반지름이 짝수라면
    // 무대에서 수직 아래에 있는 좌석을 사용한다
    bool down = d2 > d1 || d2 % 2 == 0;

    // 무대의 한쪽 옆에 있는 좌석 중 사용 가능한 좌석의 수를 계산
    for (int i = d1; i <= d2; i++) ans += calc(i);

    // 구한 좌석의 수는 무대의 한쪽 옆에 있는 좌석뿐
    // 좌석의 배치는 선대칭이므로 구한 좌석의 수에 2를 곱한 뒤
    // 반드시 사용되는 수직 위 좌석, 경우에 따라 사용되는 수직 아래 좌석의
    // 사용 여부를 더한 값을 출력한다
    printf("%d\n", 2 * ans + down + 1);

    return 0;
}