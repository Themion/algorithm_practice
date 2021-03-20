#define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>

int main()
{
    int r;
    scanf("%d", &r);
    //_USE_MATH_DEFINES를 이용하면 cmath에서 원주율을 사용할 수 있다
    printf("%.6f\n%.6f", M_PI * r * r, 2.0 * r * r);

    return 0;
}