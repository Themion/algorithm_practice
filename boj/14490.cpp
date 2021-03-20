#include <cstdio>

//a와 b의 최대공약수를 반환한다
int gcc(int a, int b)
{
    if(b == 0) return a;
    else if(b > a) return gcc(b, a);
    else return gcc(b, a % b);
}

int main()
{
    //a:b의 최대공약수를 div에 저장한다
    int a, b, div;
    scanf("%d:%d", &a, &b);
    
    div = gcc(a, b);

    //a와 b를 최대공약수로 나눈 수를 출력한다
    printf("%d:%d", a / div, b / div);

    return 0;
}