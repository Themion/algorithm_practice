#include <cstdio>

int main() {
	//a, b를 저장할 공간
	int a, b;
	//a와 b를 입력받는다
	scanf("%d %d", &a, &b);
	//둘을 나눈 결과를 저장하지 않고 바로 출력
	printf("%.9f\n", (double)a / (double)b);

    return 0;
}