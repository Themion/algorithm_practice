#include <cstdio>

#define MAX_N 10000

int main() {
    // N: 찾을 종말의 숫자의 순서
    // i, temp: i가 종말의 숫자인지 temp에 저장한뒤 10씩 나눠가며 계산
    // num: i가 종말의 숫자라면 num에 저장
    int N, i = 1, test, num;
    
    scanf("%d", &N);

    while (N) {
        test = i;
        // i의 각 자리에 대해
        while (test) {
            // i의 특정 부분에서 666을 발견했다면
            if (test % 1000 == 666) {
                // i는 종말의 숫자이므로 num에 i를 저장하고 N을 1 줄인다
                num = i;
                N--;
                break;
            }
            // i의 모든 자리에서 탐색하기 위해 temp를 10으로 나눈다
            test /= 10;
        }
        // 가능한 모든 숫자에 대해 탐색
        i++;
    }

    // N번째 종말의 숫자를 출력
    printf("%d\n", num);

    return 0;
}
