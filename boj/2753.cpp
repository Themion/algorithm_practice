#include <cstdio>

int main()
{
    //연도를 입력받은 뒤
    int year;
    scanf("%d", &year);
    //해당 연도가 윤년인지, 즉
    //4의 배수이면서, 100의 배수가 아니거나 또는 400의 배수인지를 판단하여
    //이를 출력한다
    printf("%d\n", (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
    return 0;
}