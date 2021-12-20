#include <iostream>

using namespace std;

typedef long long ll;

#define MAX_N 1000000

// N: 나무의 수, M: 원하는 나무토막의 총 길이, wood[i]: 각 나무의 길이
int N, M, wood[MAX_N];

// 나무를 높이 mid만큼 자른 뒤 얻은 나무토막의 총 길이
ll cut_wood(int mid) {
    ll sum = 0;
    for (auto w : wood) sum += (w > mid) ? (w - mid) : 0;
    return sum;
}

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // min, max: 이진 탐색에 필요한 범위
    int min = 0, mid, max = 1;

    // 문제의 조건을 입력받으면서 이분 탐색의 범위를 조정
    cin >> N >> M;
    for (int i = 0; i < N; i++)  {
        cin >> wood[i];
        // 이분 탐색의 최댓값을 나무의 최댓값으로 조정
        max = max > wood[i] ? max : wood[i];
    }
    mid = (min + max) / 2;

    // 최적의 절단기 높이를 이분 탐색을 이용해 찾는다
    while (min <= max) {
        // 각 나무토막을 길이 mid만큼 잘랐을 때
        // 나무토막의 길이가 M 이상이라면 mid보다 큰 값에 대해,
        // 그렇지 않다면 mid보다 작은 값에 대해 탐색
        if (cut_wood(mid) >= M) min = mid + 1;
        else                    max = mid - 1;

        // mid 갱신
        mid = (min + max) / 2;
    }

    // 이진탐색 결과를 출력
    cout << mid << '\n';
    return 0;
}
