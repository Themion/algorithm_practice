#include <cstdio>

#define MAX_LEN 1000

int min(int a, int b) { return a < b ? a : b; }

int main() {
    // A, B: 입력받을 두 문자열
    char A[MAX_LEN + 1] = "", B[MAX_LEN + 1] = "";
    // a, b: a와 B의 길이
    int a = 0, b = 0;
    // mde[i % 2][j]: A[0:i]와 B[0:j]의 편집 거리
    short mde[2][MAX_LEN + 1] = {{ 0, }};

    // A와 B를 입력받은 뒤
    scanf("%s\n%s", A, B);

    // 두 문자열의 길이를 계산한 뒤
    for (; A[a]; a++);
    for (; B[b]; b++);
 
    // 공백 문자열을 B로 바꿀 때의 편집 거리를 계산한다
	for (int i = 1; i <= b; i++) mde[0][i] = i;

    // 동적 계획법으로 편집 거리를 계산한다
    for (int i = 1; i <= a; i++) {
        // 공백 문자열을 A[0:i]로 바꿀 때의 편집 거리를 계산한 뒤
        mde[i % 2][0] = i;
            for (int j = 1; j <= b; j++) {
            // mde[!(i % 2)][j - 1]까지 계산했을 때
            // mde[i % 2][j]는 mde[!(i % 2)][j - 1]거나 그보다 1 크다
            // 우선 mde[!(i % 2)][j - 1]에서 A[i] != B[j]를 더해
            // 한 글자 변경할 때의 최소 편집 거리를 계산하고
            mde[i % 2][j] = mde[!(i % 2)][j - 1] + (A[i - 1] != B[j - 1]);
            // A와 B중 어느 하나를 한 글자 덜 계산한 값에 추가 연산을 실행해
            // 한 글자 추가할 때의 최소 편집 거리를 계산한다
            mde[i % 2][j] = min(mde[i % 2][j], 
                                min(mde[!(i % 2)][j], mde[i % 2][j - 1]) + 1);
        }
    }

    // 최단 거리를 출력한다
    printf("%d\n", mde[a % 2][b]);

    return 0;
}
