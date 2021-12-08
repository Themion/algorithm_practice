#include <cstdio>

int main() {
    //두 수를 입력받아 두 수의 관계에 해당하는 부등호를 출력한다
    int a, b;
    scanf("%d %d", &a, &b);

    if (a == b) printf("==\n");
    if (a > b) printf(">\n");
    if (a < b) printf("<\n");

    return 0;
}
