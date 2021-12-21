#include <cstdio>
#include <cmath>

int main() {
    int R;
    scanf("%d", &R);
    // 택시 기하학에서 반지름이 R인 원은 한 변의 길이가 R√2인 정사각형과 같다
    // 유클리드 기하학의 원의 넓이와 택시 기하학에서의 원의 넓이를 출력한다
    printf("%.6f\n%.6f", M_PI * R * R, 2.0 * R * R);

    return 0;
}
