#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 현재 상황이 치트키 없이 가능한 상황이라면 true, 아니라면 false
    bool valid = true;
    // N: 건물 종류의 개수, M: 건설 조건의 개수, K: 건물 건설/파괴 정보 개수
    // X, Y: 입력 버퍼
    int N, M, K, X, Y;
    // cnt[i]: 건물 i의 현재 개수
    // chk[i]: 건물 i를 짓기 위해 추가로 필요한 건물 종류의 수
    short cnt[MAX_N + 1] = { 0, }, chk[MAX_N + 1] = { 0, };
    // info[i]: 건물 i가 필수 조건인 건물의 집합
    vector<int> info[MAX_N + 1];

    // 건물 종류와 건설 조건, 건물 건설/파괴 정보 개수를 각각 입력받은 뒤
    cin >> N >> M >> K;

    // 건설 조건을 입력받아 저장
    while (M--) {
        // 각 건설 조건을 입력받은 뒤
        cin >> X >> Y;
        // info에 해당 조건 X -> Y를 저장한 뒤
        info[X].push_back(Y);
        // Y를 짓기 위해 필요한 건물 종류의 수를 1 늘린다
        chk[Y]++;
    }
    
    // 각 건물 건설/파괴 정보에 대해
    for (int i = 0; valid && (i < K); i++) {
        // 정보를 입력받은 뒤
        cin >> X >> Y;
        
        // 현재 정보가 건설 정보라면
        if (X == 1) {
            // 건물 Y를 짓기 위해 추가로 필요한 건물이 있다면 치트키를 사용한 것
            if (chk[Y] > 0) valid = false;
            // 그렇지 않다면
            else {
                // 건물 Y가 존재하지 않았다면 chk에 건물 Y가 생성되었음을 반영
                if (cnt[Y] == 0) for (auto y : info[Y]) chk[y]--;
                // 건물 Y의 수를 1 늘린다
                cnt[Y]++;
            }
        // 현재 정보가 파괴 정보라면
        } else if (X == 2) {
            // 건물 Y의 개수가 0개 이하라면 치트키를 사용한 것
            if (cnt[Y] <= 0) valid = false;
            // 건물 Y의 수를 1 줄인 뒤
            cnt[Y]--;
            // 건물 Y가 모두 파괴되었다면 chk에 건물 Y가 제거되었음을 반영
            if (cnt[Y] == 0) for (auto y : info[Y]) chk[y]++;
        }
    }

    // 치트키 사용 여부에 따라 문자열을 출력한다
    cout << (valid ? "King-God-Emperor" : "Lier!") << '\n';

    return 0;
}
