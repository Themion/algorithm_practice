#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 8

// N: 사용할 자연수의 종류, M: 수열의 길이, item: 수열에 쓰일 각 수, arr: 만든 수열
int N, M, item[MAX_N], arr[MAX_N];

void backtrack(int len) {
    // len이 M라면 수열을 모두 채운 것이므로 수열을 출력한 뒤 종료
    if (len == M) {
        for (int i = 0; i < M; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    // 사용 가능한 수가 있다면
    for (int i = 0; i < N; i++) {
        // 수열에 추가한 뒤 수열의 다음 수를 채운다
        arr[len] = item[i];
        backtrack(len + 1);
    }
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N과 M을, 수열을 만들 수를 입력받은 뒤 정렬하고
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> item[i];
    sort(item, item + N);
    // 조건을 만족하는 수열을 모두 출력
    backtrack(0);

    return 0;
}
