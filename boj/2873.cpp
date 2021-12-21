#include <iostream>

using namespace std;

#define MAX_R 1000
#define INF 0x3f3f

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 롤러코스터의 행/열이 모두 짝수라면 true, 아니라면 false
    bool is_even;
    // R, C: 롤러코스터의 행/열의 수, val[i][j]: i행 j열의 기쁨 지수
    // p, min: 스킵 가능한 지역의 좌표와 기쁨 지수의 최소치
    short R, C, val[MAX_R][MAX_R], p[2] = {0, 1}n = INF;

    // 롤러코스터의 행/열의 크기를 입력받은 뒤 그 둘이 모두 짝수인지를 저장
    cin >> R >> C;
    is_even = (R % 2 == 0) && (C % 2 == 0);

    // 롤러코스터의 각 지역을 입력받으면서
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        cin >> val[i][j];
        // 해당 지역이 스킵 가능하며 기존 스킵 지역보다 기쁨 지수가 작다면
        if (is_even && (i + j) % 2 && min > val[i][j]) {
            // 스킵할 지역을 현재 지역으로 갱신
            min = val[i][j];
            p[0] = i;
            p[1] = j;
        }
    }

    // 행의 수가 홀수라면 각 을 차례로 탐색하는 것으로 모든 칸을 탐색 가능
    if (R % 2 == 1) {
        for (int i = 0; i < (R / 2); i++) {
            for (int j = 1; j < C; j++) cout << 'R';
            cout << 'D';
            for (int j = 1; j < C; j++) cout << 'L';
            cout << 'D';
        }
        for (int j = 1; j < C; j++) cout << 'R';
    }
    // 열의 수가 홀수라면 각 열을 차례로 탐색하는 것으로 모든 칸을 탐색 가능
    else if (C % 2 == 1) {
        for (int i = 0; i < (C / 2); i++) {
            for (int j = 1; j < R; j++) cout << 'D';
            cout << 'R';
            for (int j = 1; j < R; j++) cout << 'U';
            cout << 'R';
        }
        for (int j = 1; j < R; j++) cout << 'D';
    }

    // 행과 열의 수가 모두 짝수라면 좌표 (i, j)에 대해
    // (i + j)가 홀수인 한 칸을 제외한 모든 칸을 탐색 가능
    else {
        // 행 단위로 탐색하기 위해 두 행을 하나로 묶은 뒤
        // 스킵할 칸 p가 있는 행 쌍에선 특수한 이동 방식을 취하고
        // 나머지 행은 단번에 탐색
        is_even = !(p[0] % 2); p[0] /= 2;

        // p가 있는 행 쌍 이전의 모든 행을 순차적으로 탐색
        for (int i = 0; i < p[0]; i++) {
            for (int j = 1; j < C; j++) cout << 'R';
            cout << 'D';
            for (int j = 1; j < C; j++) cout << 'L';
            cout << 'D';
        }

        // p가 있는 행 쌍을 2 * 2 칸으로 묶은 뒤
        // p가 속하지 않은 2 * 2칸의 모든 칸을 차례로 탐색한 뒤
        for (int i = 0; i < p[1] / 2; i++) cout << "DRUR";
        // p가 속한 2 * 2 칸에서 p 이외의 칸을 탐색한다
        // 이 때 p[0]이 짝수라면 p는 2 * 2의 오른쪽 위, 홀수라면 왼쪽 아래에 있다.
        cout << (is_even ? "DR" : "RD");
        // p가 속하지 않은 2 * 2칸의 모든 칸을 차례로 탐색한다
        for (int i = (p[1] / 2) + 1; i < C / 2; i++) cout << "RURD";

        // p가 있는 행 쌍 이후의 모든 행을 순차적으로 탐색
        for (int i = p[0] + 1; i < R / 2; i++) {
            cout << 'D';
            for (int j = 1; j < C; j++) cout << 'L';
            cout << 'D';
            for (int j = 1; j < C; j++) cout << 'R';
        }
    }

    // 개행 문자를 출력해 출력을 종료한다.
    cout << '\n';

    return 0;
}
