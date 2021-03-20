#include <cstdio>

int main()
{
    // m, seed, X1, X2: 문제에서 제공하는 조건
    int m, seed, X1, X2;
    // a, c: 구할 값,  X1_, X2_: 추정한 a와 c로 계산한 X1, X2
    int a, c, X1_, X2_;
    scanf("%d %d %d %d", &m, &seed, &X1, &X2);

    // 브루트 포스를 이용해 a와 c를 추정한다
    for (int a_ = 0; a_ < m; a_++) for (int c_ = 0; c_ < m; c_++)
    {
        // a_, c_로 X1_, X2_를 계산한 뒤
        X1_ = (a_ * seed + c_) % m;
        X2_ = (a_ * X1_ + c_) % m;

        // 계산한 값이 실제 X1, X2와 같다면 a, c는 a_, c_라 할 수 있다
        if (X1 == X1_ && X2 == X2_) 
        {
            a = a_;
            c = c_;
        }
    }

    printf("%d %d", a, c);

    return 0;
}