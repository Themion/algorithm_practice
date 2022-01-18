#include <cstdio>

using namespace std;

#define MAX_ALP 26
#define y_(i) (crd[idx[i + 1]].y - crd[idx[i]].y)
#define x_(i) (crd[idx[i + 1]].x - crd[idx[i]].x)

// siz: crd의 길이, idx: 트리플렛 여부를 검토할 세 좌표의 crd 인덱스
int siz, idx[3];
// 칠판에서 각 알파벳의 좌표를 정렬된 순서로 저장
struct coord{ char y = 0, x = 0; } crd[MAX_ALP];

// len개의 알파벳을 골랐고 마지막으로 고른 알파벳이 last번째 알파벳일 때
int brute_force(int len, int last) {
    // 주어진 경우에서 트리플렛의 개수
    int ret = 0;
    
    // 만일 세 알파벳을 모두 골랐다면 세 알파벳이 일직선상에 있는지 여부를 계산
    // y_(0) : y_(1) == x_(0) : x_(1)이라면 세 알파벳의 좌표의 변위가 같으므로
    // 세 알파벳은 일직선상에 있고
    // 식을 변형하면 y_(0) * x_(1) == y_(1) * x_(0)이다
    if (len == 3) ret = y_(0) * x_(1) == y_(1) * x_(0);
    // 그렇지 않다면 남은 3 - len개의 알파벳을 골랐을 때 트리플렛의 개수를 계산
    else for (int i = last; i <= siz - (3 - len); i++) {
        // 트리플렛의 len번째 알파벳을 i번째 알파벳으로 고른 뒤
        idx[len] = i;
        // 이 경우에 트리플렛의 개수를 전부 더해 ret에 저장
        ret += brute_force(len + 1, i + 1);
    }

    // 현재 경우에서 트리플렛의 수를 반환
    return ret;
} 

int main() {
    // 그리드의 크기
    int N;
    // 그리드의 각 좌표의 상태를 입력받아 알파벳이 놓인 그리드의 좌표를 crd에 저장
    scanf("%d", &N);
    for (char y = 0; y < N; y++) {
        getchar();
        for (char x = 0; x < N; x++) if (getchar() != '.') crd[siz++] = { y, x };
    }

    // 트리플렛인 모든 경우를 계산해 경우의 수를 출력
    printf("%d\n", brute_force(0, 0));

    return 0;
}
