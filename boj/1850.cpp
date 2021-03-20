#include <cstdio>

//a와 b의 최대공약수를 반환한다
long long gcc(long long a, long long b)
{
    if(b == 0) return a;
    else if(b > a) return gcc(b, a);
    else return gcc(b, a % b);
}

int main()
{
    //a:b의 최대공약수를 div에 저장한다
    long long a, b, div;
    scanf("%lld %lld", &a, &b);
    
    div = gcc(a, b);

    //예) 1111 = 11 * 101, 111111 = 11 * 10101
    //    4와 6의 최대공약수는 2이다
    while(div--) printf("1");
    printf("\n");

    return 0;
}