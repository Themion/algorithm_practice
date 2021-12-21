#include <cstdio>

int main() {
    // asc: 연주가 ascending이라면 true, 아니라면 false
    // des: 연주가 descending이라면 true, 아니라면 false
    bool asc = true, des = true;
    // 연주한 음 여덟 개를 차례로 받아온다
    int input[8];

    // 문제의 조건을 입력받은 뒤
    for (int i = 0; i < 8; i++) scanf("%d", input + i);

    // 각 음을 이전 음과 비교한다
    // 음이 한번이라도 올라간다면 이 연주는 descending이 아니다
    // 음이 한번이라도 내려간다면 이 연주는 ascending이 아니다
    for (int i = 1; i < 8; i++) {
        if (input[i - 1] > input[i]) asc = false;
        if (input[i - 1] < input[i]) des = false;
    }

    // asc와 des를 이용해 이 연주의 종류를 파악한 뒤 출력한다
    printf("%s\n", (asc ? "ascending" : (des ? "descending" : "mixed")));

    return 0;
}
