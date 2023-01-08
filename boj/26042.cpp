#include <cstdio>

#define MAX_N 100000

int main() {
    // 배식받을 학생 수
    int n;
    // 학생의 입출력을 나타낼 명령
    int cmd;
    // 각 학생의 번호
    int a[MAX_N] = { 0, };
    // 줄을 선 학생의 맨 앞 인덱스
    int l = 0;
    // 줄을 선 학생의 맨 뒤 인덱스
    int r = 0;
    // 줄의 최장 길이
    int max = 0;
    // 줄이 가장 길 때의 맨 마지막 학생의 번호
    int last = 0;

    // 각 명령에 대해
    for (scanf("%d", &n); n--;) {
        // 명령의 종류를 입력받은 뒤
        scanf("%d", &cmd);
        
        // 명령이 학생 입력 명령이라면
        if (cmd == 1) {
            // 맨 뒤에 학생 번호를 하나 추가
            scanf("%d", a + r++);
        
            // 줄의 최장 길이가 갱신되거나, 혹은 최장 길이가 같으며 마지막 학생 번호가 이전보다 작다면
            // 줄의 최장 길이와 마지막 학생 번호를 갱신
            if ((r - l > max) || (r - l == max && last > a[r - 1])) {
                max = r - l;
                last = a[r - 1];
            }
        }
        
        // 그렇지 않다면 맨 앞 학생을 줄에서 제거
        else l++;
    }

    // 줄의 최장 길이와 이때의 맨 마지막 학생의 번호를 출력
    printf("%d %d\n", max, last);

    return 0;
}
