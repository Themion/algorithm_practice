#include <cstdio>

#define FOR(a, b) for (int i = a; i < b; i++)

int main() {
    // arr[digit]: [1, N] 안의 각 수에서 각 digit이 나오는 횟수
    // log: 수 N의 각 자리 digit을 뽑아내기 위한 10^n승 변수
    // left, right: k번째 digit의 왼쪽/오른쪽에 있는 수
    // mid: k번째 digit
    int N, arr[10] = { 0, }, log = 1, left, right, mid;
    // 주어진 경우에 대해
    scanf("%d", &N);
    
    // N 각 자리에 대해
    while (N >= log) {
        // left, right, mid 초기화
        left = N / (log * 10);
        right = N % log;
        mid = (N / log) % 10;

        /*
        [1, num]사이의 모든 수에서 k번째 자리에 i가 나오는 횟수는 다음과 같다
        i <  mid => (left + 1 - (mid == 0)) * log
        i == mid => (left + 1 - (mid == 0)) * log + (right + 1)
        i >  mid => (left     - (mid == 0)) * log 
        
        left의 범위는 [0, left]이고 right의 최대 범위는 [0, log]임이 자명하다.
        이 때 left의 범위가 [0, left - 1)일 때 right의 범위는 반드시 [0, log]이고
        left가 최대일 때 right의 범위는 [0, right]이다.
        단 i가 0일 때 left의 범위는 예외적으로 (0, left)이므로
        k번째 자리에 i가 나오는 경우의 수는 (left - (mid == 0)) * right을 넘는다.

        i가 mid보다 작다면 right의 경우의 수는 log이고,
        i가 mid라면 가능한 right의 범위는 [0, right]이므로 경우의 수는 right + 1이며,
        i가 mid보다 크다면 valid하지 않으므로 가능하지 않다.
        따라서 i와 mid의 대소에 따라 k번째 자리에 i가 나오는 경우의 수는
        i <  mid => (left + 1 - (  i == 0)) * log
        i == mid => (left + 1 - (mid == 0)) * log + (right + 1)
        i >  mid => (left     - (  i == 0)) * log 
        와 같다
        */
        FOR(0, mid) arr[i] += (left + 1 - (i == 0)) * log;
        arr[mid] += (left - (mid == 0)) * log + (right + 1);
        FOR(mid + 1, 10) arr[i] += left * log;

        // k번째 자리일 때의 계산이 끝났으므로 k + 1번째 자리에 대해 계산
        log *= 10;
    }

    FOR(0, 10) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
