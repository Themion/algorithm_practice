#include <cstdio>

#define FOR(a, b) for (int i = a; i < b; i++)

// 구간 [1, num]에서 등장하는 digit의 개수를 계산
void search(int num, int arr[]) {
    // log: 수 num의 각 자리 digit을 뽑아내기 위한 10^n승 변수
    // left, right: k번째 digit의 왼쪽/오른쪽에 있는 수
    // mid: k번째 digit
    int log = 1, left, right, mid;
    
    // 배열 초기화
    FOR(0, 10) arr[i] = 0;
    
    // num의 각 자리에 대해
    while (num >= log) {
        // left, right, mid 초기화
        left = num / (log * 10);
        right = num % log;
        mid = (num / log) % 10;

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
}

int main() {
    int A, B, a[10], b[10];
    // 주어진 경우에 대해
    scanf("%d %d", &A, &B);
    while (A && B) {
        // 1부터 A까지 각 수가 나오는 횟수와
        search(A - 1, a);
        // 1부터 B까지 각 수가 나오는 횟수를 계산한 뒤
        search(B, b);
        // 둘의 차를 출력한다
        FOR(0, 10) printf("%d%c", b[i] - a[i], i == 9 ? '\n' : ' ');
        
        scanf("%d %d", &A, &B);
    }

    return 0;
}