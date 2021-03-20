#include <cstdio>

//R, M: 해시 함수를 sigma(a, R^i) % M로 정의
const int R = 31;
const int M = 1234567891;

int main()
{
    int n;                      //해시 입력의 길이
    char str[50];               //해시 입력
    unsigned long long ret = 0; //해시 출력

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) scanf("%c", str + i);

    //해시 입력의 뒷자리부터 차례로
    for (int i = n - 1; i >= 0; i--)
    { 
        //지금까지 해싱한 것에 계수를 한 번 곱한 뒤 추가된 문자를 더한다
        ret = ret * R + (str[i] - 'a' + 1);
        //해시 함수이므로 큰 소수 M으로 나눠준다
        ret %= M;
    }

    //해싱한 결과를 출력
    printf("%lld\n", ret);

    return 0;
}