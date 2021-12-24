#include <cstdio>

#define MIN_K 6
#define MAX_K 12

// len: 로또 번호의 개수, arr: 각 로또 번호
// picks: 로또 번호 후보 중 로또로 예측되는 번호
int len, arr[MAX_K], picks[MIN_K];

// 현재 idx개의 번호를 뽑았으며 마지막으로 뽑은 번호는 last번째 번호이다
void pick(int idx, int last) {
    // 번호를 전부 뽑지 않았다면
    // last 이후 가능한 번호들을 전부 뽑은 뒤 다음 번호를 고른다
    if (idx < MIN_K) for (int i = last + 1; i < len; i++) {
        picks[idx] = arr[i];
        pick(idx + 1, i);
    }
    // 6개의 번호를 모두 뽑았다면 각 번호를 순서대로 출력한뒤 행을 바꾼다
    else for (int i = 0; i < MIN_K; i++) 
        printf("%d%c", picks[i], (i == MIN_K - 1 ? '\n' : ' '));
}

void test_case() {
    // 각 로또 번호를 입력받은 뒤
    for (int i = 0; i < len; i++) scanf("%d", arr + i);
    // 가능한 경우를 모두 출력한 뒤 줄바꿈을 출력해 테스트 케이스의 출력을 종료
    pick(0, -1);
    printf("\n");
}

int main() {
    // 길이가 0이 아닌 모든 테스트 케이스에 대해 가능한 경우를 출력
    while (scanf("%d", &len) && len) test_case();
    return 0;
}
