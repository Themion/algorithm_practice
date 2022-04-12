#include <iostream>

using namespace std;

#define MAX_M 50000

int max(int a, int b) { return a > b ? a : b; }
int relu(int num) { return max(num, 0); }

int main() {
    // M: 덮을 구간의 길이, l, r: 각 선의 좌우 좌표, ans: 최소 선의 개수
    int M, l, r, ans = 0;
    // line[i]: i에서 시작하는 선 중 가장 긴 선의 오른쪽 좌표
    // arr[i]: 구간 [0, M]을 덮는 선분 중 i번째 선분의 오른쪽 좌표
    int line[MAX_M + 1] = { 0, }, arr[MAX_M + 1] = { 0, };

    // 덮을 구간의 길이를 입력받은 뒤
    cin >> M;
    do {
        // 각 선의 좌우 좌표를 입력받고
        cin >> l >> r;
        // 왼쪽 좌표를 기준으로 가장 긴 선의 오른쪽 좌표를 갱신
        line[relu(l)] = max(line[relu(l)], relu(r));
    // 입력이 끝날 때까지, 즉 "0 0"을 입력받을 때까지 반복
    } while (l || r);

    // 0번 좌표를 지나는 선이 존재한다면
    if (line[0])  {
        // 해당 선을 구간을 덮는 첫번째 선으로 지정
        arr[ans++] = line[0];

        // 왼쪽 좌표가 1부터 덮은 구간의 각 좌표에 대해
        for (int i = 1; i <= arr[ans - 1] && arr[ans - 1] < M; i++)
            // 해당 좌표에서 시작하는 선이 덮은 구간을 넘어설 때
            if (line[i] > arr[ans - 1]) {
                // 덮은 구간을 이루는 선 중 현재 선과 겹치는 선이 있다면 제거
                while (ans >= 2 && i <= arr[ans - 2]) ans--;
                // 현재 선을 구간을 덮을 선의 집합에 추가
                arr[ans++] = line[i];
            }
    }

    // 구간을 덮는 선의 집합 중 마지막 선의 오른쪽 좌표가 M 미만이라면 구간을 덮지 못함
    // 따라서 마지막 선이 좌표 M을 포함하는지에 따라 ans 혹은 0울 반환
    cout << ans * (arr[ans - 1] >= M) << '\n';

    return 0;
}
