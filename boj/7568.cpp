#include <cstdio>

#define MAX_N 50

// 사람의 키와 몸무게를 저장할 클래스
class person {
public:
    short w = 0, h = 0;
    // 몸무게와 키 둘 다 p보다 작을 경우 p보다 덩치가 작다
    bool operator<(person p) { return this->w < p.w && this->h < p.h; }
};

int main() {
    // N: 사람의 수, rank: 각 사람의 순위를 임시로 저장할 공간
    int N, rank;
    // p[i]: i번째 사람의 키와 몸무게
    person p[MAX_N];

    // 문제의 조건을 입력받은 뒤
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%hd %hd", &p[i].w, &p[i].h);

    // 입력받은 모든 사람에 대해
    for (int i = 0; i < N; i++) {
        // 순위가 1등이라고 가정한 뒤
        rank = 1;

        // 자신을 제외한 다른 사람들이 자신보다 덩치가 크다면 순위를 1 내림
        for (int j = 0; j < N; j++) rank += p[i] < p[j];

        // 계산한 등수를 출력
        printf("%d ", rank);
    }

    // 출력을 마치기 위해 개행문자를 출력
    printf("\n");

    return 0;
}
