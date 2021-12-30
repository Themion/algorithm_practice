#include <cstdio>

void swap(int &a, int &b) { int temp = a; a = b; b = temp; }

int main() {
    // 입력받을 세 수
    int input[3];
    scanf("%d %d %d", &input[0], &input[1], &input[2]);

    // 세 수 중 가장 큰 수를 input[2]에 저장
    for (int i = 0; i < 2; i++) if (input[i] > input[i + 1]) 
        swap(input[i], input[i + 1]);
    // input[0]과 input[1]을 비교해 더 큰 수를 출력
    printf("%d", input[0] > input[1] ? input[0] : input[1]);

    return 0;
}
