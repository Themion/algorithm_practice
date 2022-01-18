#include <cstdio>

int main() {
    // k: X에서 구할 문자의 순서, N: k번째를 포함하는 가장 작은 X의 길이
    // cnt: k번째 문자가 뒤집힌 횟수
    unsigned long long k, N = 1, cnt = 0;

    // k를 입력받은 뒤
    scanf("%lld", &k);

    // k번째를 포함하는 가장 긴 문자열의 길이를 계산
    while (N < k) N *= 2;
    // 문자열을 반씩 나눠가면서 만일 k가 길이 N짜리 문자열에 속했다면
    while (k > 1) if (k > (N /= 2)) {
        // k번쨰 문자는 (k - (N / 2))번째 문자를 뒤집은 값과 같다
        k -= N;
        // 문자를 뒤집은 횟수를 1 증가
        cnt++;
    }

    // 문자를 짝수번 뒤집었다면 k번째 문자는 0이고
    // 홀수번 뒤집었다면 k번째 문자는 1이다
    printf("%d\n", cnt % 2);

    return 0;
}
