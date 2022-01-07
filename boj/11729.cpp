#include <cstdio>

char str[1 << 22];
int i;

// 원판 하나를 기둥 s에서 기둥 e로 이동하는 것을 str에 기록
void add(int s, int e) { 
    // s와 e는 각각 한 자리 수이므로 char 변수 하나를 사용해 저장 가능하다
    str[i++] = s + '0';
    str[i++] = ' ';
    str[i++] = e + '0';
    str[i++] = '\n';
}

// 탑의 c번째 원반과 그 위에 있는 모든 원판을 s에서 e로 이동
void move(int c, int s, int m, int e) {
    // 원판 c 위의 모든 원판을 m으로 옮긴 뒤
    if (c) move(c - 1, s, e, m);
    // 원판 c를 s에서 e로 옮기고
    add(s, e);
    // m으로 옮긴 모든 원판을 다시 e로 옮긴다
    if (c) move(c - 1, m, s, e);
}

int main() {
    // 하노이 탑의 높이
    int N;

    // 하노이 탑의 높이를 입력받고 각 원판을 움직일 순서를 계산한 뒤
    scanf("%d", &N);
    move(N - 1, 1, 2, 3);
    // 원판을 움직일 횟수와 각 순서를 출력
    printf("%d\n%s", (1 << N) - 1, str);

    return 0;
}
