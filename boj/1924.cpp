#include <cstdio>

int main() {
    // day[i]: x월 y일을 1월 i일로 치환했을 때 i % 7일의 요일
    char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    // x, y: x월 y일
    int x, y, ans = 0, month[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &x, &y);
    // x월 이전까지의 모든 날을 더한다
    for (int i = 1; i < x; i++) ans += month[i];
    // 1일부터 y일까지의 일 수를 더한다
    ans += y - 1;

    // ans를 7로 나눈 나머지를 이용해 요일을 출력한다
    printf("%s\n", day[ans % 7]);

    return 0;
}
