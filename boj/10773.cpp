#include <cstdio>

#define MAX_K 100000

int main() {
    // K: 명령의 수, input: 각 명령
    // arr: 받아 적은 수의 배열, len: arr의 길이, ans: 최종적으로 받아 적은 수의 합
    int K, input, arr[MAX_K] = { 0, }, len = 0, ans = 0;
    
    // 명령의 수를 입력받은 뒤
    scanf("%d", &K);
    // 각 명령에 대해
    for (int i = 0; i < K; i++) {
        // 명령을 입력받은 뒤 명령에 따라 배열에 수를 넣거나 제거한다
        scanf("%d", &input);
        arr[input ? len++ : --len] = input; 
    }
    // 배열 안의 모든 수를 모두 더해 ans에 저장
    for (int i = 0; i < len; i++) ans += arr[i];
    // 받아 적은 수의 합을 출력
    printf("%d\n", ans);

    return 0;
}
