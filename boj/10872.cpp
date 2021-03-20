#include <cstdio>

int main()
{
    //팩토리얼을 구할 수
    int n;
    //팩토리얼을 저장할 수
    long long fact = 1;

    //n을 입력받은 뒤
    scanf("%d", &n);
    //n이 0이 될 때까지 fact에 n을 곱한 뒤 n에 1을 빼 준다
    while (n > 0) fact *= n--;
    //fact를 출력한다
    printf("%lld\n", fact);

    return 0;
}