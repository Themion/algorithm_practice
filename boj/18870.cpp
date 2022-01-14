#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> p;

#define MAX_N 1000000
#define _crd first
#define _ord second

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N: 배열의 실질적 크기, crd: 좌표를 압축할 때 사용할, 이전 좌표의 압축 전 값
    // cnt: 압축된 좌표 중 자신보다 크기가 작은 서로 다른 좌표의 수
    int N, crd, cnt = 0;
    // 좌표의 값과 입력된 순서를 배열에 저장
    p arr[MAX_N];

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> crd;
        arr[i] = p(crd, i);
    }

    // 좌표를 크기에 따라 정렬
    sort(arr, arr + N, [](p a, p b){ 
        return a._crd == b._crd ? a._ord < b._ord : a._crd < b._crd;
    });

    // 첫 번째 좌표는 크기가 가장 작으므로 압축 후 값은 반드시 0
    crd = arr[0]._crd;
    arr[0]._crd = cnt;

    // 두 번째 좌표부터
    for (int i = 1; i < N; i++) {
        cnt += crd != arr[i]._crd; // 현재 좌표와 이전 좌표를 비교해 압축
        crd = arr[i]._crd;         // 현재 좌표의 압축 전 값을 저장한 뒤
        arr[i]._crd = cnt;         // 계산한 압축값을 arr에 대입
    }

    // 다시 입력된 순서로 배열을 정렬
    sort(arr, arr + N, [](p a, p b) { return a._ord < b._ord; });

    // 압축된 좌표값을 차례로 출력한다
    for (int i = 0; i < N; i++) cout << arr[i]._crd << ' ';
    cout << '\n';

    return 0;
}
