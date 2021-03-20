#include <cstdio>

bool is_prime;

int main()
{
    //m, n: 소수를 찾을 범위
    //min: 범위 내의 가장 작은 소수, sum: 범위 내의 소수의 합
    int m, n, min = 10001, sum = 0;
    scanf("%d %d", &m, &n);

    //0과 1은 소수가 아니므로 범위 내에 0과 1이 들어가지 않게 조정
    if (m < 2) m = 2;

    //범위 내의 모든 수에 대해
    for (int i = m; i <= n; i++)
    {
        //우선 해당 수가 소수라고 가정한 뒤
        is_prime = true;

        //1과 자기 자신을 제외한 수 중 약수가 발견된다면
        for (int j = 2; j <= i / 2; j++) if (i % j == 0)
        {
            //소수가 아님을 표시한 뒤 벗어난다
            is_prime = false;
            break;
        }

        //만일 i가 정말로 소수였다면
        if (is_prime)
        {
            //해당 값이 범위 내 가장 작은 소수인지 확인한 뒤
            min = i < min ? i : min;
            //소수의 합에 해당 수를 더한다
            sum += i;
        }
    }

    //sum이 0이라는 건 범위 내에 소수가 없었다는 뜻이므로 -1을 출력
    if (sum == 0) printf("-1\n");
    //그렇지 않다면 범위 내에 소수가 하나라도 있었으므로
    //소수의 합과 가장 작은 소수를 출력
    else printf("%d\n%d\n", sum, min);

    return 0;
}