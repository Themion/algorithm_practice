#include <cstdio>

int main() {
    // hr: 기상 시간, min: 기상 분
    int hr, min;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &hr, &min);

    // min이 45 미만이라면 hr에 1을 뺀 뒤
    hr -= (min < 45);
    // min에 45를 뺀 뒤, 음수 방지를 위해 60을 더한 뒤 60으로 나눈 나머지를 저장
    min = (min + 60 - 45) % 60;

    // 알람을 설정한 시간과 분을 출력
    printf("%d %d\n", hr, min);

    return 0;
}
