#include <cstdio>

int main() {
    int grade;

    // 입력받은 점수에 해당하는 학점을 출력
    scanf("%d", &grade);
    if      (grade >= 90) printf("A\n");
    else if (grade >= 80) printf("B\n");
    else if (grade >= 70) printf("C\n");
    else if (grade >= 60) printf("D\n");
    else                  printf("F\n");

    return 0;
}
