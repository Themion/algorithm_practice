#include <cstdio>

int main()
{
	//점수를 입력받는다
	int grade;
	scanf("%d", &grade);

	//점수에 따라 그 점수에 해당하는 학점을 출력
	if      (grade >= 90) printf("A\n");
	else if (grade >= 80) printf("B\n");
	else if (grade >= 70) printf("C\n");
	else if (grade >= 60) printf("D\n");
	else                  printf("F\n");

    return 0;
}