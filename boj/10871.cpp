#include <cstdio>

int main() {
    // N: 수열의 길이, X: 비교할 수, A: 수열의 각 성분
    int N, X, A;
    
    // N과 X를 입력받은 뒤
    for (scanf("%d %d", &N, &X); N--;) {
        // 입력받은 각 수열의 성분 A가 X보다 작다면 A를 출력
        scanf("%d", &A);
        if (A < X) printf("%d ", A);
    }
    // 개행 문자를 출력해 출력을 종료
    printf("\n");
    
    return 0;
}
