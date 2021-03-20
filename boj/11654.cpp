#include <cstdio>

int main()
{
	//입력받을 문자 하나
	char input;
	//출력할 수
	int ret;

	//문자를 입력받아 int로 형변환한 뒤 출력한다
	scanf("%c", &input);
	ret = (int)input;
	printf("%d\n", ret);

    return 0;
}