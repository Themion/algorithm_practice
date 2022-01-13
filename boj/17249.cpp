#include <cstdio>

int main() {
    // 문자열을 한 글자씩 입력받을 공간
    char c;
    // 각 펀치의 잔상의 수
    int ans = 0;

    // 얼굴을 입력받기 전까지 주먹의 개수를 세어 ans에 저장
    while ((c = getchar()) != '0') ans += (c == '@');
    // ans (= 왼손의 잔상)를 출력한 뒤 0으로 초기화
    ans = printf("%d ", ans) & 0;
    // 문자열이 끝나기 전까지 주먹의 개수를 세어 ans에 저장
    while ((c = getchar()) != '\n') ans += (c == '@');
    // ans(= 오른손의 잔상)를 출력
    printf("%d\n", ans);
    
    return 0;
}
