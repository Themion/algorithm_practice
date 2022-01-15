#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX_D 9

int main() {
    // N: 각 수가 한번씩 나오는 d진법을 찾을 수, d: 수를 변환할 진법
    // arr: permutation을 이용해 d진법 수를 계산
    // n: d진법 수 arr을 10진법으로 바꿔 저장할 공간
    int N, d, arr[MAX_D + 1] = { 1, 0, }, n = 0;

    // 문제의 조건을 입력받은 뒤
    scanf("%d %d", &N, &d);

    // arr을 진법에 맞춰 완성시킨 뒤
    for (int i = 2; i < d; i++) arr[i] = i;
    do {
        // n을 초기화한 뒤 arr을 10진법 수로 변환
        n = 0;
        for (int i = 0; i < d; i++) n = (n * d) + arr[i];
        // n이 N보다 크다면 break
        if (n > N) break;
        // permutation을 이용회 순회하며 가능한 n을 모두 탐색
    } while (next_permutation(arr, arr + d));

    // n이 N보다 크다면 n을, 아니라면 -1을 출력
    printf("%d\n", n > N ? n : -1);

    return 0;
}
