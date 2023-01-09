#include <algorithm>
#include <iostream>

#define MAX_N 1500

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 표의 한 변의 크기
    int N;
    // 표의 셀의 수
    int NN;
    // 표
    int arr[MAX_N * MAX_N];

    // 표를 입력받은 뒤
    cin >> N;
    NN = N * N;
    for (int i = 0; i < NN; i++) cin >> arr[i];

    // 표를 1차원 배열로 생각하여 N번째 성분을 계산 후 출력
    nth_element(arr, arr + NN - N, arr + NN);
    printf("%d\n", arr[NN - N]);

    return 0;
}
