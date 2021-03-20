#include <cstdio>

#define LEN 1000

//a: 주어진 수열
//up[i]: i에서 끝나는 증가 부분수열, down[i]: i에서 끝나는 감소 부분수열
short a[LEN], up[LEN], down[LEN];

void set_max(short &a, short b) { a = a > b ? a : b; }

int main()
{
    //n: 수열의 길이, ans: 출력할 값을 저장할 공간
    short n, ans = 0;

    //수열을 입력받는다
    scanf("%hd", &n);
    for (int i = 0; i < n; i++) scanf("%hd", &a[i]);

    // 증가 부분수열 만들기
    for (int i = 0; i < n; i++)
    {
        // 모든 부분수열의 최소 길이는 1이다
        up[i] = 1;
        // i 이전의 원소만을 이용한 증가 부분수열 중 i를 맨 뒤에 넣을 수 있는
        // 증가 부분수열이 있다면 그 수열 뒤에 i를 넣는다
        for (int j = 0; j < i; j++)
            if (up[i] <= up[j] && a[i] > a[j])
                up[i] = up[j] + 1;
    }
    // 감소 부분수열 만들기
    for (int i = n - 1; i >= 0; i--)
    {
        // 모든 부분수열의 최소 길이는 1이다
        down[i] = 1;
        // i 이후의 원소만을 이용한 감소 부분수열 중 i를 맨 앞에 넣을 수 있는
        // 감소 부분수열이 있다면 그 수열 앞에 i를 넣는다
        for (int j = n - 1; j >= i; j--)
            if (down[i] <= down[j] && a[i] > a[j])
                down[i] = down[j] + 1;
    }

    // i에서 끝나는 두 부분수열의 길이의 합의 최댓값을 구한다
    for (int i = 0; i < n; i++) set_max(ans, up[i] + down[i]);

    // 두 부분수열이 같은 성분에서 끝나므로
    // 실제 바이토닉 수열의 길이는 구한 값 - 1이다
    // 바이토닉 수열의 길이를 출력한다
    printf("%hd\n", ans - 1);

    return 0;
}